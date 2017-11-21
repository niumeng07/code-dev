# encoding:utf-8

import sys
reload(sys)
sys.setdefaultencoding('utf-8')

import time
import os
import numpy as np
import tensorflow as tf
from tensorflow.contrib import rnn, legacy_seq2seq
from tensorflow.python.framework import dtypes


class PCNNModel(object):
    def __init__(self, vocab_size, embedding_size, max_sent_len, class_num,
                 word_embeddings=None, filter_sizes=(2, 3, 4), num_filters=50,
                 is_train=True, optimizer_name='Adam', learning_rate=0.05):
        self.vocab_size = vocab_size
        self.embedding_size = embedding_size
        self.max_sent_len = max_sent_len
        self.class_num = class_num
        self.pre_word_embeddings = word_embeddings
        self.filter_sizes = filter_sizes
        self.num_filters = num_filters

        self.optimizer_name = optimizer_name
        self.learning_rate = learning_rate
        self.is_train = is_train
        self.global_step = tf.Variable(0, trainable=False)

        self._define_embedding()
        self._define_graph()

    def _define_embedding(self):
        with tf.device("/cpu:0"):
            if self.pre_word_embeddings is not None:
                self.pre_word_embeddings = np.array(self.pre_word_embeddings)
                print "use pre word embeddings: ", self.pre_word_embeddings.shape
                word_embeddings = tf.Variable(self.pre_word_embeddings, #trainable=False,
                                              dtype=tf.float32, name="word_embeddings")
            else:
                print "init with empty word embeddings"
                word_embeddings = tf.get_variable("word_embeddings", [self.vocab_size, self.embedding_size])
            word_embeddings = tf.nn.l2_normalize(word_embeddings, 1)
            self.embeddings = word_embeddings

    def _define_graph(self):
        self.sent_words = tf.placeholder(tf.int64, [self.max_sent_len, None], 'words_inputs')
        self.sent_lengths = tf.placeholder(tf.int64, [None], 'sent_lengths')
        self.sent_pinds = tf.placeholder(tf.float32, [3, self.max_sent_len, None], 'parts_indexs')
        self.sent_labels = tf.placeholder(tf.int64, [None], 'class_labels')
        self.dropout_keep_prob = tf.placeholder(tf.float32, name="dropout_keep_prob")

        self.base_loss = 0.0
        self.norm_loss = 0.0
        with tf.device("/cpu:0"):
            embed_words = tf.nn.embedding_lookup(self.embeddings, tf.transpose(self.sent_words))
            embed_words_expanded = tf.expand_dims(embed_words, -1) # [batch, max_num, emb, 1]

        pooled_outputs = []
        for i, filter_size in enumerate(self.filter_sizes):
            with tf.name_scope("conv-maxpool-%s" % filter_size):
                filter_shape = [filter_size, self.embedding_size, 1, self.num_filters]
                cnn_w = tf.Variable(tf.truncated_normal(filter_shape, stddev=0.1), name="W")
                cnn_b = tf.Variable(tf.constant(0.1, shape=[self.num_filters]), name="b")
                conv = tf.nn.conv2d(embed_words_expanded, cnn_w,
                                    strides=[1, 1, self.embedding_size, 1], padding="SAME", name="conv")
                hidden = tf.nn.relu(tf.nn.bias_add(conv, cnn_b), name="relu") # [batch, seq, 40, fil_size]
                hidden = tf.transpose(hidden, [2, 3, 1, 0])
                head_inds, mid_inds, tail_inds = tf.unstack(self.sent_pinds) # 3个[seq, batch]

                hidden1 = hidden * head_inds # [1, fil_size, seq, batch]
                hidden2 = hidden * mid_inds
                hidden3 = hidden * tail_inds

                hidden1 = tf.transpose(hidden1, [3, 2, 0, 1])
                hidden2 = tf.transpose(hidden2, [3, 2, 0, 1])
                hidden3 = tf.transpose(hidden3, [3, 2, 0, 1])

                pooled1 = tf.nn.max_pool(hidden1, ksize=[1, self.max_sent_len, 1, 1],
                                         strides=[1, self.max_sent_len, 1, 1],
                                         padding='SAME', name="pool_1")
                pooled2 = tf.nn.max_pool(hidden2, ksize=[1, self.max_sent_len, 1, 1],
                                         strides=[1, self.max_sent_len, 1, 1],
                                         padding='SAME', name="pool_2")
                pooled3 = tf.nn.max_pool(hidden3, ksize=[1, self.max_sent_len, 1, 1],
                                         strides=[1, self.max_sent_len, 1, 1],
                                         padding='SAME', name="pool_3")
                pooled_outputs.append(pooled1)
                pooled_outputs.append(pooled2)
                pooled_outputs.append(pooled3)

                self.norm_loss += tf.nn.l2_loss(cnn_w)
                self.norm_loss += tf.nn.l2_loss(cnn_b)

        num_filters_total = len(self.filter_sizes) * self.num_filters * 3
        h_pool = tf.concat(pooled_outputs, 3)
        h_pool_flat = tf.reshape(h_pool, [-1, num_filters_total])

        with tf.name_scope("dropout"):
            h_drop = tf.nn.dropout(h_pool_flat, self.dropout_keep_prob)

        W = tf.get_variable("proj_w", [num_filters_total, self.class_num], dtype=dtypes.float32)
        B = tf.get_variable("proj_b", [self.class_num], dtype=dtypes.float32)
        self.norm_loss += tf.nn.l2_loss(W)
        self.norm_loss += tf.nn.l2_loss(B)

        self.scores = tf.nn.xw_plus_b(h_drop, W, B, name="scores")
        self.predictions = tf.argmax(self.scores, 1, name="predictions")

        gold_labels = tf.one_hot(self.sent_labels, self.class_num)
        self.cost = tf.nn.softmax_cross_entropy_with_logits(logits=self.scores,
                                                            labels=gold_labels)

        self.loss = tf.reduce_mean(self.cost) + 0.01 * self.norm_loss

        with tf.name_scope("accuracy"):
            correct_predictions = tf.equal(self.predictions, self.sent_labels)
            self.accuracy = tf.reduce_mean(tf.cast(correct_predictions, "float"), name="accuracy")

        if self.optimizer_name.lower() == 'adam':
            optimizer = tf.train.AdamOptimizer(learning_rate=self.learning_rate)
        elif self.optimizer_name.lower() == 'adadelta':
            optimizer = tf.train.AdamOptimizer(learning_rate=self.learning_rate)
        elif self.optimizer_name.lower() == 'adagrad':
            optimizer = tf.train.AdagradOptimizer(learning_rate=self.learning_rate)
        else:
            optimizer = tf.train.GradientDescentOptimizer(learning_rate=self.learning_rate)

        self.update = optimizer.minimize(self.loss)

        with tf.device("/cpu:0"):
            self.saver = tf.train.Saver(tf.global_variables(), max_to_keep=10)

    def initilize(self, model_dir, session=None):
        ckpt = tf.train.latest_checkpoint(model_dir)
        if ckpt:
            self.saver.restore(session, ckpt)
            print "Reading model parameters from %s" % ckpt
        else:
            print("Creating model with fresh parameters.")
            session.run(tf.global_variables_initializer())

    def step(self, words, lengths, pinds, labels, is_train, session=None):
        feed = dict()
        feed[self.sent_words] = words
        feed[self.sent_lengths] = lengths
        feed[self.sent_pinds] = pinds
        feed[self.sent_labels] = labels

        if is_train:
            feed[self.dropout_keep_prob] = 0.5
            loss, _ = session.run([self.loss, self.update], feed)
            return None, loss
        else:
            feed[self.dropout_keep_prob] = 1.0
            # predictions, loss = session.run([self.predictions, self.loss], feed)
            accuracy, loss = session.run([self.accuracy, self.loss], feed)
            return accuracy, loss

    def fit(self, dataloader, batch_size, epoch_size, step_per_checkpoint, model_dir):
        config = tf.ConfigProto(allow_soft_placement=True)
        config.gpu_options.allow_growth = True
        with tf.Session(config=config) as session:
            self.initilize(model_dir, session)
            print "epoch size is : ", epoch_size
            print "batch size is : ", batch_size
            for epoch in xrange(1, epoch_size + 1):
                epoch_start = time.time()
                loss_sum = 0
                run_id, loss_run = 0, 0
                start = time.time()
                for word, lengths, pinds, labels in dataloader.iter_batchs(batch_size):
                    _, step_loss = self.step(word, lengths, pinds, labels, True, session)
                    loss_sum += step_loss
                    loss_run += step_loss
                    run_id += 1
                    if run_id % 100 == 0:
                        print "run %d loss %.5f time %.2f" % (run_id, loss_run, time.time() - start)
                        start = time.time()
                        loss_run = 0
                if epoch % step_per_checkpoint == 0:
                    self.saver.save(session, os.path.join(model_dir, 'checkpoint'), global_step=self.global_step)
                epoch_finish = time.time()
                print "epoch %d loss %.5f time %.2f" % (epoch, loss_sum, epoch_finish - epoch_start)

    def test(self, dataloader, model_dir):
        config = tf.ConfigProto(allow_soft_placement=True)
        config.gpu_options.allow_growth = True
        with tf.Session(config=config) as session:
            self.initilize(model_dir, session)
            accus = list()
            for word, lengths, pinds, labels in dataloader.iter_batchs(data=dataloader.test_data):
                accuracy, step_loss = self.step(word, lengths, pinds, labels, False, session)
                accus.append(accuracy)
            print "accuracy: ", sum(accus) / len(accus)



