N, C = map(int, input().split())
P = list(map(int, input().split()))
sum = 0
for p in P:
    sum += p
ans = sum // (N + 1)
if v % (N + 1) > 0: ans += 1
print(ans)
