# encoding:utf-8

import sys
reload(sys)
sys.setdefaultencoding('utf-8')

import argparse
import os, cPickle
import data_utils
import models
from utils import *

os.environ["CUDA_VISIBLE_DEVICES"] = "0"

parser = argparse.ArgumentParser()
arg = parser.add_argument
arg('--data-path', default="data/kbp37")
arg('--model-path', default="run/pcnn_v100")
arg('--embedding-size', type=int, default=100)
arg('--filter-sizes', default="2,3,4")
arg('--num-filters', type=int, default=64)
arg('--dropout-keep-prob', type=float, default=0.5)
arg('--optimizer', default='adam', help='Optimizer: adam, adadelta')
arg('--learning-rate', type=float, default=0.01)
arg('--batch-size', type=int, default=128)
arg('--epoch-size', type=int, default=10)
arg('--checkpoint-step', type=int, default=1, help='do validation and save after each this many of steps.')
args = parser.parse_args()
filter_sizes = list(map(int, args.filter_sizes.split(",")))

def main():
    if not os.path.exists(args.model_path):
        os.mkdir(args.model_path)
    print "save mode to : ", args.model_path

    dump_path = os.path.join(args.data_path, "rc_pcnn_data.pkl")
    if not os.path.exists(dump_path):
        dataloader = data_utils.DataLoader(args.data_path)
        cPickle.dump(dataloader, open(dump_path, "wb"))
    else:
        dataloader = cPickle.load(open(dump_path, "rb"))

    print "train instance: ", len(dataloader.train_data)
    print "vocab size: ", dataloader.vocab_size

    model = models.PCNNModel(dataloader.vocab_size, args.embedding_size,
                             dataloader.max_sent_len, dataloader.label_size,
                             None, filter_sizes, args.num_filters, True,
                             args.optimizer, args.learning_rate)

    print "begining to train model"
    model.fit(dataloader, args.batch_size, args.epoch_size, args.checkpoint_step, args.model_path)


def test():
    if not os.path.exists(args.model_path):
        os.mkdir(args.model_path)
    print "save mode to : ", args.model_path

    dump_path = os.path.join(args.data_path, "rc_pcnn_data.pkl")
    if not os.path.exists(dump_path):
        dataloader = data_utils.DataLoader(args.data_path)
        cPickle.dump(dataloader, open(dump_path, "wb"))
    else:
        dataloader = cPickle.load(open(dump_path, "rb"))

    model = models.PCNNModel(dataloader.vocab_size, args.embedding_size,
                             dataloader.max_sent_len, dataloader.label_size,
                             None, filter_sizes, args.num_filters, True,
                             args.optimizer, args.learning_rate)
    print "begining to test model"
    model.test(dataloader, args.model_path)


if __name__ == '__main__':
    # main()
    test()
    pass