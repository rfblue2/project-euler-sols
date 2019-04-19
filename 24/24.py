digits = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

# smaller is a list of smaller permutations of size n-1
# returns a list of permutations with a single digit (d) added to front
def generateTops(d, smaller):
    if len(smaller) == 0:
        return [d]
    return [d+x for x in smaller]

def generate(digs):
    perms = []
    for i in range(0, len(digs)):
        digit = digs[i]
        rest = digs[0:i]+digs[i+1:]
        perms += generateTops(digit, generate(rest))
    return perms

permutations = generate(digits)
list.sort(permutations)
print(permutations[int(1e6)-1])

