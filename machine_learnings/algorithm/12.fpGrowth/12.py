#!/usr/bin/env python3
#-*- coding: UTF-8 -*-

import fpGrowth

rootNode=fpGrowth.treeNode('pyramid',9,None)    #   这个调用的就是class的__init__函数来声明第一个结点
rootNode.children['eye']=fpGrowth.treeNode('eye',13,None)   #   rootNode的['eye']孩子结点也是新声明的一个treeNode
rootNode.display()
rootNode.children['phoenix']=fpGrowth.treeNode('phoenix',3,rootNode.children['eye'])
rootNode.display()


simpDat=fpGrowth.loadSimpDat()
print(simpDat)
initSet=fpGrowth.createInitSet(simpDat)
print("createTree with this initSet:",initSet)
myFPtree,myHeaderTab=fpGrowth.createTree(initSet,3)
myFPtree.display()

Result_x=fpGrowth.findPrefixPath('x',myHeaderTab['x'][1])
Result_z=fpGrowth.findPrefixPath('z',myHeaderTab['z'][1])
Result_r=fpGrowth.findPrefixPath('r',myHeaderTab['r'][1])
print(Result_x)
print(Result_z)
print(Result_r)
freqItems=[]
Result=fpGrowth.mineTree(myFPtree,myHeaderTab,3,set([]),freqItems)
print(Result)

print("100万记录用FP-growth来处理：\n")
parsedDat=[line.split() for line in open('kosarak.dat').readlines()]
initSet=fpGrowth.createInitSet(parsedDat)
myFPtree,myHeaderTab=fpGrowth.createTree(initSet,100000)
#print(myFPtree,myHeaderTab)
myFreqList=[]
fpGrowth.mineTree(myFPtree,myHeaderTab,100000,set([]),myFreqList)

print(len(myFreqList))
print(myFreqList)

