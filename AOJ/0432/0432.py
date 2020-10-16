import copy

def rotate():
    T = copy.deepcopy(G)
    for i in range(N):
        for j in range(N):
            G[j][N-i-1] = T[i][j]

N = int(input())
G = [[' ' for _ in range(N)] for _ in range(N)]

for i in range(N):
    row = input()
    for j in range(N):
        G[i][j] = row[j]

cnt = 4 * 100000
Q = int(input())
for i in range(Q):
    q = int(input());
    cnt += q
cnt %= 4
for i in range(cnt): rotate()

for i in range(N): 
    for j in range(N): print(G[i][j], end='')
    print()
