#encoding:utf-8

import sys
reload(sys)
sys.setdefaultencoding('utf-8')

import tensorflow as tf
import numpy as np
import time, os
import data_utils

class TextCNN(object):
    def __init__(self, seq_len, num_classes, vocab_size, embedding_size,
                 filter_sizes, num_filters,
                 max_gradient_norm=5.0, learning_rate=0.01, l2_reg_lambda=0.025):
        self.seq_len = seq_len
        self.num_classes = num_classes
        self.vocab_size = vocab_size
        self.embedding_size = embedding_size
        self.filter_sizes = filter_sizes
        self.num_filters = num_filters
        self.max_gradient_norm = max_gradient_norm
        self.learning_rate = learning_rate
        self.l2_reg_lambda = l2_reg_lambda
        self.global_step = tf.Variable(0, trainable=False)

        # 输入数据定义，文本格式，类格式
        self.input_x = tf.placeholder(tf.int32, [None, seq_len], name="input_x")
        self.input_y = tf.placeholder(tf.float32, [None, num_classes], name="input_y")
        self.dropout_keep_prob = tf.placeholder(tf.float32, name="dropout_keep_prob")

        l2_loss = tf.constant(0.0)

        with tf.device('/cpu:0'), tf.name_scope("embedding"):
            # 定义词向量
            zero_embeddings = tf.Variable(tf.zeros([1, embedding_size]), trainable=False)
            word_embeddings = tf.Variable(
                tf.random_uniform([vocab_size-1, embedding_size], -1.0, 1.0),
                name="word_embedding")
            self.embeddings = tf.concat([zero_embeddings, word_embeddings], 0, name="embedding")
            # self.embeddings = tf.Variable(
            #     tf.random_uniform([vocab_size-1, embedding_size], -1.0, 1.0),
            #     name="embedding")
            # 获取输入文本各个词的词向量
            self.embed_words = tf.nn.embedding_lookup(self.embeddings, self.input_x)
            self.embed_words_expanded = tf.expand_dims( self.embed_words, -1)

        # 构造len(filter_sizes)种卷积，每种卷积的输出特征个数为num_filters（输出通道）
        pooled_outputs = []
        for i, filter_size in enumerate(filter_sizes):
            with tf.name_scope("conv-maxpool-%s" % filter_size):
                # 卷积形状定义
                filter_shape = [filter_size, embedding_size, 1, num_filters]
                # 卷积参数
                W = tf.Variable(tf.truncated_normal(filter_shape, stddev=0.1), name="W")
                b = tf.Variable(tf.constant(0.1, shape=[num_filters]), name="b")
                # 卷积过程
                conv = tf.nn.conv2d(
                    self.embed_words_expanded,
                    W,
                    strides=[1, 1, 1, 1],
                    padding="VALID",
                    name="conv")
                # 进行非线性变换
                h = tf.nn.relu(tf.nn.bias_add(conv, b), name="relu")
                # 池化操作
                pooled = tf.nn.max_pool(
                    h,
                    ksize=[1, seq_len - filter_size + 1, 1, 1],
                    strides=[1, 1, 1, 1],
                    padding='VALID',
                    name="pool")
                pooled_outputs.append(pooled)

        # 合并所有的特征
        num_filters_total = num_filters * len(filter_sizes)
        self.h_pool = tf.concat(pooled_outputs, 3)
        self.h_pool_flat = tf.reshape(self.h_pool, [-1, num_filters_total])

        # 加入dropout
        with tf.name_scope("dropout"):
            self.h_drop = tf.nn.dropout(self.h_pool_flat, self.dropout_keep_prob)

        # 对CNN得到的特征进行类别预测
        with tf.name_scope("output"):
            W = tf.get_variable(
                "W",
                shape=[num_filters_total, num_classes],
                initializer=tf.contrib.layers.xavier_initializer())
            b = tf.Variable(tf.constant(0.1, shape=[num_classes]), name="b")
            l2_loss += tf.nn.l2_loss(W)
            l2_loss += tf.nn.l2_loss(b)
            self.scores = tf.nn.xw_plus_b(self.h_drop, W, b, name="scores") # 预测得分，注意：不是概率
            self.predictions = tf.argmax(self.scores, 1, name="predictions") # 预测结果

        # 定义Mean cross-entropy损失函数
        with tf.name_scope("loss"):
            losses = tf.nn.softmax_cross_entropy_with_logits(logits=self.scores,
                                                             labels=self.input_y)
            self.loss = tf.reduce_sum(losses) + l2_reg_lambda * l2_loss
        # 更新参数
        with tf.name_scope("update"):
            params = tf.trainable_variables()
            gradients = tf.gradients(self.loss, params)
            clipped_gradients, norm = tf.clip_by_global_norm(gradients, self.max_gradient_norm) # 过滤倒数太大或太小的情况

            opt = tf.train.AdadeltaOptimizer(learning_rate=self.learning_rate)
            self.update = opt.apply_gradients(zip(clipped_gradients, params), global_step=self.global_step)

        # 判断模型效果
        with tf.name_scope("accuracy"):
            correct_predictions = tf.equal(self.predictions, tf.argmax(self.input_y, 1))
            self.accuracy = tf.reduce_mean(tf.cast(correct_predictions, "float"), name="accuracy")

        self.saver = tf.train.Saver(tf.global_variables(), max_to_keep=2)

    # 初始化模型，从头开始初始化或者使用之前训练模型进行初始化
    def initilize(self, model_dir, session=None):
        ckpt = tf.train.get_checkpoint_state(model_dir)
        if ckpt and tf.gfile.Exists(ckpt.model_checkpoint_path):
            print("Reading model parameters from %s" % ckpt.model_checkpoint_path)
            self.saver.restore(session, ckpt.model_checkpoint_path)
        else:
            print("Creating model with fresh parameters.")
            session.run(tf.global_variables_initializer())

    # 预测过程
    def predict(self, words, model_dir):
        config = tf.ConfigProto(allow_soft_placement=True)
        with tf.Session(config=config) as session:
            self.initilize(model_dir, session)
            in_inputs = np.zeros((1, self.seq_len), dtype=int)
            in_inputs[0] = words + [data_utils.PAD_ID] * (self.seq_len - len(words)) #长度不够的需要补固定的符号

            feeds = dict()
            feeds[self.input_x] = in_inputs
            feeds[self.dropout_keep_prob] = 1.0
            outputs = session.run([self.predictions], feeds)
            outputs = outputs[0]
            # print outputs
            return outputs

    def step(self, _inputs, _labels, session=None, is_train=True):
        feeds = dict()
        if is_train:
            feeds[self.input_x] = _inputs
            feeds[self.input_y] = _labels
            feeds[self.dropout_keep_prob] = 0.5 # 训练的时候使用dropout
            outputs, loss, _ = session.run([self.predictions, self.loss, self.update], feeds)
        else:
            feeds[self.input_x] = _inputs
            feeds[self.input_y] = _labels
            feeds[self.dropout_keep_prob] = 1.0 # 测试的时候不要dropout
            outputs, loss = session.run([self.predictions, self.loss], feeds)
        return outputs, loss

    def fit(self, train_words, train_labels, valid_words, valid_labels,
            epoch_size, batch_size, step_per_checkpoint, model_dir):
        config = tf.ConfigProto(allow_soft_placement=True)
        with tf.Session(config=config) as session:
            self.initilize(model_dir, session) # 初始化参数
            for epoch in xrange(1, epoch_size + 1): # 迭代执行模型
                start = time.time()
                loss_sum = 0.0
                for words, labels in data_utils.get_batchs(train_words, train_labels, self.seq_len, batch_size):
                    # 获得一个batch的数据，并执行
                    _, step_loss = self.step(words, labels, session)
                    loss_sum += step_loss
                    print "step loss %.2f" % step_loss
                finish = time.time()
                print "epoch %d loss %.5f time %.2f" % (epoch, loss_sum, finish - start)

                if epoch % step_per_checkpoint == 0:
                    # 验证过程
                    for words, labels in data_utils.get_batchs(valid_words, valid_labels, self.seq_len, 2, sample=True):
                        predicts, step_loss = self.step(words, labels, session, False)
                        print "real"
                        print labels
                        print "predicts"
                        print predicts
                        print "validation-loss %.5f" % step_loss
                    # 保存模型结果，供测试或增量训练使用
                    self.saver.save(session, os.path.join(model_dir, 'checkpoint'), global_step=self.global_step)


