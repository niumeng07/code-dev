#!/usr/bin/env python
#-*- coding:UTF-8 -*-
#����֧��

#����kNN����������д�����ֽ��з���
from numpy import *
import operator
import os

#��txt������ת��������
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
    hwLabels=[]     #���������
    trainingFileList=os.listdir('trainingDigits')   #ѵ������Ŀ¼�б�
    m=len(trainingFileList) #Ŀ¼��һ���ж��ٸ��ļ�
    trainingMat=zeros((m,1024))     #
    for i in range(m):
        fileNameStr=trainingFileList[i]
        fileStr=fileNameStr.split('.')[0]       #�ļ�����ʽΪ  0_3.txt
        classNumStr=int(fileStr.split('_')[0])  #��һ����Ϊ�ļ���ʵ�ʵ�ֵ
        hwLabels.append(classNumStr)
        trainingMat[i,:]=img2vector('trainingDigits/%s'%fileNameStr)
    testFileList=os.listdir('testDigits')
    errorCount=0.0
    mTest=len(testFileList)
    for i in range(mTest):
        fileNameStr=testFileList[i]
        fileStr=fileNameStr.split('.')[0]
        classNumStr=int(fileStr.split('_')[0])
        #trainingMat ѵ��ͼ��ת����������
        #vectorUnderTest ����ͼ��ת����������
        vectorUnderTest=img2vector('testDigits/%s'%fileNameStr)
        #��kNN��������
        #vectorUnder�ǵȴ���������ݣ�trainingMat�൱��������hwLabelsΪ������
        classifierResult=kNN.classify0(vectorUnderTest,trainingMat,hwLabels,3)
        print("the classifier came back with: %d, the real anser is: %d "%(classifierResult,classNumStr))
        if(classifierResult!=classNumStr):  #classNumStr�����ļ����ó�������
            errorCount+=1.0
    print("\nthe total number of errors is: %d"%errorCount)
    print("\nthe total error rate is: %f"%(errorCount/float(mTest)))
    
    pass

    
    
    
    