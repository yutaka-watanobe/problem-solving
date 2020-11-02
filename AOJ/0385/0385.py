INF = 2000000000
diff = 0

def update(i, v):
    global diff
    if A[i - 1] > A[i]: diff -= 1
    if A[i] > A[i + 1]: diff -= 1
    A[i] = v
    if A[i - 1] > A[i]: diff += 1
    if A[i] > A[i + 1]: diff += 1

def sort():
    global diff
    for i in range(1, N + 1):
        if  A[i - 1] > A[i]: diff += 1

    if diff == 0: return 0
    Q = int(input())
    for i in range(1, Q + 1):
        x, y = map(int, input().split())
        v1, v2 = A[x], A[y]
        update(x, v2)
        update(y, v1)
        if diff == 0:  return i

    return -1

N = int(input())
A = list(map(int, input().split()))
A.insert(0, -INF)
A.append(INF)
print(sort())

