n,c = map(int, input().split())
p = list(map(int, input().split()))
v = 0
for i in p:
    v += i
ans = v//(n+1)
if v % (n+1) > 0: ans += 1
print(ans)
