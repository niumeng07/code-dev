#-*- coding: utf-8 -*-
#!/usr/bin/env python

#中文支持
from numpy import *

def loadDataSet():
    postingList=[['my','dog','has','flea','problems','help','please'],
        ['mabe','not','take','him','to','dog','park','stupid'],
        ['my','dalmation','is','so','cute','I','love','him'],
        ['stop','posting','stupid','worthless','barbage'],
        ['mr','licks','ate','my','steak','how','to','stop','him'],
        ['quit','buying','worthless','dog','food','stupid']]
    classVec=[0,1,0,1,0,1]#一代表侮辱性文字，0代表正常言论 人工标注 用来训练程序
    return postingList,classVec
    pass    #

def createVocabList(dataSet):
    vocabSet=set([])        #   利用set模型 把词条输入到set里，set会返回无重复的表
    for document in dataSet:
        vocabSet=vocabSet|set(document)
    return list(vocabSet)      #    构建了不重复出现的词汇表

def setOfWords2Vec(vocabList,inputSet):
    #   vocabList           词汇表
    #   inputSet            文档
    #   返回returnVec       向量 值为0或1 表示词汇表中的词在文档中是否出现
    returnVec=[0]*len(vocabList)
    for word in inputSet:
        if word in vocabList:
            returnVec[vocabList.index(word)]=1
        else:
            print("the word: %s is not in my Vocabulary!" % word)
    return returnVec

def trainNB0(trainMatrix,trainCategory):
    #trainMatrix    字典
    #trainCategory  字典每一个元的类标
    numTrainDocs=len(trainMatrix)#字典一共有多少个元
    numWords=len(trainMatrix[0])#字典在当前元中的存在情况
    pAbusive = sum(trainCategory)/float(numTrainDocs)
    #p0Num = zeros(numWords); p1Num = zeros(numWords)      
    #p0Denom = 0.0; p1Denom = 0.0
    p0Num=ones(numWords);p1Num=ones(numWords)
    p0Denom=2.0;p1Denom=2.0
    for i in range(numTrainDocs):           #对每一个字典元  如第第一个字典元 i=1
        if trainCategory[i] == 1:           #如果第i个字典元是侮辱性的
            p1Num += trainMatrix[i]             #把出现的词个总次数记录下来
            p1Denom += sum(trainMatrix[i])      #字典中共有8个词出现在了第i个字典元中
        else:
            p0Num += trainMatrix[i]
            p0Denom += sum(trainMatrix[i])
    #p1Vect = p1Num/p1Denom 
    #p0Vect = p0Num/p0Denom
    p1Vect = log(p1Num/p1Denom)
    p0Vect = log(p0Num/p0Denom)
    return p0Vect,p1Vect,pAbusive
    pass
def classifyNB(vec2Classify,p0Vec,p1Vec,pClass1):
    p1=sum(vec2Classify*p1Vec)+log(pClass1)
    p0=sum(vec2Classify*p0Vec)+log(1.0-pClass1)
    if(p1>p0):
        return 1
    else:
        return 0
    pass
def testingNM():
    listOPosts,listClasses=loadDataSet()
    myVocabList=createVocabList(listOPosts)
    trainMat=[]
    for postinDoc in listOPosts:
        trainMat.append(setOfWords2Vec(myVocabList,postinDoc))
    p0V,p1V,pAb=trainNB0(array(trainMat),array(listClasses))
    testEntry=['love','my','dalmation']
    thisDoc=array(setOfWords2Vec(myVocabList,testEntry))
    print(testEntry,'classified as:',classifyNB(thisDoc,p0V,p1V,pAb))
    testEntry=['stupid','garbage']
    thisDoc=array(setOfWords2Vec(myVocabList,testEntry))
    print(testEntry,'classified as:',classifyNB(thisDoc,p0V,p1V,pAb))
    pass

#接受一个大写字符串并将其解析为字符串列表  返回值为小写 并删除长度<=2的字符串
#如输入bigString=abcD a bc DEFGaa
#则返回          abcd defgaa
def textParse(bigString):
    import re
    listOfTokens=re.split(r'\W*',bigString)
    return [tok.lower() for tok in listOfTokens if len(tok) > 2]

def spamTest():
    docList=[]
    classList=[]
    fullText=[]
    for i in range(1,26):
        #导入email/spam下的文件形成词表
        wordList=textParse(open('email/spam/%d.txt' % i).read())    
        docList.append(wordList)#append与extend的区别
        fullText.extend(wordList)
        classList.append(1)  
        #导入email/ham 下的文件形成词表
        wordList=textParse(open('email/ham/%d.txt' % i).read())   #s.decode('gbk', ‘ignore').encode('utf-8′) 
        docList.append(wordList)
        fullText.extend(wordList)
        classList.append(0)
        pass
    vocabList = createVocabList(docList)#create vocabulary
    trainingSet = range(50)
    tmp=[]
    result=[]
    testSet=[]           #create test set
    #随机的形成训练集
    for i in range(10):
        randIndex = int(random.uniform(0,len(trainingSet)))
        testSet.append(trainingSet[randIndex])
        tmp.append(randIndex)
        '''
        for atom in trainingSet:
            if atom in tmp:
                pass
            else:
                result.append(atom)
        trainingSet=result  #'''
        #del(trainingSet[randIndex])
        pass
    trainMat=[]; trainClasses = []
    for docIndex in trainingSet:#train the classifier (get probs) trainNB0
        trainMat.append(bagOfWords2VecMN(vocabList, docList[docIndex]))
        trainClasses.append(classList[docIndex])
        pass
    p0V,p1V,pSpam = trainNB0(array(trainMat),array(trainClasses))
    errorCount = 0
    #测试集
    for docIndex in testSet:        #classify the remaining items
        wordVector = bagOfWords2VecMN(vocabList, docList[docIndex])
        if classifyNB(array(wordVector),p0V,p1V,pSpam) != classList[docIndex]:
            errorCount += 1
            print("classification error",docList[docIndex])
            pass
        pass
    print('the error rate is: ',float(errorCount)/len(testSet))
    #return vocabList,fullText
def bagOfWords2VecMN(vocabList, inputSet):
    returnVec = [0]*len(vocabList)
    for word in inputSet:
        if word in vocabList:
            returnVec[vocabList.index(word)] += 1
    return returnVec
