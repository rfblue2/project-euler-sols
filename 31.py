# Roland Fong
# 7/23/18
# PE 31

coin_vals = [1, 2, 5, 10, 20, 50, 100, 200]
    
def pathsToSum(n, vals):
    if n <= 0:
        return [[]]
    valid = [i for i in vals if n-i >= 0]
    return [x for v in valid for x in [[v] + p for p in pathsToSum(n-v, [y for y in valid if y >= v])]]

print(len(pathsToSum(200, coin_vals)))

