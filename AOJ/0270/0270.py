N, Q = list(map(int, input().split()))
C = list(map(int, input().split()))

M = max(C) + 1
T = [0]*(M)
for v in C: T[v] = 1

L = [0]*(M)
m = 0
for i in range(M):
    L[i] = m
    if T[i] : m = i

for i in range(Q):
    q = int(input())
    maxv = 0
    cur = m
    while 0 < cur:
      p = cur % q
      maxv = max(maxv, p)
      if cur - p < 0:  break
      cur = L[cur - p]
    print(maxv)
