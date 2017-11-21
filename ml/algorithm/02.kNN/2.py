#!/usr/bin/env python
#-*- coding:UTF-8 -*-
#中文支持

#kNN简单例子
from numpy import *
import operator
import sys, os

random.rand(4,4)
randMat=mat(random.rand(4,4))
randMatI=randMat.I

import kNN
group,labels=kNN.createDataSet()
print(group)
print(labels)

result=kNN.classify0([0,0],group,labels,3)
print("result: ", result)
print("classify [1,1] result: ", kNN.classify0([1,1],group,labels,3))

sys.exit(0)
#reload(kNN)
datingDataMat,datingLabels=kNN.file2matrix('datingTestSet2.txt')
print(datingDataMat)
print(datingLabels[0:20])

#kNN约会推荐系统
import matplotlib
import matplotlib.pyplot as plt
fig=plt.figure()
ax=fig.add_subplot(111)
ax.scatter(datingDataMat[:,1],datingDataMat[:,2])

ax.scatter(datingDataMat[:,1],
           datingDataMat[:,2],
           15.0*array(datingLabels),
           15.0*array(datingLabels))

#plt.show()

normMat,ranges,minVals=kNN.autoNorm(datingDataMat)
print('autoNorm Result:')
print(normMat)
print(ranges)
print(minVals)

kNN.datingClassTest()
kNN.classifyPerson()

#kNN手写体数字识别
import HandWritingNumber
testVector=HandWritingNumber.img2vector('testDigits/0_13.txt')
print(testVector[0,0:31])
print(testVector[0,32:63])

HandWritingNumber.handwritingClassTest()



