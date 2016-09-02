#11/20/15
__author__ = 'rfblue2'

def collatz(seed):
    return op(seed, 0)

def op(num, count):
    count += 1
    if num == 1:
        return count
    else:
        if num % 2 == 0:
            return op(num / 2, count)
        else:
            return op(3 * num + 1, count)

largest = 0
index = 0
for i in range(1,999999):
    c = collatz(i)
    if c > largest:
        largest = c
        index = i
        print('new largest ' + str(i) + ': ' + str(c))