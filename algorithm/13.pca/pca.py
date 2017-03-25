#!/usr/bin/env python3
#-*- coding: UTF-8 -*-

from numpy import *

def loadDataSet(fileName,delim='\t'):
    fr=open(fileName)
    stringArr=[line.strip().split(delim) for line in fr.readlines()]
    datArr=[list(map(float,line)) for line in stringArr]
    return mat(datArr)
    pass

def pca(dataMat,topNfeat=9999999):              #   topNfeat 保留的维度
    meanVals = mean(dataMat, axis=0)
    meanRemoved = dataMat - meanVals            #   remove mean
    covMat = cov(meanRemoved, rowvar=0)         #   协方差矩阵
    eigVals,eigVects = linalg.eig(mat(covMat))  #   协方差矩阵的特征向量和特征系数
    eigValInd = argsort(eigVals)                #   特征系数从小到大排序
    eigValInd = eigValInd[:-(topNfeat+1):-1]    #   cut off unwanted dimensions
    redEigVects = eigVects[:,eigValInd]         #   reorganize eig vects largest to smallest
    lowDDataMat = meanRemoved * redEigVects     #   transform data into new dimensions
    reconMat = (lowDDataMat * redEigVects.T) + meanVals
    return lowDDataMat, reconMat
    pass

def replaceNanWithMean():   #   把缺失的数据用平均值来代替
    datMat=loadDataSet('secom.data',' ')
    numFeat=shape(datMat)[1]    #   特征个数
    for i in range(numFeat):
        meanVal=mean(datMat[nonzero(~isnan(datMat[:,i].A))[0],i])
        datMat[nonzero(isnan(datMat[:,i].A))[0],i]=meanVal
    return datMat
    pass
