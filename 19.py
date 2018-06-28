def isleap(y):
    return y % 4 == 0 and y % 100 != 0 or y % 400 == 0

count = 0
dow = 1 # 1 = Mon, 7 = Sun
for y in range(1900, 2000+1):
    for m in range(1, 12+1):
        days = 30 if m in [4,6,9,11] else 31
        if m == 2:
            days = 29 if isleap(y) else 28
        for d in range(1,days+1):
            if d == 1 and dow == 7 and y != 1900:
                count += 1
            dow = dow % 7 + 1
print(count)
