# encoding:utf-8


import codecs


def read_lines(file_name, code='utf-8'):
    try:
        with codecs.open(file_name, 'rb', code) as f:
            lines = f.readlines()
            return lines
    except:
        return list()

