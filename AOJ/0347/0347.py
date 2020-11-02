N = int(input())
A = list(map(int, input().split()))
res = 0.0;
A.sort()

for p4 in range(N - 1):
    p3 = p4 + 1
    p1 = N - 1
    p2 = N - 2
    if p4 == N - 3:
        p2 = p4 - 1
    elif p4 == N - 2:
        p1 = p4 - 2
        p2 = p4 - 1
    res = max(res, 1.0 * \
              (A[p1] + A[p2]) / (A[p3] - A[p4]))
print(res)

