# encoding:utf-8

import sys
reload(sys)
sys.setdefaultencoding('utf8')

import os
import cPickle
import random, re
import nltk
import codecs
import numpy as np
from collections import Counter
from utils import *

PAD, UNK = ('_PAD', '_UNK')
PAD_ID, UNK_ID = range(2)


def tokenizer(sent):
    sent = re.sub(r"<e1>.*?</e1>", "e1e1e1e1", sent)
    sent = re.sub(r"<e2>.*?</e2>", "e2e2e2e2", sent)
    words = [w.strip() for w in nltk.word_tokenize(sent)]
    words = [w.lower() for w in words if len(w) > 0]
    start_ind, end_ind = 0, 0
    new_words = list()
    for ind, word in enumerate(words):
        if word == 'e1e1e1e1':
            start_ind = ind
            new_words.append('_<e1>')
        elif word == 'e2e2e2e2':
            end_ind = ind
            new_words.append('_<e2>')
        else:
            new_words.append(word)
    return new_words, start_ind, end_ind


class DataLoader(object):
    def __init__(self, data_path):
        print "deal with : ", data_path
        self.data_path = data_path
        self.max_sent_len = 40
        self.create_vocbulary()
        self.load_data()

    def load_data(self):
        def filter_data(data):
            new_data = list()
            for word_ids, start, end, label in data:
                if len(word_ids) > self.max_sent_len:
                    continue
                new_data.append((word_ids, start, end, label))
            return new_data
        datas = list()
        for name in ['train', 'dev', 'test']:
            db_file = os.path.join(self.data_path, '%s.txt' % name)
            print "load data from ", db_file
            data_insts = list()
            with codecs.open(db_file, 'rb', 'utf-8') as f:
                lines = [l.strip() for l in f if len(l.strip()) > 0]
                for ind in range(0, len(lines) / 2):
                    sent, label = lines[2 * ind:2 * ind + 2]
                    if label not in self.labels:
                        continue
                    sent = sent.split('\t')[1].strip()[1:-1].strip()
                    words, start, end = tokenizer(sent)
                    word_ids = [self.vocab.get(w, UNK_ID) for w in words]
                    label_id = self.labels[label]
                    data_insts.append((word_ids, start, end, label_id))
            print "origial entire line : ", len(data_insts)
            datas.append(data_insts)
        train_data, valid_data, test_data = datas
        self.train_data = filter_data(train_data)
        print "filter train entire : ", len(self.train_data)
        self.valid_data = filter_data(valid_data)
        print "filter valid entire : ", len(self.valid_data)
        self.test_data = filter_data(test_data)
        print "filter test entire : ", len(self.test_data)

    def create_vocbulary(self, min_frq=0, max_vocab_size=30*1000):
        #先获取词表
        word_counts = Counter()
        label_set = set()
        with codecs.open(os.path.join(self.data_path, 'train.txt'), 'rb', 'utf-8') as f:
            lines = [l.strip() for l in f if len(l.strip()) > 0]
            for ind in range(0, len(lines) / 2):
                sent, label = lines[2*ind:2*ind+2]
                label_set.add(label)
                sent = sent.split('\t')[1].strip()[1:-1].strip()
                words, _, _ = tokenizer(sent)
                word_counts.update(words)
        word_frqs = filter_vocab(word_counts, min_frq, max_vocab_size)

        word_vocab = dict([(x, y) for (y, x) in enumerate(word_frqs.keys())])
        self.vocab_list = [PAD, UNK] + list(word_vocab.keys())
        self.vocab_size = len(self.vocab_list)
        self.vocab = dict([(x, y) for (y, x) in enumerate(self.vocab_list)])
        print "vocab size: ", self.vocab_size

        self.label_list = list(label_set)
        self.label_size = len(self.label_list)
        self.labels = dict([(x, y) for (y, x) in enumerate(self.label_list)])
        print "label size: ", self.label_size

    def iter_batchs(self, batch_size=120, shuffle=True, data=None):
        if data is None:
            data = self.train_data
        if shuffle:
            random.shuffle(data)
        batch_num = len(data) // batch_size
        for kk in xrange(batch_num + 1):
            begin, end = batch_size * kk, batch_size * (kk + 1)
            if begin >= end:
                continue
            if end > len(self.train_data):
                end = len(self.train_data)
            batch_data = self.train_data[begin:end]
            inst_size = len(batch_data)
            input_words = np.zeros((inst_size, self.max_sent_len), dtype=int)
            input_lengths = np.zeros(inst_size)
            input_pinds = np.zeros((inst_size, 3, self.max_sent_len))
            input_labels = np.zeros(inst_size)

            for ind in xrange(0, inst_size):
                ids, start, end, label = batch_data[ind]
                input_words[ind] = np.array(ids + [PAD_ID] * (self.max_sent_len - len(ids)))
                input_lengths[ind] = len(ids)
                input_labels[ind] = label
                input_pinds[ind, 0, :start] = 1.0
                input_pinds[ind, 1, start:end] = 1.0
                input_pinds[ind, 2, end:] = 1.0
            yield np.transpose(input_words), input_lengths, \
                  np.transpose(input_pinds, [1, 2, 0]), input_labels

    def get_batch(self, batch_size=120, data=None):
        if data is None:
            data = self.train_data
        batch_data = random.sample(data, batch_size)
        inst_size = len(batch_data)
        input_words = np.zeros((inst_size, self.max_sent_len), dtype=int)
        input_lengths = np.zeros(inst_size)
        input_pinds = np.zeros((inst_size, 3, self.max_sent_len))
        input_labels = np.zeros(inst_size)

        for ind in xrange(0, inst_size):
            ids, start, end, label = batch_data[ind]
            input_words[ind] = np.array(ids + [PAD_ID] * (self.max_sent_len - len(ids)))
            input_lengths[ind] = len(ids)
            input_labels[ind] = label
            input_pinds[ind, 0, :start] = 1.0
            input_pinds[ind, 1, start:end] = 1.0
            input_pinds[ind, 2, end:] = 1.0

        return np.transpose(input_words), input_lengths, \
               np.transpose(input_pinds, [1, 2, 0]), input_labels

if __name__ == '__main__':
    data_path = 'data/kbp37'

    dump_path = os.path.join(data_path, "rc_pcnn_temp_data.pkl")
    if not os.path.exists(dump_path):
        dataloader = DataLoader(data_path)
        cPickle.dump(dataloader, open(dump_path, "wb"))
    else:
        dataloader = cPickle.load(open(dump_path, "rb"))

    words, lens, pids, labels = dataloader.get_batch(2)
    print words
    print '\n'.join(ids_to_sentence(words.tolist(), dataloader.vocab_list))
    print lens
    print pids
    print labels













