#!/usr/bin/env python3
#-*- coding: UTF-8 -*-

class treeNode:
    #   初始化
    def __init__(self,nameValue,numOccur,parentNode):
        self.name=nameValue
        self.count=numOccur
        self.nodeLink=None      #   用于链接相似的结点
        self.parent=parentNode
        self.children={}
        pass
    #   方法：self.count+numOccur
    def increase(self, numOccur):
        self.count+=numOccur
        pass
    #   方法：把树以文本形式显示
    def display(self, ind=1):
        print("  "*ind,self.name,"  ",self.count)
        for child in self.children.values():
            child.display(ind+1)
        pass

def createTree(dataSet, minSup=1): #create FP-tree from dataset but don't mine
    headerTable = {}
    
    #go over dataSet twice
    for trans in dataSet:   #   第一次遍历扫描数据集并统计每个元素项出现的频度
        for item in trans:
            headerTable[item] = headerTable.get(item, 0) + dataSet[trans]
    
    headtmp=headerTable.copy()      #   注意，不能直接对headerTable进行删除，因为在循环过程中同时改变大小，Python3中不通过
    for k in headerTable.keys():    #   扫描并删除频度小于minSup的项
        if headerTable[k] < minSup:
            del(headtmp[k])
    headerTable=headtmp.copy()
    del(headtmp)
    #   headerTable是频繁单项
    freqItemSet = set(headerTable.keys())   #   把频繁项构建成一个set
    print('freqItemSet: ',freqItemSet)
    if len(freqItemSet) == 0:   #   如果set的长度为0，说明没有频繁项
        return None, None  
    for k in headerTable:   #对每一个频繁项集
        headerTable[k] = [headerTable[k], None]     #   添加相似项表指针
    print('headerTable: ',headerTable)
    retTree = treeNode('Null Set', 1, None)         #   创建根结点，只含空集
    #   再次遍历数据，只考虑频繁项
    for tranSet, count in dataSet.items():  #   go through dataset 2nd time
        localD = {}
        for item in tranSet:  # put transaction items in order
            if item in freqItemSet: #   如果这个元素出现在了频繁项中，则把它添加到表头中
                localD[item] = headerTable[item][0]
        if len(localD) > 0:     #   如果频繁项的个数不为0
            orderedItems = [v[0] for v in sorted(localD.items(), key=lambda p: p[1], reverse=True)]
            updateTree(orderedItems, retTree, headerTable, count)#populate tree with ordered freq itemset
    return retTree, headerTable #return tree and header table

def updateTree(items, inTree, headerTable, count):
    #   items   
    if items[0] in inTree.children:#check if orderedItems[0] in retTree.children
        inTree.children[items[0]].increase(count) #incrament count
    else:   #add items[0] to inTree.children
        inTree.children[items[0]] = treeNode(items[0], count, inTree)
        if headerTable[items[0]][1] == None: #update header table 
            headerTable[items[0]][1] = inTree.children[items[0]]
        else:
            updateHeader(headerTable[items[0]][1], inTree.children[items[0]])
    if len(items) > 1:#call updateTree() with remaining ordered items
        updateTree(items[1::], inTree.children[items[0]], headerTable, count)
        
def updateHeader(nodeToTest, targetNode):   #this version does not use recursion
    while (nodeToTest.nodeLink != None):    #Do not use recursion to traverse a linked list!
        nodeToTest = nodeToTest.nodeLink
    nodeToTest.nodeLink = targetNode

def loadSimpDat():
    simpDat = [['r', 'z', 'h', 'j', 'p'],
               ['z', 'y', 'x', 'w', 'v', 'u', 't', 's'],
               ['z'],
               ['r', 'x', 'n', 'o', 's'],
               ['y', 'r', 'x', 'z', 'q', 't', 'p'],
               ['y', 'z', 'x', 'e', 'q', 's', 't', 'm']]
    return simpDat

def createInitSet(dataSet):
    retDict = {}
    for trans in dataSet:
        retDict[frozenset(trans)] = 1
    return retDict

def ascendTree(leafNode,prefixPath):
    if leafNode.parent!=None:
        prefixPath.append(leafNode.name)
        ascendTree(leafNode.parent,prefixPath)
    pass

def findPrefixPath(basePat,treeNode):
    condPats={}
    while treeNode!=None:
        prefixPath=[]
        ascendTree(treeNode,prefixPath)
        if len(prefixPath)>1:
            condPats[frozenset(prefixPath[1:])]=treeNode.count
        treeNode=treeNode.nodeLink
    return condPats
    pass

def mineTree(inTree,headerTable,minSup,preFix,freqItemList):
    bigL=[v[0] for v in sorted(headerTable.items(),key=lambda p:p[1])]
    
    for basePat in bigL:
        newFreqSet=preFix.copy()
        newFreqSet.add(basePat)
        freqItemList.append(newFreqSet)
        condPattBases=findPrefixPath(basePat,headerTable[basePat][1])
        myCondTree,myHead=createTree(condPattBases,minSup)
        
        if myHead!=None:
            mineTree(myCondTree,myHead,minSup,newFreqSet,freqItemList)
    pass
