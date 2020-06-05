def next(i):
    return ((N-i-1)+N)%N

def getState(G, i, j):
    return  G[i][j] == G[i][next(j)] and  G[i][j] == G[next(i)][j] and G[i][j] == G[next(i)][next(j)]

def getInit(N, G):
    dcnt = 0
    for i in range(N//2):
        for j in range(N//2):
            if not getState(G, i, j): dcnt += 1
    return dcnt

C, N = map(int, input().split())
G = [[0]*N]*N

for i in range(N):
    str = input()
    j = 0
    for ch in str:
        G[i][j] = int(ch)
        j += 1

ans = 0
dcnt = getInit(N, G)
if dcnt == 0: ans += 1

for i in range(C-1):
    k = int(input())
    for j in range(k):
        r, c = map(int, input().split())
        r -= 1
        c -= 1
        pre = getState(G, r, c)
        G[r][c] = 0 if G[r][c]=='1' else 1
        post = getState(G, r, c)
        if not pre and post: dcnt -= 1
        elif  pre and not post: dcnt += 1
        if dcnt == 0: ans += 1

print(ans)
