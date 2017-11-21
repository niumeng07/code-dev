
# coding: utf-8

# In[1]:


'''
A Multilayer Perceptron implementation example using TensorFlow library.
This example is using the MNIST database of handwritten digits
(http://yann.lecun.com/exdb/mnist/)

Author: Aymeric Damien
Project: https://github.com/aymericdamien/TensorFlow-Examples/
'''


# In[3]:



# 跟前面项目一样，导入数据
from tensorflow.examples.tutorials.mnist import input_data
#mnist = input_data.read_data_sets("/tmp/data/", one_hot=True)
mnist = input_data.read_data_sets("/Users/liuda/Template/mnist/", one_hot=True)

import tensorflow as tf


# In[4]:


# 定义超参数
learning_rate = 0.001
training_epochs = 15
batch_size = 100
display_step = 1

# 神经网络的参数
n_hidden_1 = 256 # 第一隐层特征
n_hidden_2 = 256 # 第二隐层特征
n_input = 784 # 输入层特征个数，即MNIST每个对象的唯独(img shape: 28*28)
n_classes = 10 # MNIST总类别数

# 输入，即Graph的输入
x = tf.placeholder("float", [None, n_input])
y = tf.placeholder("float", [None, n_classes])


# In[5]:


# 创建模型
def multilayer_perceptron(x, weights, biases):
    # 第一层，使用RELU作为激活函数
    layer_1 = tf.add(tf.matmul(x, weights['h1']), biases['b1'])
    layer_1 = tf.nn.relu(layer_1)
    # 第二层，也用RELU作为激活函数
    layer_2 = tf.add(tf.matmul(layer_1, weights['h2']), biases['b2'])
    layer_2 = tf.nn.relu(layer_2)
    # 输出映射
    out_layer = tf.matmul(layer_2, weights['out']) + biases['out']
    return out_layer


# In[13]:


# 模型参数定义
weights = {
    'h1': tf.Variable(tf.random_normal([n_input, n_hidden_1])),
    'h2': tf.Variable(tf.random_normal([n_hidden_1, n_hidden_2])),
    'out': tf.Variable(tf.random_normal([n_hidden_2, n_classes]))
}
biases = {
    'b1': tf.Variable(tf.random_normal([n_hidden_1])),
    'b2': tf.Variable(tf.random_normal([n_hidden_2])),
    'out': tf.Variable(tf.random_normal([n_classes]))
}

# 构建模型
pred = multilayer_perceptron(x, weights, biases)

# 定义损失函数以及优化函数
cost = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(logits=pred, labels=y))
optimizer = tf.train.AdamOptimizer(learning_rate=learning_rate).minimize(cost)


# In[ ]:


init = tf.initialize_all_variables()
with tf.Session() as sess:
    sess.run(init)

    #训练循环
    for epoch in range(training_epochs):
        avg_cost = 0.
        total_batch = int(mnist.train.num_examples/batch_size)
        
        for i in range(total_batch):
            batch_x, batch_y = mnist.train.next_batch(batch_size) #获得一个batch            
            _, c = sess.run([optimizer, cost], feed_dict={x: batch_x,
                                                          y: batch_y})
            avg_cost += c / total_batch        
        if epoch % display_step == 0:
            print '第%04d轮:' % (epoch+1), "cost=", "{:.9f}".format(avg_cost)
    print "优化结束"

    # 模型测试
    correct_prediction = tf.equal(tf.argmax(pred, 1), tf.argmax(y, 1))
    # 计算准确率
    accuracy = tf.reduce_mean(tf.cast(correct_prediction, "float"))
    print "准确率:", accuracy.eval({x: mnist.test.images, y: mnist.test.labels})

