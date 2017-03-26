#!/usr/bin/env python
#-*- coding: UTF-8 -*-

from numpy import *

def loadDataSet(fileName):
    dataMat=[]
    fr=open(fileName)
    for line in fr.readlines():
        curLine=line.strip().split('\t')
        fltLine=list(map(float,curLine))
        dataMat.append(fltLine)
    return dataMat
    pass

def distEclud(vecA,vecB):                                   #   欧几里德距离
    return sqrt(sum(power(vecA-vecB,2)))
    pass

def randCent(dataSet,k):                                    #   聚类中心随机初始化
    print("Size of dataSet:",shape(dataSet))
    n=shape(dataSet)[1]                                     #   特征个数
    print("n=shape(dataSet)[1]=",n)
    centroids=mat(zeros((k,n)))                             #   k为要选取的中心个数，n为每个中心的维度
    for j in range(n):                                      #   n为每个样本的维度
        minJ=min(dataSet[:,j])                              #   j=0,1,...,n-1  minJ为所有样本第j个数据的最小值
        rangeJ=float(max(dataSet[:,j])-minJ)                #   rangeJ为样本第j个数据的范围
        centroids[:,j]=minJ+rangeJ*random.rand(k,1)         #   在(minJ,minJ+rangeJ)中随机选一个数据为中心
    return centroids
    pass

def kMeans(dataSet,k,distMeans=distEclud,createCent=randCent):
    m=shape(dataSet)[0]                 #   样本个数
    clusterAssment=mat(zeros((m,2)))    #   clusterAssent:保存簇分配结果，第一列记录簇索引———每个样本属于哪一个索引，第二列记录误差
    centroids=createCent(dataSet,k)     #   初化聚类中心，k是人工确定要分为几类
    clusterChanged=True                 #   如果当前循环后，簇中心有变化，则继续迭代
    while clusterChanged:               #   实现迭代过程，直到簇中心不再变化 
        clusterChanged=False
        for i in range(m):              #   对每一个样本
            minDist=inf
            minIndex=-1
            for j in range(k):          #   对每一个质心
                distJI=distMeans(centroids[j,:],dataSet[i,:])       #   求第j个中心与第i个样本的距离
                if distJI<minDist:                                  #   目的是保存下距离最小的j，即当前点与哪一个质心最近
                    minDist=distJI
                    minIndex=j                                      #   当前样本属于第j类，赋给minIndex，并在之后保存在clusterAssent中
            if clusterAssment[i,0]!=minIndex:                       #   需要修改, 这一次的minIndex和上一次已经保存的minIndex相同，说明不再需要修改了
                clusterChanged=True     #   有修改，需要断续循环
            clusterAssment[i,:]=minIndex,minDist**2                 #   第一个数据中质心标，第二个数为误差
        print("centroids:",centroids)                               #   至此已经找到了k个质心
        for cent in range(k):                                       #   对每一个质心，找出属于这个质心的样本，并求出返回的质心
            ptsInClust=dataSet[nonzero(clusterAssment[:,0].A==cent)[0]]
            centroids[cent,:]=mean(ptsInClust,axis=0)
    return centroids,clusterAssment
    pass


