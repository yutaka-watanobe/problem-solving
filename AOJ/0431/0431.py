N = int(input())
r = list(map(int, input().split())) # N 個の円盤の半径を記録するリスト
maxr = 0
cnt = 0
for i in range(N - 1, -1, -1):
    if r[i] > maxr:
        cnt += 1
        maxr = r[i]
print(cnt)
