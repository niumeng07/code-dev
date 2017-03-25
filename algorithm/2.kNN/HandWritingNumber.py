#!/usr/bin/env python
#-*- coding:UTF-8 -*-
#中文支持

#采用kNN分类器对手写体数字进行分类
from numpy import *
import operator
import os

#把txt中数据转化成向量
def img2vector(filename):
    returnVect=zeros((1,1024))
    fr=open(filename)
    for i in range(32):
        lineStr=fr.readline()
        for j in range(32):
            returnVect[0,32*i+j]=int(lineStr[j])
    return returnVect
    pass

import kNN

def handwritingClassTest():
    hwLabels=[]     #保存分类结果
    trainingFileList=os.listdir('trainingDigits')   #训练数据目录列表
    m=len(trainingFileList) #目录中一共有多少个文件
    trainingMat=zeros((m,1024))     #
    for i in range(m):
        fileNameStr=trainingFileList[i]
        fileStr=fileNameStr.split('.')[0]       #文件名格式为  0_3.txt
        classNumStr=int(fileStr.split('_')[0])  #第一部分为文件中实际的值
        hwLabels.append(classNumStr)
        trainingMat[i,:]=img2vector('trainingDigits/%s'%fileNameStr)
    testFileList=os.listdir('testDigits')
    errorCount=0.0
    mTest=len(testFileList)
    for i in range(mTest):
        fileNameStr=testFileList[i]
        fileStr=fileNameStr.split('.')[0]
        classNumStr=int(fileStr.split('_')[0])
        #trainingMat 训练图像转化来的向量
        #vectorUnderTest 测试图像转化来的向量
        vectorUnderTest=img2vector('testDigits/%s'%fileNameStr)
        #在kNN分类器中
        #vectorUnder是等待分类的数据，trainingMat相当于字曲，hwLabels为结果标号
        classifierResult=kNN.classify0(vectorUnderTest,trainingMat,hwLabels,3)
        print("the classifier came back with: %d, the real anser is: %d "%(classifierResult,classNumStr))
        if(classifierResult!=classNumStr):  #classNumStr是由文件名得出的数字
            errorCount+=1.0
    print("\nthe total number of errors is: %d"%errorCount)
    print("\nthe total error rate is: %f"%(errorCount/float(mTest)))
    
    pass

    
    
    
    