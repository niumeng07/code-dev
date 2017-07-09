#!/usr/bin/env python
#-*- coding: UTF-8 -*-

from numpy import *
import pdb

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

def randCent(dataSet,k):                                    #   随机求中心？
    print("Size of dataSet:",shape(dataSet))
    n=shape(dataSet)[1]
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
    centroids=createCent(dataSet,k)     #   k是人工确定要分为几类
    clusterChanged=True                 #   如果当前循环后，簇中心有变化，则继续迭代
    while clusterChanged:               #   实现迭代过程，直到簇中心不再变化 
        clusterChanged=False
        for i in range(m):              #   对每一个样本
            minDist=inf
            minIndex=-1
            for j in range(k):          #   对每一个质心
                distJI=distMeans(centroids[j,:],dataSet[i,:])       #   求距离
                if distJI<minDist:                                  #   目的是保存下距离最小的j，即当前点与哪一个质心最近
                    minDist=distJI
                    minIndex=j                                      #   当前样本属于第j类，赋给minIndex，并在之后保存在clusterAssent中
            if clusterAssment[i,0]!=minIndex:                       #   需要修改
                clusterChanged=True     #   有修改，需要断续循环
            clusterAssment[i,:]=minIndex,minDist**2                 #   第一个数据中质心标，第二个数为误差
        print("centroids:",centroids)                               #   至此已经找到了k个质心
        for cent in range(k):                                       #   对每一个质心，找出属于这个质心的样本，并求出返回的质心
            ptsInClust=dataSet[nonzero(clusterAssment[:,0].A==cent)[0]]
            centroids[cent,:]=mean(ptsInClust,axis=0)
    return centroids,clusterAssment
    pass

def binaryKeans(dataSet,k,distMeas=distEclud):
    m=shape(dataSet)[0]
    clusterAssment=mat(zeros((m,2)))            #   m行2列，保存m个数据的分配结果和误差
    centroid0=mean(dataSet,axis=0).tolist()[0]  #   原始质心———所有数据特征按列求均值，即分别求第一/第二个特征的均值
            # mean操作
            # a=mat([[1,2],[2,3],[3,4]])
            # 即a为
            # 1  2
            # 2  3
            # 3  4
            # 则:
            # mean(a)             =2.5         求所有数据的均值
            # mean(a,axis=0)      =2.0 3.0     按列求均值
            # mean(a,axis=1)      =1.5 2.5 3.5 按行求均值
    centList=[centroid0]    #   初始化第一个中心
    for j in range(m):      #   m个数据 对每一个数据求误差，保存在clusterAssment[:,1]中
        clusterAssment[j,1]=distMeas(mat(centroid0),dataSet[j,:])**2
    while len(centList)<k:  #   目标是分为k类，cenList是质心个数，小于说明还没有达到k类
        lowestSSE=inf       #   SSE 误差平方和，初始化为无穷大
        for i in range(len(centList)):  #   对已有的每一个中心
            ptsInCurrCluster = dataSet[nonzero(clusterAssment[:,0].A==i)[0],:]          #   得到在当前簇中的数据 pointsInCurrentCluster
            centroidMat, splitClustAss = kMeans(ptsInCurrCluster, 2, distMeas)          #   把当前簇中的数据分为两类
            sseSplit = sum(splitClustAss[:,1])                                          #   分类过后计算误差SSE
            sseNotSplit = sum(clusterAssment[nonzero(clusterAssment[:,0].A!=i)[0],1])   #   除上面被分割的簇外，其它的簇的SSE
            print("sseSplit=%d, and notSplit=%d" % (sseSplit,sseNotSplit))
            if (sseSplit + sseNotSplit) < lowestSSE:        #   说明分割后的SSE小于分割前的SSE
                bestCentToSplit = i         #   第i个质心的数据需要分割
                bestNewCents = centroidMat  #   分割后的质心
                bestClustAss = splitClustAss.copy()         #   分割后的标识
                lowestSSE = sseSplit + sseNotSplit
        bestClustAss[nonzero(bestClustAss[:,0].A == 1)[0],0] = len(centList) #change 1 to 3,4, or whatever
        bestClustAss[nonzero(bestClustAss[:,0].A == 0)[0],0] = bestCentToSplit
        print("The bdstCentToSplit is: ",bestCentToSplit)
        print("The length of bestClustAss is: ",len(bestClustAss))
        centList[bestCentToSplit] = bestNewCents[0,:].tolist()[0]           #   replace a centroid with two best centroids 
        centList.append(bestNewCents[1,:].tolist()[0])
        clusterAssment[nonzero(clusterAssment[:,0].A == bestCentToSplit)[0],:]= bestClustAss    #   reassign new clusters, and SSE
    return mat(centList), clusterAssment
    pass

import urllib
import urllib.parse
import urllib.request
import json
def geoGrab(stAddress,city):
    apiStem='http://where.yahooapis.com/geocode?'
    params={}
    params['flags']='J'
    params['appid']='MyApplication'
    params['location']='%s %s' % (stAddress,city)
    url_params=urllib.parse.urlencode(params)
    yahooApi=apiStem+url_params
    print("yahooApi:",yahooApi)
    c=urllib.request.urlopen(yahooApi)
    return json.loads(c.read())
    pass

from time import sleep
def massPlaceFind(fileName):
    fw=open('places.txt','w')
    for line in open(fileName).readlines():
        line=line.strip()
        lineArr=line.split('\t')
        retDict=geoGrab(lineArr[1],lineArr[2])
        if retDict['ResultSet']['Error']==0:
            lat=float(retDict['ResultSet']['Results'][0]['latitude'])
            lng=float(retDict['ResultSet']['Results'][0]['longitude'])
            print("%s\t%f\t%f" % (lineArr[0],lat,lng))
        else:
            print("Error fetching")
        sleep(1)
    fw.close()
    pass

