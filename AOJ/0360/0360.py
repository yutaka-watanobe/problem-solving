def overlap(a, b, c, d):
    if d <= a:  return False
    if b <= c:  return False
    return True

a, b = map(int, input().split())
res = 0
for i in range(int(input())):
    s, t = map(int, input().split())
    if overlap(a, b, s, t): res = 1
print(res)

