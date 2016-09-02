#11/20/15
__author__ = 'rfblue2'

num = pow(2,1000)

sum = 0
i = 0
while num > 0:
    temp = num % pow(10, i)
    num = num - temp
    digit = temp / pow(10, i - 1)
    print(digit)
    sum += digit
    i += 1

print(sum)
