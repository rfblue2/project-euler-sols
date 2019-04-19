import math

def numToList(n):
    l = []
    for i in range(int(math.log10(n)) + 1):
        l.append(n % 10)
        n = int(n / 10)
    return l

def isSymm(l):
    return l == list(reversed(l))

# base 10 to base 2 list
def tenToTwo(n):
    l = []
    while n > 0:
        l.append(n % 2)
        n = int(n/2)
    return l

total = 0
for i in range(1, 1000000):
    if isSymm(numToList(i)):
        if isSymm(tenToTwo(i)):
            total += i

print(total)
