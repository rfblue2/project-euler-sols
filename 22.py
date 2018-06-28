names = []

def score(name):
    s = 0 
    for c in name:
        s += ord(c) - 64
    return s

with open("names.txt") as f:
    names = [x[1:len(x)-1] for x in f.readline().split(',')]
    list.sort(names)
    total = 0
    for i in range(0,len(names)):
        total += score(names[i]) * (i+1) 

print(total)
        
