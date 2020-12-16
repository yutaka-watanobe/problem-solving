n = int(input())
maxt = 0
t = []
for i in range(n):
    t.append(int(input()))
    # 間隔が一番長いmaxtを更新
    if t[i] > maxt : maxt = t[i]

# maxtの約数を昇順に列挙 
divisors = []
for i in range(1, maxt+1):
    if maxt % i == 0: divisors.append(i)

ans = 0
for a in t:
    # tを増やしたときに最初に一致する
    # maxtの約数を線形探索 
    for d in divisors:
        if d >= a:
            ans += d - a
            break
print(ans)




