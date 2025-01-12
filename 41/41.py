digits = [str(x) for x in range(7,0,-1)]

def gen(l):
    if len(l) == 1:
        yield l[0]
    else:
        for i in range(0,len(l)):
            d = l[i]
            for n in gen(l[:i]+l[i+1:]):
                yield d + n

def is_prime(n):
    # Edge cases
    if n <= 1:
        return False
    if n <= 3:
        return True

    # Check for factors from 5 to sqrt(n)
    i = 2
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 1

    return True 

gg = gen(digits)

for i in gg:
    if is_prime(int(i)):
        print("is prime:")
        print(i)
        break


