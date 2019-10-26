#!/usr/bin/env python
#-*- coding:UTF-8 -*-

from numpy import *

def regLeaf(dataSet):
    return mean(dataSet[:,-1])  #   叶结点模型，用目标变量的均值
    pass

def regErr(dataSet):
    return var(dataSet[:,-1])*shape(dataSet)[0]    #   返回总方差，均方差个数
    pass

def loadDataSet(fileName):
    dataMat=[]
    fr=open(fileName)
    for line in fr.readlines():
        curLine=line.strip().split('\t')
        fltLine=list(map(float,curLine))    #   把每行映射成浮点数
        dataMat.append(fltLine)
    return dataMat
    pass

def binSplitDataSet(dataSet,feature,value): #   feature是指特征的下标值，value是阈值
    mat0=dataSet[nonzero(dataSet[:,feature]>value)[0],:][0]
    mat1=dataSet[nonzero(dataSet[:,feature]<=value)[0],:][0]
    return mat0,mat1
    pass

def createTree(dataSet,leafType=regLeaf,errType=regErr,ops=(1,4)):
    feat,val=chooseBestSplit(dataSet,leafType,errType,ops)  #   chooseBestSplit怎样实现
    #feat 最佳特征下标
    #val  最佳特征阈值
    if feat==None:  #  如果没有找到合适的分类特征，直接返回
        return val
    retTree={}  #   树的初始化
    retTree['spInd']=feat   #   树的第一个分类下标
    retTree['spVal']=val    #   树的第一个分类阈值
    lSet,rSet=binSplitDataSet(dataSet,feat,val) #   用特征和阈值把数据集分为两个部分
    retTree['left']=createTree(lSet,leafType,errType,ops)   #   循环对左子集建树
    retTree['right']=createTree(rSet,leafType,errType,ops)  #   循环对右子集建树
    return retTree
    pass

def chooseBestSplit(dataSet,leafType=regLeaf,errType=regErr,ops=(1,4)):
    #   找到最佳的二分切分方式 如果没有找到则返回None
    tolS=ops[0] #   允许的误差下降值
    tolN=ops[1] #   切分的最少样本数
    if len(set(dataSet[:,-1].T.tolist()[0]))==1:    #   如果所有值相等，则直接退出  tolist()  to list
        return None,leafType(dataSet)               #   直接建立叶结点并返回
    #为什么没有考虑所有的类标都是-1：注意，用的是length  即类标set长度为1，可能全为1，也可能全为-1
    
    m,n=shape(dataSet)
    S=errType(dataSet)  #   总方差
    
    bestS=inf       #   初始化
    bestIndex=0
    bestValue=0
    
    for featIndex in range(n-1):                                            #   n-1 为什么不是n  n=3
        for splitVal in set(tuple(dataSet.T.getA()[featIndex])):
            #   splitVal是ex0.txt的第一列数和第二列数的set  第一列只出1.0  第二列好多数  因为是set
            
            #   1.000000	0.409175	1.883180                    从ex0.txt中取的样本示例
            #   1.000000	0.182603	0.063908
            #   1.000000	0.663687	3.042257
            #   1.000000	0.517395	2.305004
            #   1.000000	0.013643	-0.067698
            mat0,mat1=binSplitDataSet(dataSet,featIndex,splitVal)           #   当featIndex为0时，   当featIndex为1时
            if(shape(mat0)[0]<tolN)or(shape(mat1)[0]<tolN):                 #   如果有一个集全的数据过少，则直接用下一个特征分类
                continue
            newS=errType(mat0)+errType(mat1)                                #   分完成的两个数据集的误差和
            if newS<bestS:                                                  #   如果误差和小于上一次迭代的误差和，保存下当前值
                bestIndex=featIndex
                bestValue=splitVal
                bestS=newS
    if(S-bestS)<tolS:                                                       #   如果误差减小不够，则认为分类没有成功，直接返回
        return None,leafType(dataSet)                                       #   直接建立叶结点并返回
    mat0,mat1=binSplitDataSet(dataSet,bestIndex,bestValue)                  #   按找到的特征与阈值进行分类
    if(shape(mat0)[0]<tolN)or(shape(mat1)[0]<tolN):                         #   如果有一个数据集的元素数太小，则认为分类不成功
        return None,leafType(dataSet)                                       #   直接建立叶结点并返回
    return bestIndex,bestValue

