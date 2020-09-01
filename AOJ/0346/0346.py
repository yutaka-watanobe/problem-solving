N = 12
e = list(map(int, input().split()))
for i in range(N -1):
    minj = i
    for j in range(i, N):
        if  e[j] < e[minj]: minj = j
    e[minj], e[i] = e[i], e[minj]
print("yes" if e[0] == e[3] and e[4] == e[7] and e[8] == e[11] else "no")



