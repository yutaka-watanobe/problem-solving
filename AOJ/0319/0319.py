N = int(input())
p = list(map(int, input().split()))
p = sorted(p)
p.reverse()
ans = 0
for i in range(0, N):
    if p[i] >= i + 1: ans = i + 1
print(ans)
