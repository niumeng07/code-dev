#!/usr/bin/env python
#-*-coding:utf-8-*-

import sys
reload(sys)
sys.setdefaultencoding('utf-8')

import os
import numpy as np
import re
import jieba, nltk
from collections import Counter
from tensorflow.python.platform import gfile

PAD, UNK = ('_PAD', '_UNK')
PAD_ID, UNK_ID = range(2)

#把原始数据划分为训练集和测试集，此处取最后文件做测试集
def split_train_test(input_data, save_dir_name):
    pos_lines, neg_lines = list(), list()
    reader = gfile.GFile(input_data, mode="rb")
    for line in reader:
        label, sent = line.split('\t', 2)
        score = int(label.strip())
        if score > 30: # 标签得分大于30的认为是正例
            pos_lines.append(sent.strip())
        elif score < 30:
            neg_lines.append(sent.strip())
    reader.close()

    def save(lines, name):
        with gfile.GFile(os.path.join(save_dir_name, name), mode="wb") as writer:
            writer.write('\n'.join(lines))

    save(pos_lines[:-100], "train_pos")
    save(pos_lines[-100:], "test_pos")
    save(neg_lines[:-100], "train_neg")
    save(neg_lines[-100:], "test_neg")

    print "train pos num: ", len(pos_lines)
    print "train neg num: ", len(neg_lines)

# 对中文进行分词
def tokenizer(sentence, lang='zh'):
    if lang == 'zh':
        return [w.strip() for w in jieba.cut(sentence)]
    return [w.strip() for w in nltk.word_tokenize(sentence.strip())]

# 读取数据，创建词汇表，即提取词频前多少的词放入词汇表中，词汇表未覆盖的词表示特殊词'UNK'
def create_vocabulary(vocab_path, data_path, max_vocab_size=40*1000):
    vocab_counts = Counter()
    for name in ['train_pos', 'train_neg']:
        with gfile.GFile(os.path.join(data_path, name), mode="rb") as reader:
            for line in reader:
                words = [w.strip() for w in tokenizer(line) if len(w.strip()) > 0]
                vocab_counts.update(words)
    print "vocab num: %d/%d" % (len(vocab_counts), sum(vocab_counts.values()))
    sel_vocabs = vocab_counts.most_common(max_vocab_size) # 提取最高频的max_vocab_size个词
    print "sel vocab num: %d/%d" % (len(sel_vocabs), sum([x[1] for x in sel_vocabs]))
    vocab_list = [PAD, UNK] + [w[0] for w in sel_vocabs]
    vocab = dict([(x, y) for (y, x) in enumerate(vocab_list)])
    with gfile.GFile(os.path.join(vocab_path, "word_vocab"), mode="wb") as writer:
        for w in vocab_list:
            writer.write(w + b"\n")


def initialize_vocabulary(vocab_path):
    vocab_list = list()
    with gfile.GFile(os.path.join(vocab_path, "word_vocab"), mode="rb") as f:
        for word in f:
            vocab_list.append(str(word.strip()))
    vocab = dict([(x, y) for (y, x) in enumerate(vocab_list)])
    return vocab, vocab_list

# 把一个句子分词，然后根据词汇表各个词对应的位置（ID），转换词序列为ID序列
def sentence_to_token_ids(line, vocab):
    words = [str(w.strip()) for w in tokenizer(line) if len(w.strip()) > 0]
    word_ids = [vocab.get(w, UNK_ID) for w in words]
    return word_ids


