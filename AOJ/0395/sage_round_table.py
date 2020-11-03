N = int(input())
a = list(map(int, input().split()))
w = list(map(int, input().split()))

INF = 100000
rmin = INF
lmin = INF

for i in range(N):
    if a[i] == 1:
        rmin = min(rmin, w[i])
    else :
        lmin = min(lmin, w[i])
    
if  rmin == INF or lmin == INF : print(0);
else : print(rmin + lmin);
