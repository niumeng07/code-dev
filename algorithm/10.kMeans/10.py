#!/usr/bin/env python
#-*- coding: UTF-8 -*-

import kMeans
from numpy import *

dataMat=mat(kMeans.loadDataSet('testSet.txt'))
kMeansRandCenter=kMeans.randCent(dataMat,2) #   两个中心
print(kMeansRandCenter)

centroids,clusterAssment=kMeans.kMeans(dataMat,5)

import matplotlib.pyplot as plt
fig=plt.figure(1)
plt.plot(centroids[:,0],centroids[:,1],'ro')
plt.plot(dataMat[:,0],dataMat[:,1],'bo')
plt.axis([-8,8,-8,8])
# plt.show()

kMeans.binaryKeans(dataMat,3)

dataMat3=mat(kMeans.loadDataSet('testSet2.txt'))
centList,Assments=kMeans.binaryKeans(dataMat3,3)
print("centList:",centList)
print("Assments:",Assments)
fig=plt.figure(2)
plt.plot(dataMat3[:,0],dataMat3[:,1],'bo')
plt.plot(centList[:,0],centList[:,1],'ro')
plt.axis([-10,10,-10,10])
# plt.show()

geoResults=kMeans.geoGrab('l Va Center','Augusta, ME')
#print("geoResults",geoResults)