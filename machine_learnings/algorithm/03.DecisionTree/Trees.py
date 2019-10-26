#!/usr/bin/env python
#-*- coding:UTF-8 -*-
#中文支持

#决策树
from numpy import *
import operator
import os

from math import log
def calcShannonEnt(dataSet):
    numEntries=len(dataSet)
    labelCounts={}  #   类标集合
    for featVec in dataSet:     #   对每一个训练数据
        currentLabel=featVec[-1]    #   最后一项为当前数据的类标
        if currentLabel not in labelCounts.keys():  #   如果当前类标还没有加入到类标集合中
            labelCounts[currentLabel]=0
        labelCounts[currentLabel]+=1    #统计当前类标一共出现了多少次
    shannonEnt=0.0
    for key in labelCounts:
        prob=float(labelCounts[key])/numEntries
        shannonEnt-=prob*log(prob,2)
    return shannonEnt
    pass

def createDataSet():
    dataSet=[[1,1,'yes'],[1,1,'yes'],[1,0,'no'],[0,1,'no'],[0,1,'no']]  #训练数据
    labels=['no surfacing','flippers']  #类标
    return dataSet,labels

#   按照给定的特征划分数据集
def splitDataSet(dataSet,axis,value):
    #   dataSet 待划分的数据集
    #   axis    划分数据集的特征
    #   value   特征      如：我们要抽取第axis个特征为value的项
    retDataSet=[]
    for featVec in dataSet:
        if featVec[axis]==value:
            reducedFeatVec=featVec[:axis]
            reducedFeatVec.extend(featVec[axis+1:])
            retDataSet.append(reducedFeatVec)
    return retDataSet
#   选取最佳特征
def chooseBestFeatureToSplit(dataSet):
    numFeatures = len(dataSet[0]) - 1       #   最后一个值不是特征  而是类标，所以要减一
    baseEntropy = calcShannonEnt(dataSet)   #   计算数据集的熵
    bestInfoGain = 0.0; bestFeature = -1
    for i in range(numFeatures):            #   对每一个特征进行循环
        featList = [example[i] for example in dataSet]  #   把当前样本的特征建成一个表
        uniqueVals = set(featList)          #   get a set of unique values
        newEntropy = 0.0
        for value in uniqueVals:
            subDataSet = splitDataSet(dataSet, i, value)
            prob = len(subDataSet)/float(len(dataSet))
            newEntropy += prob * calcShannonEnt(subDataSet)     
        infoGain = baseEntropy - newEntropy     #   calculate the info gain; ie reduction in entropy
        if (infoGain > bestInfoGain):           #   compare this to the best gain so far
            bestInfoGain = infoGain             #   if better than current best, set to best
            bestFeature = i
    return bestFeature                          #   returns an integer

#创建决策树
def createTree(dataSet,labels):
    #   dataSet     数据
    #   labels      标号
    classList = [example[-1] for example in dataSet]    #取出dataSet的最后一个值，标号
    if classList.count(classList[0]) == len(classList): #如果所有标号都已经相同，则不用继续分类
        return classList[0]#stop splitting when all of the classes are equal
    if len(dataSet[0]) == 1: #stop splitting when there are no more features in dataSet
        return majorityCnt(classList)
    bestFeat = chooseBestFeatureToSplit(dataSet)
    bestFeatLabel = labels[bestFeat]
    myTree = {bestFeatLabel:{}}
    del(labels[bestFeat])
    featValues = [example[bestFeat] for example in dataSet]
    uniqueVals = set(featValues)
    for value in uniqueVals:
        subLabels = labels[:]       #copy all of labels, so trees don't mess up existing labels
        myTree[bestFeatLabel][value] = createTree(splitDataSet(dataSet, bestFeat, value),subLabels)
    return myTree                            
#
def classify(inputTree,featLabels,testVec):
    firstStr = inputTree.keys()[0]
    secondDict = inputTree[firstStr]
    featIndex = featLabels.index(firstStr)
    key = testVec[featIndex]
    valueOfFeat = secondDict[key]
    if isinstance(valueOfFeat, dict): 
        classLabel = classify(valueOfFeat, featLabels, testVec)
    else: classLabel = valueOfFeat
    return classLabel
def majorityCnt(classList):#用投票的方法
    classCount={}
    for vote in classList:
        if vote not in classCount.keys(): classCount[vote] = 0
        classCount[vote] += 1
    sortedClassCount = sorted(classCount.iteritems(), key=operator.itemgetter(1), reverse=True)
    return sortedClassCount[0][0]
