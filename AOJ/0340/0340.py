import copy
N = int(input())
p = list(map(int, input().split()))

ans = (1<<29)
for j in range(0, p[0]+1):
    x = j
    r = copy.copy(p)
    r[0] -= j
    for i in range(N-1):
      y = max(0, r[i])
      r[i] -= y
      r[i+1] -= y
      x += y*2
    ans = min(ans, x + max(0, r[N-1]))

print(ans)
