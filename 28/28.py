# Roland Fong
# 7/22/18
# PE 28

i = 1
s = 1
count = 1
while i <= 1001 - 2:
    for j in range(0,4):
        count += i + 1
        s += count
    i += 2
print(s)
