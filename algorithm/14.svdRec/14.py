#!/usr/bin/env python3
#-*- coding: UTF-8 -*-

import svdRec
from numpy import *
Data=svdRec.loadExData()
print(Data)
U,Sigma,VT=linalg.svd(Data)
print("U=",U)
print("Sigma=",Sigma)
print("VT=",VT)

Sig3=mat([[Sigma[0],0,0],[0,Sigma[1],0],[0,0,Sigma[2]]])
Sig5=mat([[Sigma[0],0,0,0,0],[0,Sigma[1],0,0,0],[0,0,Sigma[2],0,0],[0,0,0,Sigma[3],0],[0,0,0,0,Sigma[4]]])
DataWithSig3=U[:,:3]*Sig3*VT[:3,:]
#DataWithSig5=U[:,:]*Sig5*VT[:,:]
print("Data Sigma3 ReConstruct:\n",U[:,:3]*Sig3*VT[:3,:])
#print("Data Sigma5 ReConstruct:\n",DataWithSig5)


myMat=mat(svdRec.loadExData())
print(svdRec.ecludSim(myMat[:,0],myMat[:,4]))
print(svdRec.ecludSim(myMat[:,0],myMat[:,0]))
print(svdRec.cosSim(myMat[:,0],myMat[:,4]))
print(svdRec.cosSim(myMat[:,0],myMat[:,0]))
print(svdRec.pearsSim(myMat[:,0],myMat[:,4]))
print(svdRec.pearsSim(myMat[:,0],myMat[:,0]))

myMat=mat([[4,4,0,2,2],[4,0,0,3,3],[4,0,0,1,1],[1,1,1,2,0],
    [2,2,2,0,0],[1,1,1,0,0],[5,5,5,0,0]])
print(myMat)

recommendResult=svdRec.recommend(myMat,2)
recommendResultWithEclud=svdRec.recommend(myMat,2,simMeas=svdRec.ecludSim)
recommendResultWithPears=svdRec.recommend(myMat,2,simMeas=svdRec.pearsSim)

print(recommendResult)
print(recommendResultWithEclud)
print(recommendResultWithPears)

U,Sigma,VT=linalg.svd(mat(svdRec.loadExData2()))
print(Sigma)
Sig2=Sigma**2
print(sum(Sig2))
print(sum(Sig2)*0.9)

ResultWithSvdEst=svdRec.recommend(myMat,1,estMethod=svdRec.svdEst)
print("ResultWithSvdEst:",ResultWithSvdEst)




