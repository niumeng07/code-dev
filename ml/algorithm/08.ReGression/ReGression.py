#!/usr/bin/env python
# -*- coding: utf-8 -*-

from numpy import *

def loadDataSet(fileName):
    numFeat=len((open(fileName)).readline().split('\t'))-1
    dataMat=[]
    labelMat=[]
    fr=open(fileName)
    for line in fr.readlines():
        lineArr=[]
        curLine=line.strip().split('\t')
        for i in range(numFeat):
            lineArr.append(float(curLine[i]))
        dataMat.append(lineArr)
        labelMat.append(float(curLine[-1]))
    return dataMat,labelMat

#计算最佳拟合直线
def standRegres(xArr,yArr):
    xMat=mat(xArr)
    yMat=mat(yArr).T
    if linalg.det(xMat.T*xMat)==0.0:
        print("This matrix is singular, cannot do inverse")
        return
    ws=(xMat.T*xMat).I*(xMat.T*yMat)
    return ws
#给定x空间中的任意一点，计算出对应的预测值yHat
def lwlr(testPoint,xArr,yArr,k=1.0):
    xMat=mat(xArr)
    yMat=mat(yArr).T
    m=shape(xMat)[0]
    weights=mat(eye((m)))#eye 产生m*m的单位array，对角为1，其它为0
    for j in range(m):
        diffMat=testPoint-xMat[j,:] #与每一个训练数据求差
        weights[j,j]=exp((diffMat*diffMat.T)/(-2.0*(k**2)))#高斯核函数
    xTx=xMat.T*(weights*xMat)
    
    if linalg.det(xTx)==0.0:
        print("this matrix is singular, cannot do inverse")
        return
    ws=xTx.I*(xMat.T*(weights*yMat))#计算系数w
    #print("ws=",ws)
    return testPoint*ws
    
def lwlrTest(testArr,xArr,yArr,k=1.0):
    m=shape(testArr)[0]
    yHat=zeros(m)
    for i in range(m):
        yHat[i]=lwlr(testArr[i],xArr,yArr,k)
    return yHat

def rssError(yArr,yHatArr):
    return ((yArr-yHatArr)**2).sum()

def ridgeRegres(xMat,yMat,lam=0.2):
    xTx=xMat.T*xMat
    denom=xTx+eye(shape(xMat)[1])*lam
    if linalg.det(denom)==0.0:
        print("This matrix is singular, cannot do inverse.")
        return
    ws=denom.I*(xMat.T*yMat)
    return ws
    pass    

def ridgeTest(xArr,yArr):
    xMat=mat(xArr)
    yMat=mat(yArr).T
    yMean=mean(yMat,0)
    yMat=yMat-yMean
    xMeans=mean(xMat,0)
    xVar=var(xMat,0)
    xMat=(xMat-xMeans)/xVar
    numTestPts=30       #  numTestPts
    wMat=zeros((numTestPts,shape(xMat)[1]))
    for i in range(numTestPts):
        ws=ridgeRegres(xMat,yMat,exp(i-10))#lam=e-9,e-8,e-7,...,e-1,e0,e,e2,...,e20
        wMat[i,:]=ws.T
    return wMat

from time import sleep
import json
import urllib.request
def searchForSet(retX,retY,setNum,yr,numPce,origPrc):
    sleep(10)
    myAPIstr='get from code.google.com'
    searchURL = 'https://www.googleapis.com/shopping/search/v1/public/products?key=%s&country=US&q=lego+%d&alt=json' % (myAPIstr, setNum)
    
    pg=urllib.request.urlopen(searchURL)
    retDict=json.loads(pg.read())
    for i in range(len(retDict['items'])):
        try:
            currItem=retDict['items'][i]
            if currItem['product']['condition']=='new':
                newFlag=1
            else:
                newFlag=0
            listOfInv=currItem['product']['inventories']
            for item in listOfInv:
                sellingPrice=item['price']
                if sellingPrice>origPrc*0.5:
                    print("%d\t%d\t%d\t%f\t%f"%(yr,numPce,newFlag,origPrc,sellingPrice))
                    retX.append([yr,numPce,newFlag,origPrc])
                    retY.append([sellingPrice])
        except:
            print('problem with item %d'%i)
        code
def setDataCollect(retX,retY):
    searchForSet(retX,retY,8288,2006,800,49.99)
    searchForSet(retX,retY,10030,2002,3096,269.99)
    searchForSet(retX,retY,10179,2007,5195,499.99)
    searchForSet(retX,retY,10181,2007,3428,199.99)
    searchForSet(retX,retY,10189,2008,5922,299.99)
    searchForSet(retX,retY,10196,2009,3263,249.99)

