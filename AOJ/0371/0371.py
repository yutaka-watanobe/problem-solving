n = int(input())
maxt = 0
t = []
for i in range(n):
    t.append(int(input()))
    if t[i] > maxt : maxt = t[i]

divisors = []
for i in range(1, maxt+1):
    if maxt % i == 0: divisors.append(i)

ans = 0
for a in t:
    for d in divisors:
        if d >= a:
            ans += d - a
            break
print(ans)
