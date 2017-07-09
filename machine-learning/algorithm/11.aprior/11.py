#!/usr/bin/env python3
import aprior
from numpy import *

dataSet=aprior.loadDataSet()
print("dataSet:",dataSet)

C1=aprior.createC1(dataSet)
print("C1:",C1)

D=list(map(set,dataSet))
print("D:",D)

L1,suppData0=aprior.scanD(D,C1,0.6)
print("L1:",L1)
print("suppData0:",suppData0)

L,suppData=aprior.apriori(dataSet)
print("L:",L)
print("supportData:",suppData)

L,suppData=aprior.apriori(dataSet,minSupport=0.5)
rules1=aprior.generateRules(L,suppData,minConf=0.7)
print("rules1:",rules1)
rules2=aprior.generateRules(L,suppData,minConf=0.5)
print("rules2:",rules2)



