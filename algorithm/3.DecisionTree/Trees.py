#!/usr/bin/env python
#-*- coding:UTF-8 -*-
#����֧��

#������
from numpy import *
import operator
import os

from math import log
def calcShannonEnt(dataSet):
    numEntries=len(dataSet)
    labelCounts={}  #   ��꼯��
    for featVec in dataSet:     #   ��ÿһ��ѵ������
        currentLabel=featVec[-1]    #   ���һ��Ϊ��ǰ���ݵ����
        if currentLabel not in labelCounts.keys():  #   �����ǰ��껹û�м��뵽��꼯����
            labelCounts[currentLabel]=0
        labelCounts[currentLabel]+=1    #ͳ�Ƶ�ǰ���һ�������˶��ٴ�
    shannonEnt=0.0
    for key in labelCounts:
        prob=float(labelCounts[key])/numEntries
        shannonEnt-=prob*log(prob,2)
    return shannonEnt
    pass

def createDataSet():
    dataSet=[[1,1,'yes'],[1,1,'yes'],[1,0,'no'],[0,1,'no'],[0,1,'no']]  #ѵ������
    labels=['no surfacing','flippers']  #���
    return dataSet,labels

#   ���ո����������������ݼ�
def splitDataSet(dataSet,axis,value):
    #   dataSet �����ֵ����ݼ�
    #   axis    �������ݼ�������
    #   value   ����      �磺����Ҫ��ȡ��axis������Ϊvalue����
    retDataSet=[]
    for featVec in dataSet:
        if featVec[axis]==value:
            reducedFeatVec=featVec[:axis]
            reducedFeatVec.extend(featVec[axis+1:])
            retDataSet.append(reducedFeatVec)
    return retDataSet
#   ѡȡ�������
def chooseBestFeatureToSplit(dataSet):
    numFeatures = len(dataSet[0]) - 1       #   ���һ��ֵ��������  ������꣬����Ҫ��һ
    baseEntropy = calcShannonEnt(dataSet)   #   �������ݼ�����
    bestInfoGain = 0.0; bestFeature = -1
    for i in range(numFeatures):            #   ��ÿһ����������ѭ��
        featList = [example[i] for example in dataSet]  #   �ѵ�ǰ��������������һ����
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

#����������
def createTree(dataSet,labels):
    #   dataSet     ����
    #   labels      ���
    classList = [example[-1] for example in dataSet]    #ȡ��dataSet�����һ��ֵ�����
    if classList.count(classList[0]) == len(classList): #������б�Ŷ��Ѿ���ͬ�����ü�������
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
def majorityCnt(classList):#��ͶƱ�ķ���
    classCount={}
    for vote in classList:
        if vote not in classCount.keys(): classCount[vote] = 0
        classCount[vote] += 1
    sortedClassCount = sorted(classCount.iteritems(), key=operator.itemgetter(1), reverse=True)
    return sortedClassCount[0][0]
