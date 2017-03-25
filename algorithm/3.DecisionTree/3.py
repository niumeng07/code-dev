#!/usr/bin/env python
#-*- coding:UTF-8 -*-
#中文支持

#决策树

from numpy import *
import operator
import os

import Trees
myData,labels=Trees.createDataSet()
print(myData)
print(labels)
print(Trees.calcShannonEnt(myData))

myData[0][-1]='maybe'
print(myData)
print(labels)
print(Trees.calcShannonEnt(myData))

myDat,labels=Trees.createDataSet()
print(myDat)
print(Trees.splitDataSet(myDat,0,1))
print(Trees.splitDataSet(myData,0,0))

print(Trees.chooseBestFeatureToSplit(myDat))

myTree=Trees.createTree(myDat,labels)
print(myTree)

import TreePlotter

TreePlotter.createPlot()



