n,k = map(int, input().split())
res = 0
row = 1
w = 0
while n >= row :
    if row * k >= w :
        res += 1
        w += row
        n -= row
    elif n >= row + 1 : row += 1
    else : break
print(res)
