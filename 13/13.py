#11/20/15
__author__ = 'rfblue2'

dat = open('data.txt')
nums = dat.readlines()

sum = 0
for num in nums:
    sum += int(num)

print(sum)