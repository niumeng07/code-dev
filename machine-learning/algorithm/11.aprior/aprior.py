#!/usr/bin/env python3

def loadDataSet():
    return [[1,3,4],[2,3,5],[1,2,3,5],[2,5]]
    pass

def createC1(dataSet):
    #构建集合C1  单项的候选集———C1是大小为1的所有候选项集的集合
    C1=[]
    for transaction in dataSet:     #   dataSet中的每一个样本
        for item in transaction:    #   每个样本的每一个特征
            if not [item] in C1:    #   所有出现过的特征在C1中有且只有一次
                C1.append([item])
    C1.sort()       #   对C1进行排序
    return list(map(frozenset,C1))  #   frozenset：一种Python类型，不可修改的set
    pass

def scanD(D, Ck, minSupport):
    #   D：候选项集
    #   Ck：字典
    #   minSupport：最小支持度
    ssCnt = {}
    for tid in D:       #   D为候选集，对候选集中每一个项集检测是否满足p_tid>=minSupport
        for can in Ck:  #   Ck为字典，是用D构造的，他包含D中的每一个数据，且每个数据只包含一次
            if can.issubset(tid):   #   如果候选项集tid中有can
                if not can in ssCnt:    #   can还没加入到ssCnt中
                    ssCnt[can]=1
                else:                   #   ssCnt中已经有can项
                    ssCnt[can] += 1
    #   到这里，字典中的每一个项，在D中出现的字数已经统计完成了
    numItems = float(len(D))    #   候选项个数
    retList = []
    supportData = {}
    for key in ssCnt:
        support = ssCnt[key]/numItems
        if support >= minSupport:
            retList.insert(0,key)
        supportData[key] = support
    return retList, supportData
    pass

def aprioriGen(Lk,k):   #   creates Ck
    retList=[]
    lenLk=len(Lk)
    for i in range(lenLk):
        for j in range(i+1,lenLk):
            L1=list(Lk[i])[:k-2]
            L2=list(Lk[j])[:k-2]    #   A[:K]   表示A的第0项到第K-1项
            L1.sort()
            L2.sort()
            if L1==L2:
                retList.append(Lk[i]|Lk[j])
    return retList
    pass

def apriori(dataSet,minSupport=0.5):
    C1=createC1(dataSet)
    D=list(map(set,dataSet))
    L1,SupportData=scanD(D,C1,minSupport)   #   L1是单项高频候选集，其它集合从这里衍生出来
    L=[L1]
    k=2
    while len(L[k-2])>0:
        Ck=aprioriGen(L[k-2],k)
        Lk,SupK=scanD(D,Ck,minSupport)
        SupportData.update(SupK)
        L.append(Lk)
        k+=1
        if (k-2)>len(L):
            break
    return L,SupportData
    pass

def generateRules(L, supportData, minConf=0.7):  #supportData is a dict coming from scanD
    #   生成候选规则并对规则进行评估
    #   参数：L————频繁项集列表
    #         supportData————包含频繁项集支持数据的字典
    #           L和supportData正是apriori返回的结果
    #         minConf————可信度的阈值
    bigRuleList = []
    for i in range(1, len(L)):      #   对每一个频繁项单项集
        for freqSet in L[i]:        #   该单项集中的每一个元素
            H1 = [frozenset([item]) for item in freqSet]
            if (i > 1):     #   如果频繁项集中的数目超过2，则会考虑合并
                rulesFromConseq(freqSet, H1, supportData, bigRuleList, minConf)
            else:   #   如果只有两个元素  注意 i是从0开始的   
                calcConf(freqSet, H1, supportData, bigRuleList, minConf)
    return bigRuleList         

def calcConf(freqSet, H, supportData, brl, minConf=0.7):
    #   计算置信度
    #   freqSet频繁项
    prunedH = [] #create new list to return
    for conseq in H:
        conf = supportData[freqSet]/supportData[freqSet-conseq]         #   calc confidence
        if conf >= minConf: 
            print(freqSet-conseq,'-->',conseq,'\tconf:',conf)
            brl.append((freqSet-conseq, conseq, conf))
            prunedH.append(conseq)
    return prunedH

def rulesFromConseq(freqSet, H, supportData, brl, minConf=0.7):
    m = len(H[0])
    if (len(freqSet) > (m + 1)):        #   try further merging
        Hmp1 = aprioriGen(H, m+1)       #   create Hm+1 new candidates
        Hmp1 = calcConf(freqSet, Hmp1, supportData, brl, minConf)
        if (len(Hmp1) > 1):             #   need at least two sets to merge
            rulesFromConseq(freqSet, Hmp1, supportData, brl, minConf)
            
