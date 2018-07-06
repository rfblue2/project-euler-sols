import math

def countDig(n):
    return int(math.log(n) / math.log(10)) + 1

found = False
f1 = 1
f2 = 1
idx = 3
while not found:
    f3 = f1 + f2
    if countDig(f3) >= 1000:
        found = True
        print(idx)
    f1 = f2
    f2 = f3
    idx += 1
     
