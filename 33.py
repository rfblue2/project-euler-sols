# Roland Fong
# 7/25/18
# PE 33

fracs = []
def areEqual(num, denom, newNum, newDenom):
    if newDenom == 0:
        return False
    return abs(float(num)/float(denom) - float(newNum)/float(newDenom)) < 1e-6

for num in range(10, 99):
    for denom in range(num+1, 100):
        n1 = int(num/10)
        n2 = int(num%10)
        d1 = int(denom/10)
        d2 = int(denom%10)
        if n1 == d2 and areEqual(num, denom, n2, d1):
            fracs.append((n2, d1))
        if n2 == d1 and areEqual(num, denom, n1, d2):
            fracs.append((n1, d2))

print(fracs)

