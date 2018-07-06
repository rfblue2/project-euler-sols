from decimal import *

MAX_DIG = 10000
getcontext().prec = MAX_DIG

# takes n as string
def cycleLength(n):
    n = n[2:] # remove '0.'
    if len(n) < MAX_DIG:
        return 0
    ptr1 = 0
    ptr2 = 50 # assumption that longest match will be greater than this
    while ptr2 < MAX_DIG - ptr1 + 1:
        ptr1 = 0
        ptr2 += 1
        for i in range(ptr2):
            if n[ptr1+i:ptr2] == n[ptr2:ptr2*2-i]:
                return ptr2 - ptr1 + 1
    return -1

largest_i = 0
largest = 0
for i in range(2, 1000):
    l = cycleLength((Decimal(1)/Decimal(i)).to_eng_string())
    if l == -1:
        print("Reached MAX_DIG on d=" + str(i))
        exit()
    if l > largest:
        largest = l
        largest_i = i

print(largest_i) 