#  数据准备函数
def prepare_data(data_path, is_id=True):
    vocab, vocab_list = initialize_vocabulary(data_path) #初始化词汇表

    # 直接使用id表示的句子
    if is_id:
        train_word_ids = list()
        train_label_ids = list()
        for name, label in [('train_pos_ids', 1), ('train_neg_ids', 0)]:
            data_file = gfile.GFile(os.path.join(data_path, name), mode="rb")
            for line in data_file:
                word_ids = [int(w.strip()) for w in line.split()]
                train_word_ids.append(word_ids)
                train_label_ids.append(label)
            data_file.close()

        test_word_ids = list()
        test_label_ids = list()
        for name, label in [('test_pos_ids', 1), ('test_neg_ids', 0)]:
            data_file = gfile.GFile(os.path.join(data_path, name), mode="rb")
            for line in data_file:
                word_ids = [int(w.strip()) for w in line.split()]
                test_word_ids.append(word_ids)
                test_label_ids.append(label)
            data_file.close()
    # 从原始文本数据得到学习语料
    else:
        train_word_ids = list()
        train_label_ids = list()
        train_max_num = 0
        for name, label in [('train_pos', 1), ('train_neg', 0)]:
            data_file = gfile.GFile(os.path.join(data_path, name), mode="rb")
            data_id_file = gfile.GFile(os.path.join(data_path, "%s_ids" % name), mode="wb")
            for line in data_file:
                word_ids = sentence_to_token_ids(line, vocab)
                if len(word_ids) > train_max_num:
                    train_max_num = len(word_ids)
                train_word_ids.append(word_ids)
                train_label_ids.append(label)
                data_id_file.write(' '.join([str(id) for id in word_ids]) + '\n')
            data_file.close()
            data_id_file.close()
        print "train max token: ", train_max_num

        test_word_ids = list()
        test_label_ids = list()
        test_max_num = 0
        for name, label in [('test_pos', 1), ('test_neg', 0)]:
            data_file = gfile.GFile(os.path.join(data_path, name), mode="rb")
            data_id_file = gfile.GFile(os.path.join(data_path, "%s_ids" % name), mode="wb")
            for line in data_file:
                word_ids = sentence_to_token_ids(line, vocab)
                if len(word_ids) > test_max_num:
                    test_max_num = len(word_ids)
                test_word_ids.append(word_ids)
                test_label_ids.append(label)
                data_id_file.write(' '.join([str(id) for id in word_ids]) + '\n')
            data_file.close()
            data_id_file.close()
        print "test max token: ", test_max_num

    return vocab, vocab_list, train_word_ids, train_label_ids, test_word_ids, test_label_ids

# 迭代获得batch数据
def get_batchs(words, labels, max_seq_len, batch_size, shuffle=True, sample=False):
    words = np.asarray(words)
    labels = np.asarray(labels)
    assert len(words) == len(labels)
    data_size = len(words)

    indexs = list(xrange(data_size))
    if shuffle:
        np.random.shuffle(indexs) # 对数据进行随机打散
    indexs = np.asarray(indexs)

    if sample: # 只抽取一个batch的数据
        batchs = np.random.choice(indexs, batch_size)
        in_inputs = np.zeros((batch_size, max_seq_len), dtype=int)
        in_labels = np.zeros((batch_size, 2), dtype=int)
        for ind in xrange(batch_size):
            ids, label = words[batchs[ind]], labels[batchs[ind]]
            in_inputs[ind] = ids + [PAD_ID] * (max_seq_len - len(ids)) # 词个数长度不够，则补固定值
            if label == 1:
                in_labels[ind] = [0, 1]
            else:
                in_labels[ind] = [1, 0]
        yield in_inputs, in_labels
    else: # 变量数据集，迭代获得多个batch的数据
        for epoch in xrange(data_size // batch_size):
            begin, end = epoch * batch_size, (epoch + 1) * batch_size
            in_inputs = np.zeros((batch_size, max_seq_len), dtype=int)
            in_labels = np.zeros((batch_size, 2), dtype=int)

            for i, ind in enumerate(xrange(begin, end)):
                ids, label = words[indexs[ind]], labels[indexs[ind]]
                in_inputs[i] = ids + [PAD_ID] * (max_seq_len - len(ids))
                if label == 1:
                    in_labels[i] = [0, 1]
                else:
                    in_labels[i] = [1, 0]
            yield in_inputs, in_labels


if __name__ == '__main__':

    # input_data = 'data/combine.txt'
    # data_dir_name = 'data'
    # split_train_test(input_data, data_dir_name)

    base_dir = 'data'
    vocab_path = "data"
    create_vocabulary(vocab_path, base_dir)

    base_dir = 'data'
    vocab_word, vocab_word_list, \
    train_words, train_labels, test_words, test_labels = prepare_data(base_dir, False)

    max_seq_len = max([len(words) for words in train_words + test_words])

    for words, labels in get_batchs(train_words, train_labels, max_seq_len, 5):
        print words
        print labels
        break
    pass