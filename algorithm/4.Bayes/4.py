#!/usr/bin/env python

#中文支持
import Bayes

listOPost,listClasses=Bayes.loadDataSet()
#listOPost 由函数返回的N*M的数组  每一行为每个句子的M个词  一个N个句子
#listClasses 为每个句子是否有侮辱性词汇  0或1  在Bayes中人工确定
print("listOPost:")
print(listOPost)
print("listClasses:")
print(listClasses)
myVocabList=Bayes.createVocabList(listOPost)
#myVocabList由N*M的表创建的不重复的词汇表
print("myVocabList:")
print(myVocabList)
print("listOPost[0]:")
print(listOPost[0])
print("listOPost:")
print(listOPost)
print(Bayes.setOfWords2Vec(myVocabList,listOPost[0]))
#Bayes.setOfWords2Vec()两个参数，第一个是字典词汇表，第二个是要测试的一个句子
#该函数测试词汇表中的每一个词是否出现在这个被测试的句子中
print(Bayes.setOfWords2Vec(myVocabList,listOPost[3]))

from numpy import *
trainMat=[]
for postinDoc in listOPost:#listOPost为一个M*N的矩阵
    print(postinDoc)    #每一行
    trainMat.append(Bayes.setOfWords2Vec(myVocabList,postinDoc))#把每一行的每个词是否包含在字典中加入到trainMat中
    print(trainMat)
p0V,p1V,pAb=Bayes.trainNB0(trainMat,listClasses)
print(p0V)
print(p1V)
print(pAb)

Bayes.testingNM()


#邮件
import re   # re  正则表达式
regEx=re.compile('\\W*')    #正则表达式
emailText=open('email/ham/6.txt').read()
listOfTokens=regEx.split(emailText)
print(listOfTokens)

Bayes.spamTest()