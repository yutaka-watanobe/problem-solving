dst = []

def CWDist(s, e, n) : return (e - s + n) % n
def CCWDist(s, e, n) : return (s - e + n) % n
def CWNext(i, m) : return dst[0] if i == m - 1 else dst[i + 1]
def CCWNext(i, m) : return dst[m-1] if i == 0 else dst[i - 1]
def CWTurn(p, t, e, n) : return CWDist(p, t, n) + CCWDist(t, e, n)
def CCWTurn(p, t, e, n) : return CCWDist(p, t, n) + CWDist(t, e, n)

n,m,p = map(int, input().split())
for i in range(m) :
    dst.append(int(input()))
dst.sort()

s = 0
while s < m :
    if dst[s] > p : break
    s += 1

cwNext = dst[0] if s == m else dst[s]
ccwNext = dst[m - 1] if s == 0 else dst[s - 1]
dist = min(CCWDist(p, cwNext, n), CWDist(p, ccwNext, n))
for i in range(m) :
    dist = min(dist, CWTurn(p, dst[i], CWNext(i,m), n), CCWTurn(p, dst[i], CCWNext(i,m), n))
print(100 * dist)
