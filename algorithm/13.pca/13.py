#!/usr/bin/env python3
#-*- coding: UTF-8 -*-
from numpy import *
import pca
import matplotlib
import matplotlib.pyplot as plt
from pylab import *

dataMat=pca.loadDataSet('testSet.txt')
print(shape(dataMat))

lowDMat,reconMat=pca.pca(dataMat,1)
print(shape(lowDMat))
fig=plt.figure(1)
ax=fig.add_subplot(111)
ax.scatter(dataMat[:,0].flatten().A[0],reconMat[:,1].flatten().A[0],marker='^',s=90)
ax.scatter(reconMat[:,0].flatten().A[0],reconMat[:,1].flatten().A[0],marker='o',s=50,c='red')
show()

lowDMat,reconMat=pca.pca(dataMat,2)
print(shape(lowDMat))
fig2=plt.figure(2)
ax=fig2.add_subplot(111)
ax.scatter(dataMat[:,0].flatten().A[0],reconMat[:,1].flatten().A[0],marker='^',s=90)
ax.scatter(reconMat[:,0].flatten().A[0],reconMat[:,1].flatten().A[0],marker='o',s=50,c='red')
show()

dataMat=pca.replaceNanWithMean()
meanVals=mean(dataMat,axis=0)
meanRemoved=dataMat-meanVals
covMat=cov(meanRemoved,rowvar=0)
eigVals,eigVects=linalg.eig(mat(covMat))
print(eigVals)  #   特征值


