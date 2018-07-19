# Roland Fong
# 9/18/18
# PE 27
def isPrime(x):
    if x <= 1:
        return False
    for i in range(2,x):
        if x % i == 0:
            return False
    return True

A = 999
B = 1000
best_n = 0
best = (0,0)
for a in range(-A,A+1):
    for b in range(-B,B+1):
        n = 0
        while True:
            if isPrime(n*n + a*n + b):
                n += 1
            elif n > best_n:
                best_n = n
                best = (a,b)
                break
            else:
                break
print(best[0]*best[1])
