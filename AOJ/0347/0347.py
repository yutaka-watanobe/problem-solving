n = int(input())
S = list(map(int, input().split()))
res = 0.0;
S.sort()

for d in range(n-1):
    c = d+1
    a = n-1
    b = n-2
    if d == n-3:
        b = d-1
    elif d == n-2:
        a = d-2
        b = d-1
    res = max(res, 1.0*(S[a]+S[b])/(S[c]-S[d]))

print(res)

