#!/usr/bin/env python
#-*- coding:UTF-8 -*-

from numpy import *
import operator

import math

#≤‚ ‘Ïÿµƒº∆À„
a=[[1,1,2,2,3,4,5],[1,1,2,2,3,4,5],
    [1,1,2,2,3,4,7],
    [1,1,2,2,3,4,8],[1,1,2,2,3,4,8],[1,1,2,2,3,4,8]]
p={}
for V in a:
    label=V[-1]
    if label not in p:
        p[label]=0
    p[label]+=1
for label in p:
    p[label]=p[label]/shape(a)[0]
H=0
for label in p:
    H-=p[label]*log(p[label])
print(p)
print(H)

import matplotlib
import matplotlib.pyplot as plt
fig=plt.figure()
ax=fig.add_subplot(111)
import kNN
datingDataMat,datingLabels=kNN.file2matrix('datingTestSet2.txt')
print(datingDataMat)
print(datingLabels)
ax.scatter(datingDataMat[:,1],
           datingDataMat[:,2],
           15.0*array(datingLabels),
           15.0*array(datingLabels))
plt.show()