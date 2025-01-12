def val(w):
    return sum(ord(c) - 64 for c in w)

# highest value word is less than 21st triangle #
triangles = [int(n*(n+1)/2) for n in range(1,21)]

with open('0042_words.txt', 'r') as f:
    words = f.read().split(",")
    print(sum(1 if val(w.strip('"')) in triangles else 0 for w in words))



