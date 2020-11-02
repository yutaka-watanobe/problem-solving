N = 0
d = []

def isReachable() :
    current = 0
    for i in range(N) :
        if current < 10 * i : return False
        current = max(current, 10 * i + d[i])
        if current >= 10 * N : return True
    return False

N = int(input())
for i in range(N) :
    d.append(int(input()))

if not isReachable() : print("no")
else :
    d.reverse() # 列の要素を逆順に変換する
    if isReachable() : print("yes")
    else : print("no")
