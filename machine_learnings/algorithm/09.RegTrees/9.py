#!/usr/bin/env python3
#-*- coding:UTF-8 -*-

import regTrees
from numpy import *


testMat=mat(eye(4))
print(testMat)
mat0,mat1=regTrees.binSplitDataSet(testMat,1,0.5)#1为特征下标，0.5为阈值
print("mat0=\n",mat0)
print("mat1=\n",mat1)

myDat=regTrees.loadDataSet('ex00.txt')
#print(myDat)
myMat=mat(myDat)
print("myMat size:",shape(myMat))
#print(myMat)
print(regTrees.createTree(myMat))

print("ex0.txt")
myDat1=regTrees.loadDataSet('ex0.txt')
myMat1=mat(myDat1)
print(shape(myMat1))#200 3
print(regTrees.createTree(myMat1))
#建树完成
myDat2=regTrees.loadDataSet('ex2.txt')
myMat2=mat(myDat2)
print(regTrees.createTree(myMat2))
myTree=regTrees.createTree(myMat2,ops=(0,1))
myDatTest=regTrees.loadDataSet('ex2test.txt')
myMat2Test=mat(myDatTest)
regTrees.prune(myTree,myMat2Test)
print(myTree)

print("分段函数表示：")
myMat2=mat(regTrees.loadDataSet('exp2.txt'))
print(regTrees.createTree(myMat2,regTrees.modelLeaf,regTrees.modelErr,(1,10)))


trainMat=mat(regTrees.loadDataSet('bikeSpeedVsIq_train.txt'))
testMat=mat(regTrees.loadDataSet('bikeSpeedVsIq_test.txt'))
myTree=regTrees.createTree(trainMat,ops=(1,20))
yHat=regTrees.createForeCast(myTree,testMat[:,0])
print(corrcoef(yHat,testMat[:,1],rowvar=0)[0,1])

ws,X,Y=regTrees.linearSolve(trainMat)
print(ws)
for i in range(shape(testMat)[0]):
    yHat[i]=testMat[i,0]*ws[1,0]+ws[0,0]
print(corrcoef(yHat,testMat[:,1],rowvar=0)[0,1])

from Tkinter import *
root=Tk()
myLabel=Label(root,text="Hello World")
myLabel.grid()
root.mainloop()






