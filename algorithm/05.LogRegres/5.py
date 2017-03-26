#!/usr/bin/env python

import logRegres
dataArr,labelMat=logRegres.loadDataSet()
weights=logRegres.gradAscent(dataArr,labelMat)

print("dataArr:")
print(dataArr)
print("labelMat:")
print(labelMat)
print("logRegres.gradAscent(dataArr,labelMat):")
print(logRegres.gradAscent(dataArr,labelMat))

from numpy import *

print("weights:")
print(weights)
print("weights.getA()")
print(weights.getA())

logRegres.plotBestFit(weights.getA())

weights=logRegres.stocGradAscent(array(dataArr),labelMat)
logRegres.plotBestFit(weights)
