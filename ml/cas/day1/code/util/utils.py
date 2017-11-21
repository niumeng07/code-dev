# encoding:utf-8

import os
import jieba, nltk


def tokenizer(sent, lang='zh'):
    if lang == 'zh':
        words = [w.strip() for w in jieba.cut(sent)]
    else:
        words = [w.strip() for w in nltk.word_tokenize(sent)]
    return [w for w in words if len(w) > 0]


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
