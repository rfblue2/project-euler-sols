# Roland Fong
# 7/26/18
# PE 34

facts = {
    0: 1, 1: 1, 
    2: 2, 3: 6,
    4: 24, 5: 120,
    6: 720, 7: 5040,
    8:40320, 9: 362880,
}

def curious(n):
    i = 0
    digsum = 0
    while 10 ** i <= n:
        dig = int(n / (10**i)) % 10
        digsum += facts[dig]
        if digsum > n:
            return False
        i += 1
    return n == digsum

print(sum(filter(curious, range(3, 100000))))

