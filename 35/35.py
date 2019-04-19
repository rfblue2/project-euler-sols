# Roland Fong
# 7/28/18
# PE 35

from functools import reduce

def isPrime(n):
    if n <= 1:
        print()
        return False
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return False
    return True

# create set of n digits chosen from digs.
def genSets(digs, n):
    if not n:
        return [[]]
    allSets = []
    for i, d in enumerate(digs):
        sets = genSets(digs, n-1)
        allSets += [[d] + x for x in sets]
    return allSets

# from a list generate the cycles
def genPerms(l):
    if not l:
        return [[]]
    perms = []
    for i in range(len(l)):
        perms.append(l[i:]+l[:i])
    return perms

def listToNum(l):
    return sum(d * (10**i) for i,d in enumerate(l[::-1]))

digs = [1, 3, 7, 9]
circulars = set([2, 3, 5, 7])
for numDig in range(2,7):
    sets = genSets(digs, numDig)
    for s in sets:
        nums = set(listToNum(x) for x in genPerms(s))
        if reduce(lambda x, y: x and y, [isPrime(x) for x in nums]):
            circulars = circulars.union(nums)

print(len(circulars))
