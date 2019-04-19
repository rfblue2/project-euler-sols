# Roland Fong
# 7/22/18
# PE 30

# Super inefficient silly one-liner
print(sum(filter(lambda i: i == sum(int(x)**5 for x in str(i)), range(2, 9**5 * 6))))