def isTree(obj):
    return (type(obj).__name__=='dict')
    pass

def getMean(tree):
    if isTree(tree['right']):
        tree['right']=getMean(tree['right'])
    if isTree(tree['left']):
        tree['left']=getMean(tree['left'])
    return (tree['left']+tree['right'])/2.0
    pass

def prune(tree, testData):
    if shape(testData)[0] == 0:     #   如果testData个数为 0
        return getMean(tree)                                    #if we have no test data collapse the tree
    if (isTree(tree['right']) or isTree(tree['left'])):         #if the branches are not trees try to prune them  如果不是叶结点 用该结点对数据分类，得到两个set
        lSet, rSet = binSplitDataSet(testData, tree['spInd'], tree['spVal'])
    if isTree(tree['left']):        #   递归
        tree['left'] = prune(tree['left'], lSet)
    if isTree(tree['right']):       #   递归
        tree['right'] =  prune(tree['right'], rSet)
    #if they are now both leafs, see if we can merge them
    if not isTree(tree['left']) and not isTree(tree['right']):  #   都不是tree 即当前结点的左右结点已经都为叶子
        lSet, rSet = binSplitDataSet(testData, tree['spInd'], tree['spVal'])
        errorNoMerge = sum(power(lSet[:,-1] - tree['left'],2)) + sum(power(rSet[:,-1] - tree['right'],2))
        treeMean = (tree['left']+tree['right'])/2.0
        errorMerge = sum(power(testData[:,-1] - treeMean,2))
        if errorMerge < errorNoMerge:   #  如果合并之后的误差小于合并之前的误差，那就需要合并了
            print("merging")
            return treeMean
        else:
            return tree
    else:
        return tree
    pass

def linearSolve(dataSet):
    m,n=shape(dataSet)
    X=mat(ones((m,n)))
    Y=mat(ones((m,1)))
    X[:,1:n]=dataSet[:,0:n-1]
    Y=dataSet[:,-1]     #   从dataSet中取出 Y X
    xTx=X.T*X
    if linalg.det(xTx)==0.0:
        raise NameError('This matrix is singular, cannot do inverse,\n\
                        try increasing the second value of ops')
    ws=xTx.I*(X.T*Y)    #   利用Y X 计算回归系数 ws
    return ws,X,Y
    pass

def modelLeaf(dataSet): #   叶结点模型
    ws,X,Y=linearSolve(dataSet)
    return ws           #   回归系数相同 可以认为是同一类
    pass

def modelErr(dataSet):  #   误差定义   会被 chooseBestSplit()函数调用
    ws,X,Y=linearSolve(dataSet)
    yHat=X*ws
    return sum(power(Y-yHat,2))
    pass

def regTreeEval(model,inDat):
    return float(model)
    pass

def modelTreeEval(model,inDat):
    n=shape(inDat)[1]
    X=mat(ones((1,n+1)))
    X[:,1:n+1]=inDat
    return float(X*model)
    pass

def treeForeCast(tree,inData,modelEval=regTreeEval):    #   预测  输入  决策树tree  待判决数据inData  叶子结点类型regTreeEval
    if not isTree(tree):  # 递归结束条件－－如果不是树  即当前这个tree只是一个叶子结点，则把当前这个叶子结点的值返回
        return modelEval(tree,inData)   # modelEval(tree,inData)=float(model)
    if inData[tree['spInd']]>tree['spVal']:     #   递归左树
        if isTree(tree['left']):
            return treeForeCast(tree['left'],inData,modelEval)
        else:
            return modelEval(tree['left'],inData)
    else:                                       #   递归右树
        if isTree(tree['right']):
            return treeForeCast(tree['right'],inData,modelEval)
        else:
            return modelEval(tree['right'],inData)
    pass

def createForeCast(tree,testData,modelEval=regTreeEval):    # 用testData测试tree  testData有m个测试元，返回m个类标
    m=len(testData)
    yHat=mat(zeros((m,1)))
    for i in range(m):
        yHat[i,0]=treeForeCast(tree,mat(testData[i]),modelEval)
    return yHat
    pass

