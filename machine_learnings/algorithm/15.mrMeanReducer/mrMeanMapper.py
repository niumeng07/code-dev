#!/usr/bin/env python3
#-*- coding: UTF-8 -*-

import sys
from numpy import mat,mean,power

def read_input(file):
    for line in file:
        yield line.rstrip()
        pass
input=read_input(sys.stdin)
input=[float(line) for line in input]
numInputs=len(input)
sqInput=power(input,2)
print("%d\t%f\t%f" % (numInputs,mean(input),mean(sqInput)))
#print >> sys.stderr, "report: still alive"  #python2写法
sys.stderr.write('report: still alive')      #python3.3写法
