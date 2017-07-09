#!/usr/bin/env python

import ReGression
from numpy import *
import os
import operator

xArr,yArr=ReGression.loadDataSet('ex0.txt')
print(xArr)
print(yArr)
ws=ReGression.standRegres(xArr,yArr) #系数
print(ws)

import matplotlib.pyplot as plt
xMat=mat(xArr)  #x坐标
yMat=mat(yArr)  #y坐标
yHat=xMat*ws    #用y=WT*Xi进行预测
fig=plt.figure()
ax=fig.add_subplot(111)
ax.scatter(xMat[:,1],yMat.T[:,0])
#ax.scatter(xMat[:,1].flatten().A[0],yMat.T[:,0].flatten.A[0])
xCopy=xMat.copy()
xCopy.sort(0)
yHat=xCopy*ws
#print("xCopy:",xCopy)
#print("yHat:",yHat)
ax.plot(xCopy[:,1],yHat)
plt.show()
print(yArr[0])
print(ReGression.lwlr(xArr[0],xArr,yArr,1.0))
yHat=ReGression.lwlrTest(xArr,xArr,yArr,0.003)
print("yHat=",yHat)
xMat=mat(xArr)
srtInd=xMat[:,1].argsort(0)
xSort=xMat[srtInd][:,0,:]
import matplotlib.pyplot as plt
fig=plt.figure()
ax=fig.add_subplot(111)
ax.plot(xSort[:,1],yHat[srtInd])
ax.scatter(xMat[:,1],mat(yArr).T,2,c='red')
plt.show()

abx,aby=ReGression.loadDataSet('abalone.txt')
yHat01=ReGression.lwlrTest(abx[0:99],abx[0:99],aby[0:99],0.1)
yHat1=ReGression.lwlrTest(abx[0:99],abx[0:99],aby[0:99],1)
yHat10=ReGression.lwlrTest(abx[0:99],abx[0:99],aby[0:99],10)
print(ReGression.rssError(aby[0:99],yHat01.T))
print(ReGression.rssError(aby[0:99],yHat1.T))
print(ReGression.rssError(aby[0:99],yHat10.T))

abx,aby=ReGression.loadDataSet('abalone.txt')
ridgeWeights=ReGression.ridgeTest(abx,aby)
print("ridgeWeights=",ridgeWeights)
import matplotlib.pyplot as plt
fig=plt.figure()
ax=fig.add_subplot(111)
ax.plot(ridgeWeights)
plt.show()

lgX=[];lgY=[]
ReGression.setDataCollect(lgX,lgY)