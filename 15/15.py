#11/20/15
__author__ = 'rfblue2'
import math

def nCr(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)

print(nCr(40,20))