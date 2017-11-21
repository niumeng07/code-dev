#!/usr/bin/env python3
#-*- coding: UTF-8 -*-
from numpy import *
from numpy import linalg as la

def loadExData():
    return [[1,1,1,0,0],
        [2,2,2,0,0],
        [1,1,1,0,0],
        [5,5,5,0,0],
        [1,1,0,2,2],
        [0,0,0,3,3],
        [0,0,0,1,1]]
    pass

def ecludSim(inA,inB):
    return 1.0/(1.0+la.norm(inA-inB))
    pass

def pearsSim(inA,inB):
    if len(inA)<3:
        return 1.0
    return 0.5+0.5*corrcoef(inA,inB,rowvar=0)[0][1]
    pass

def cosSim(inA,inB):
    num=float(inA.T*inB)
    denom=la.norm(inA)*la.norm(inB)
    return 0.5+0.5*(num/denom)
    pass

def standEst(dataMat,user,simMeas,item):
    n=shape(dataMat)[1]
    simTotal=0.0
    ratSimTotal=0.0
    for i in range(n):
        userRating=dataMat[user,i]
        if userRating==0:
            continue
        overLap=nonzero(logical_and(dataMat[:,item].A>0,dataMat[:,i].A>0))[0]
        if len(overLap)==0:
            similarity=0
        else:
            similarity=simMeas(dataMat[overLap,item],dataMat[overLap,i])
        simTotal+=similarity
        ratSimTotal+=similarity*userRating
    if simTotal==0:
        return 0
    else:
        return ratSimTotal/simTotal
    pass

def recommend(dataMat,user,N=3,simMeas=cosSim,estMethod=standEst):
    unratedItems=nonzero(dataMat[user,:].A==0)[1]
    if len(unratedItems)==0:
        return "You Rated Everything."
    itemScores=[]
    for item in unratedItems:
        estimatedScore=estMethod(dataMat,user,simMeas,item)
        itemScores.append((item,estimatedScore))
    return sorted(itemScores,key=lambda jj:jj[1],reverse=True)[:N]
    pass

def loadExData2():
    return[[0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 5],
           [0, 0, 0, 3, 0, 4, 0, 0, 0, 0, 3],
           [0, 0, 0, 0, 4, 0, 0, 1, 0, 4, 0],
           [3, 3, 4, 0, 0, 0, 0, 2, 2, 0, 0],
           [5, 4, 5, 0, 0, 0, 0, 5, 5, 0, 0],
           [0, 0, 0, 0, 5, 0, 1, 0, 0, 5, 0],
           [4, 3, 4, 0, 0, 0, 0, 5, 5, 0, 1],
           [0, 0, 0, 4, 0, 4, 0, 0, 0, 0, 4],
           [0, 0, 0, 2, 0, 2, 5, 0, 0, 1, 2],
           [0, 0, 0, 0, 5, 0, 0, 0, 0, 4, 0],
           [1, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0]]
    pass

def svdEst(dataMat,user,simMeas,item):
    n=shape(dataMat)[1]
    simTotal=0.0
    ratSimTotal=0.0
    U,Sigma,VT=la.svd(dataMat)
    Sig4 = mat(eye(4)*Sigma[:4]) #arrange Sig4 into a diagonal matrix
    xformedItems = dataMat.T*U[:,:4]*Sig4.I  #create transformed items
    for j in range(n):
        userRating = dataMat[user,j]
        if userRating==0 or j==item:
            continue
        similarity = simMeas(xformedItems[item,:].T,xformedItems[j,:].T)
        print("the %d and %d similarity is: %f"%(item, j, similarity))
        simTotal += similarity
        ratSimTotal += similarity*userRating
    if simTotal==0:
        return 0
    else:
        return ratSimTotal/simTotal
    pass



