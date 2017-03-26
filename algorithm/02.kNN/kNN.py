#!/usr/bin/env python
#-*- coding:UTF-8 -*-
#中文支持

from numpy import *
import operator
import os
#
def createDataSet():
    group=array([[1.0,1.1],[1.0,1.0],[0,0],[0,0.1]])
    labels=['A','A','B','B']
    return group,labels
    pass    #   'pass' does nothing but prevent grammatical error
#
def classify0(inX, dataSet, labels, k):
    #   inX :      需要分类的点
    #   dataSet :  字典
    #   labels :   标签      字典与标签的格式上的对应关系
    #   k
    dataSetSize = dataSet.shape[0]  #4 shape  =  Matlab sizeof  dataSet.shape=(4,2)
    diffMat = tile(inX, (dataSetSize,1)) - dataSet  #tile(A,B) repeat vector A for B times to construct a Matrix
    sqDiffMat = diffMat**2  #   A**B =(C++) power(A,B)
    sqDistances = sqDiffMat.sum(axis=1)
    distances = sqDistances**0.5
    #   compute the ditances ends;
    
    sortedDistIndicies = distances.argsort()    #   返回数值从小到大的索引值  ————注意返回的是索引值，而不是将原数组重新排序 
    classCount={}          
    for i in range(k):  # 统计投票结果
        voteIlabel = labels[sortedDistIndicies[i]]
        classCount[voteIlabel] = classCount.get(voteIlabel,0) + 1
    #   choose the Nearest K point ends;
    
    sortedClassCount = sorted(classCount.items(), key=operator.itemgetter(1), reverse=True)
    #   sorted ends;
    
    return sortedClassCount[0][0]

#   把从txt中读取的数据按程序需要的格式改写
def file2matrix(filename):
    fr = open(filename)
    numberOfLines = len(fr.readlines())         #get the number of lines in the file
    returnMat = zeros((numberOfLines,3))        #prepare matrix to return
    classLabelVector = []                       #prepare labels return   
    fr = open(filename)
    index = 0
    for line in fr.readlines():
        line = line.strip()
        listFromLine = line.split('\t') #   make list with Tab
        returnMat[index,:] = listFromLine[0:3]
        classLabelVector.append(int(listFromLine[3]))
        index += 1
    return returnMat,classLabelVector

#   归一化
def autoNorm(dataSet):
    minVals=dataSet.min(0)
    maxVals=dataSet.max(0)
    ranges=maxVals-minVals
    normDataSet=zeros(shape(dataSet))
    m=dataSet.shape[0]
    normDataSet=dataSet-tile(minVals,(m,1))
    normDataSet=normDataSet/tile(ranges,(m,1))
    return normDataSet,ranges,minVals
    pass

#   测试
def datingClassTest():
    hoRatio = 0.50      #hold out 10%
    datingDataMat,datingLabels = file2matrix('datingTestSet2.txt')       #load data setfrom file
    normMat, ranges, minVals = autoNorm(datingDataMat)  #归一化
    m = normMat.shape[0]
    numTestVecs = int(m*hoRatio)
    errorCount = 0.0
    for i in range(numTestVecs):
        classifierResult = classify0(normMat[i,:],normMat[numTestVecs:m,:],datingLabels[numTestVecs:m],3)
        print("the classifier came back with: %d, the real answer is: %d" % (classifierResult, datingLabels[i]))
        if (classifierResult != datingLabels[i]): errorCount += 1.0
    print("the total error rate is: %f" % (errorCount/float(numTestVecs)))
    print(errorCount)
    pass

#   拿一个人来分类，是否适合
def classifyPerson():
    resultList=['not at all','in small doses','in large doses']
    #   输入玩游戏所占时间比率
    percentTats=float(input("percentage of time spnet playing video games?"))
    ffMiles=float(input("frequent filer miles earned per year?"))
    #   每年消耗的冰激凌多少
    iceCream=float(input("liters of ice cream consumed per year?"))
    #   训练数据
    datingDataMat,datingLabels=file2matrix('datingTestSet2.txt')
    normMat,ranges,minVals=autoNorm(datingDataMat)
    inArr=array([ffMiles,percentTats,iceCream])
    classifierResult=classify0((inArr-minVals)/ranges,normMat,datingLabels,3)
    print("You will probably like this person:",resultList[classifierResult-1])
    pass
