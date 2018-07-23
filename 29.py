# Roland Fong
# 7/22/18
# PE 29

# Brute force using list comprehension to mimic a flatmap.  Fun, but never code this way.
print(len(set([y for x in range(2, 101) for y in map(lambda a: x ** a, range(2, 101))])))

