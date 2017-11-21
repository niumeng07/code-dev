#encoding:utf-8

import sys
reload(sys)
sys.setdefaultencoding('utf-8')


import tensorflow as tf
import numpy as np
import os
import time
import datetime
import argparse
import data_utils
import models


os.environ["CUDA_VISIBLE_DEVICES"] = "0"
print "use the GPUs: ", os.environ["CUDA_VISIBLE_DEVICES"]

# 定义超参数
parser = argparse.ArgumentParser()
arg = parser.add_argument
arg('--data-path', default="data", help='path to read data from')
arg('--model-path', default="run", help='path to save model to')
arg('--embedding-size', type=int, default=100, help='size of word embedding')
arg('--filter-sizes', default="3,4,5", help="Comma-separated filter sizes (default: '3,4,5')")
arg('--num-filters', type=int, default=128, help="Number of filters per filter size (default: 128)")
arg('--dropout-keep-prob', type=float, default=0.5)
arg('--dev-sample', type=float, default=0.01)
arg('--l2-reg-lambda', type=float, default=0.025)
arg('--epoch-size', type=int, default=50)
arg('--batch-size', type=int, default=128)
arg('--optimizer', default='adam', help='Optimizer: adam, adadelta')
arg('--max-gradient-norm', type=float, default=5.0)
arg('--learning-rate', type=float, default=0.01)
arg('--checkpoint-step', type=int, default=2, help='do validation and save after each this many of steps.')
args = parser.parse_args()


# 模型训练过程
def train():
    print("Loading data...")
    vocab_word, vocab_word_list, train_words, train_labels, test_words, test_labels \
        = data_utils.prepare_data(args.data_path) #读入数据
    max_text_len = max([len(words) for words in train_words])
    vocab_len = len(vocab_word_list)

    dev_sample_size = int(args.dev_sample * float(len(train_words)))
    x_train, x_dev = train_words[:-1 * dev_sample_size], train_words[-1 * dev_sample_size:] #切分训练集和验证集
    y_train, y_dev = train_labels[:-1 * dev_sample_size], train_labels[-1 * dev_sample_size:]
    print("Vocabulary Size: {:d}".format(len(vocab_word_list)))
    print("Train/Dev split: {:d}/{:d}".format(len(y_train), len(y_dev)))

    #模型构造
    model = models.TextCNN(max_text_len, 2, vocab_len, args.embedding_size,
                           list(map(int, args.filter_sizes.split(","))), args.num_filters,
                           args.max_gradient_norm, args.learning_rate, args.l2_reg_lambda)

    if not os.path.exists(args.model_path):
        os.mkdir(args.model_path)
    #使用数据训练模型
    model.fit(x_train, y_train, x_dev, y_dev, args.epoch_size, args.batch_size,
              args.checkpoint_step, args.model_path)


# 模型测试过程
def test():
    print("Loading data...")
    vocab_word, vocab_word_list, train_words, train_labels, test_words, test_labels \
        = data_utils.prepare_data(args.data_path)
    max_text_len = max([len(words) for words in train_words])
    vocab_len = len(vocab_word_list)
    # 模型构造
    model = models.TextCNN(max_text_len, 2, vocab_len, args.embedding_size,
                           list(map(int, args.filter_sizes.split(","))), args.num_filters,
                           args.max_gradient_norm, args.learning_rate, args.l2_reg_lambda)
    # 给定数据，对模型进行测试
    text = '''说实话没吃成, 但是对这家太不满意了, 所有都给差评!到那之后满屋子都是座, 服务员非得给安排在一个犄角旮旯, 黑咕隆咚的冷气还吹不到.
    点了餐喊半天服务员都不来拿单子, 而且是眼看着服务员从身边经过, 喊着服务员服务员, 她们就只当没听见.
    然后我自己换了个显眼的位置, 举着手喊服务员, 她们还是无视的从我旁边走过.我k, 你又不服务, 没事走来走去干什么?所以后来干脆不吃了.
    请问, 您家是要做生意么?'''
    words_ids = data_utils.sentence_to_token_ids(text, vocab_word)
    predicts = model.predict(words_ids, args.model_path)
    print text
    print "预测结果为:", predicts
    if predicts == [0]:
        print "正面评论"
    else:
        print "负面评论"

    text = '''瘦了点，可能和季节有关吧吃完加点青菜做泡饭满嗲的~孔雀开屏 45.00很大一条鱼，摆盘很漂亮，肉质挺嫩，如果加点醋更好，
    去腥更美味~~香菇菜心这个 我喜欢的呀~上面酱很嗲~ 香菇很入味，菜心很爽口~ 解油腻 总体来说这里感觉很实惠，虽然价格不贵，但是品质却不错，
    摆盘很用心很漂亮。酒香不怕巷子深 用在这里真是非常合适~雨天滴滴答答，不是很舒服，但却并没影响到FB的心情~~~店开在 比较老式的弄堂里，
    周围都是居民区，门面并不大，不过据说这里生意很好。性价比高么做的是绍兴菜，装修比较朴素，菜单也是很简单的A4纸
    塑封一下总体来说这里感觉很实惠，虽然价格不贵，但是品质却不错，摆盘很用心很漂亮。酒香不怕巷子深 用在这里真是非常合适~'''
    words_ids = data_utils.sentence_to_token_ids(text, vocab_word)
    predicts = model.predict(words_ids, args.model_path)
    print text
    print "预测结果为:", predicts
    if predicts == [0]:
        print "正面评论"
    else:
        print "负面评论"


if __name__ == '__main__':
    # train()
    test()

