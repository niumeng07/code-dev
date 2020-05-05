import os, sys

l1 = [1,2,3,4,5,6,10]
l2 = [4,2,5,2,1,6,10,11,12]

def f1():
    suma = 0.0
    sum1 = sum(l1)
    sum2 = sum(l2)
    print sum1*sum2

def f2():
    suma = 0.0
    for i in l1:
        sumaa = 0.0
        for j in l2:
            sumaa += i*j
        suma += sumaa
    print suma

f1()
f2()
