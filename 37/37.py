# Roland Fong
# 8/2/18
# PE 37
import math

def isPrime(p):
    if p <= 1:
        return False
    for i in range(2,int(math.sqrt(p)+1)):
        if p % i == 0:
            return False
    return True

def ltrunc(p):
    if not isPrime(p):
        return False
    if p < 10:
        return True
    return ltrunc(p % (10 ** int(math.log10(p))))

def rtrunc(p):
    if not isPrime(p):
        return False
    if p < 10:
        return True
    return rtrunc(int(p/10))

def truncatable(n):
    return ltrunc(n) and rtrunc(n)
    
count = 0
s = 0
i = 13
while count < 11:
    if truncatable(i):
        s += i
        count += 1
    i += 1

print(s)
