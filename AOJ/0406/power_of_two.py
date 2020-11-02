N = int(input())
p = 0
while N > 1 :
    N = N >> 1
    p = p + 1
print(1 << p)
