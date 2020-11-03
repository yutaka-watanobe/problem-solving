N = int(input())
a = list(map(int, input().split()))
res = 0.0;
a.sort()

for D in range(N - 1):
    C = D + 1
    A = N - 1
    B = N - 2
    if D == N - 3:
        B = D - 1
    elif D == N - 2:
        A = D - 2
        B = D - 1
    res = max(res, 1.0 * \
              (a[A] + a[B]) / (a[C] - a[D]))
print(res)

