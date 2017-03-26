#!/usr/bin/env python

import SVM
dataMat,labelMat=SVM.loadDataSet('testSet.txt')
print(dataMat)
print(labelMat)

b,alphas=SVM.smoSimple(dataMat,labelMat,0.6,0.001,40)
print(b)
print(alphas)

from numpy import *
print("The number of Support Vector:")
print(shape(alphas[alphas>0]))

for i in range(100):
    if(alphas[i]>0.0):
        print(dataMat[i],labelMat[i])




    
    