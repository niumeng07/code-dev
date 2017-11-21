# encoding:utf-8

import sys
reload(sys)
sys.setdefaultencoding('utf8')

import os, codecs
from collections import Counter

def initialize_vocab(vocab_path):
    if os.path.exists(vocab_path):
        rev_vocab = []
        with codecs.open(vocab_path, 'rb', 'utf-8') as f:
            for line in f:
                rev_vocab.append(line.strip())
        vocab = dict([(x, y) for (y, x) in enumerate(rev_vocab)])
        return vocab, rev_vocab
    else:
        raise ValueError("Vocabulary file %s not found.", vocab_path)


def tokens_to_ids(words, vocab, UNK_ID):
    return [vocab.get(w, UNK_ID) for w in words]


def ids_to_sentence(ids, vocab_list, cut_id=None, pad=' '):
    if len(ids) == 0:
        return ''
    if isinstance(ids[0], list):
        sents = list()
        for one in ids:
            one_sents = ids_to_sentence(one, vocab_list, pad)
            if isinstance(one_sents, list):
                sents.extend(one_sents)
            else:
                sents.append(one_sents)
        return sents
    else:
        if cut_id is not None and cut_id in ids:
            ids = ids[:ids.index(cut_id)]
        words = [vocab_list[id] for id in ids]
        return pad.join(words)


# 过滤词汇表，vocab为dict数据，{word:frq}的形式
def filter_vocab(vocab, min_frq=5, max_vocab_size=0):
    word_counts = Counter()
    for w, frq in vocab.items():
        word_counts[w] = frq

    def vocab_stat(tmp_vocab):
        return len(tmp_vocab), sum([x[1] for x in tmp_vocab])

    origin_num, orgin_frq = vocab_stat(word_counts.items())
    print "orgin word num/frq : %d/%d" % (origin_num, orgin_frq)
    if min_frq > 0:
        new_vocab = Counter()
        for w, frq in vocab.items():
            if frq >= min_frq:
                new_vocab[w] = frq
                word_counts = new_vocab
        curr_num, curr_frq = vocab_stat(word_counts.items())
        print "filter min_frq word num/frq : %d/%d" % (curr_num, curr_frq)
        print "occupy %.3f (num), %.3f (frq)" % (curr_num * 1.0 / origin_num, curr_frq * 1.0 / orgin_frq)

    if max_vocab_size > 0:
        new_word_counts = word_counts.most_common(max_vocab_size)
    else:
        new_word_counts = word_counts.most_common()
    curr_num, curr_frq = vocab_stat(new_word_counts)
    print "select word num/frq : %d/%d" % (curr_num, curr_frq),
    print "occupy %.3f (num), %.3f (frq)" % (curr_num * 1.0 / origin_num, curr_frq * 1.0 / orgin_frq)
    return dict(new_word_counts)