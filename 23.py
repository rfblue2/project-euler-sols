def isAbundant(n):
    s = 0
    for i in range(1,n):
        if n % i == 0:
            s += i
    return s > n

MAX = 28123

abundants = [None] * MAX

total = 0
for i in range(1,MAX):
    abundants[i] = isAbundant(i)
    isSummable = False 
    for j in range(1,i):
        # if i is sum of two abundant numbers
        if abundants[j] and abundants[i - j]:
            isSummable = True
            break
    if not isSummable:
        total += i

print(total)

