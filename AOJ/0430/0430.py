N = int(input())
X = list(map(int, input().split()))
x = X[0]
R = x
L = x
for i in range(1, N):
    R = max(R, X[i])
    L = min(L, X[i])
minv = min(R - x, x - L)
maxv = max(R - x, x - L)
print(minv * 2 + maxv)
