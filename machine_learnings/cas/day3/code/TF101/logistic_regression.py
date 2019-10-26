#encoding:utf-8

import tensorflow as tf
import numpy as np
import input_data
import os

os.environ["CUDA_VISIBLE_DEVICES"] = "0"

def init_weights(shape):
    return tf.Variable(tf.random_normal(shape, stddev=0.01), name="weight_w")

def model(X, w):
    return tf.matmul(X, w)


mnist = input_data.read_data_sets("../MNIST_data/", one_hot=True)
trX, trY, teX, teY = mnist.train.images, mnist.train.labels, mnist.test.images, mnist.test.labels


log_dir = "mnist_logs"

def variable_summaries(var):
  with tf.name_scope('summaries'):
    mean = tf.reduce_mean(var)
    tf.summary.scalar('mean', mean)
    with tf.name_scope('stddev'):
      stddev = tf.sqrt(tf.reduce_mean(tf.square(var - mean)))
    tf.summary.scalar('stddev', stddev)
    tf.summary.scalar('max', tf.reduce_max(var))
    tf.summary.scalar('min', tf.reduce_min(var))
    tf.summary.histogram('histogram', var)

graph = tf.Graph()
with graph.as_default():

    input_X = tf.placeholder("float", [None, 784], name="input_X")
    input_Y = tf.placeholder("float", [None, 10], name="input_Y")

    global_step = tf.Variable(0, trainable=False)

    with tf.name_scope('input_reshape'):
        image_shaped_input = tf.reshape(input_X, [-1, 28, 28, 1])
        tf.summary.image('input', image_shaped_input, 10)

    w = init_weights([784, 10])
    variable_summaries(w)
    py_x = model(input_X, w)
    tf.summary.tensor_summary("predict", py_x)

    cost = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(logits=py_x, labels=input_Y))
    tf.summary.scalar("cost", cost)

    optimizer = tf.train.GradientDescentOptimizer(0.05).minimize(cost, global_step=global_step)
    predict_op = tf.argmax(py_x, 1)

    merged = tf.summary.merge_all()
    with tf.device("/cpu:0"):
        saver = tf.train.Saver(tf.global_variables(), max_to_keep=2)


with tf.Session(graph=graph) as sess:
    train_writer = tf.summary.FileWriter(log_dir + '/train', sess.graph)
    tf.global_variables_initializer().run()

    for i in range(100):
        for start, end in zip(range(0, len(trX), 128), range(128, len(trX)+1, 128)):
            summary, _, step_id = sess.run([merged, optimizer, global_step],
                                           feed_dict={input_X: trX[start:end],
                                                      input_Y: trY[start:end]})
            train_writer.add_summary(summary, step_id)

        predict_results = sess.run(predict_op, feed_dict={input_X: teX})
        accuracy = np.mean(np.argmax(teY, axis=1) == predict_results)
        print "第", i+1, "轮学习, 准确率为: ", accuracy
    saver.save(sess, 'run/checkpoint', global_step=global_step)