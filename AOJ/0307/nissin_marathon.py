N, R, T = map(int, input().split())
p = [int(input()) for _ in range(N)]
filled = [0] * R
res = 0
for i in range (1, T + 1) :
    for j in range (N) :
        if filled[(p[j] * i) % R] <= 0 :  res += 1
        else : filled[(p[j] * i) % R] -= 1
    if i > 1 :
        for j in range (N) :
            filled[(p[j] * i) % R] += 1
print(res)
