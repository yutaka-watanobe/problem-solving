INF = 2000000000
diff = 0

def update(i, v):
  global diff
  if A[i-1] > A[i]: diff -= 1
  if A[i] > A[i+1]: diff -= 1
  A[i] = v
  if A[i-1] > A[i]: diff += 1
  if A[i] > A[i+1]: diff += 1

def solve():
    global diff
    for i in range(1, N+1):
        if  A[i-1] > A[i]: diff += 1

    if diff == 0: return 0
    q = int(input())
    for i in range(1, q+1):
        a,b = map(int, input().split())
        v1 = A[a]
        v2 = A[b]
        update(a, v2)
        update(b, v1)
        if diff == 0:  return i

    return -1

N = int(input())
A = list(map(int, input().split()))
A.insert(0, -INF)
A.append(INF)
print(solve())

