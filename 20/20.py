def fact(i):
    if i <= 1:
        return 1
    return fact(i-1)*i

s = 0
for c in str(fact(100)):
    s += int(c)
    
print(s)
