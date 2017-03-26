#!/usr/bin/env python
#-*- coding: UTF-8 -*-

import kMeans2
from numpy import *

dataMat=mat(kMeans2.loadDataSet('testSet.txt'))
kMeansRandCenter=kMeans2.randCent(dataMat,2) #   两个中心
print(kMeansRandCenter)

centroids,clusterAssment=kMeans2.kMeans(dataMat,5)


