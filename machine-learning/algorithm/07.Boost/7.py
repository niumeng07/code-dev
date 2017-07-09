#!/usr/bin/env python

import boost
from numpy import *


D=mat(ones((5,1))/5)
dataMat,classLabels=boost.loadSimpData()
boost.buildStump(dataMat,classLabels,D)

classifierArray=boost.adoBoostTrainDS(dataMat,classLabels,30)
print(classifierArray)
print('----classify result:')
print(boost.adaClassify([0,0],classifierArray))
print(boost.adaClassify([[0,0],[5,5]],classifierArray))

dataArr,labelArr=boost.loadDataSet('horseColicTraining2.txt')
classifierArray=boost.adoBoostTrainDS(dataArr,labelArr,10)
testArr,testLabelArr=boost.loadDataSet('horseColicTest2.txt')
prediction10=boost.adaClassify(testArr,classifierArray)

errArr=mat(ones((67,1)))
errArr[prediction10!=mat(testLabelArr).T].sum()
print(errArr)