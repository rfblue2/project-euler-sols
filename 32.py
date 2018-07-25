# Roland Fong
# 7/24/18
# PE 32

digits = ['1', '2', '3', '4', '5', '6', '7', '8', '9']
length = len(digits)
pandigitals = set()

def flatMap(f, l):
    return [y for i,x in enumerate(l) for y in f(i,x)]

def perms(digs):
    if digs == []:
        return [[]]
    return flatMap(lambda i,x: [[x] + y for y in perms(digs[:i]+digs[i+1:])], digs)

allPerms = perms(digits)

for digs in allPerms:
    for i in range(1, length - 1):
        for j in range(i+1, length):
            a = int(''.join(digs[:i]))
            b = int(''.join(digs[i:j]))
            c = int(''.join(digs[j:]))
            if a * b == c:
                pandigitals.add(c)

print(sum(pandigitals))


