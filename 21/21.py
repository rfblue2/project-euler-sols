import math

def d(n):
    s = 0
    for i in range(1,n):
        if n % i == 0:
            s += i
    return s

total = 0
for i in range(1,10000):
    divsum = d(i)
    if i == d(divsum) and i != divsum:
        total += i 

print(total)
