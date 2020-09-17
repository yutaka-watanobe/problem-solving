G = [[1, 2], [-1, 3], [1, -1], [4, 5], [5, 2], [2, 1]] # 地図

while True:
    p = input()
    if S[0] == '#': break
    cur = 0 # A市を出発
    for c in p:
        if cur == -1: break
        cur = G[cur][int(c)]
    print("Yes" if cur == 5 else "No" ) # B市か判定
