while True:
    n = int(input())
    if n == 0: break

    totalp = 0
    P = list(map(int, input().split()))
    for p in P:
        totalp += p
    J = list(map(int, input().split()))

    maxv = 0
    J.sort(reverse=True)
    J.append(0); # nazo
    totalj = 0
    t = n
    j = 0
    while t >= 1:
        v = t*(totalj + totalp)
        totalj += J[j]
        maxv = max(v, maxv)
        t = t - 1
        j = j + 1

    print(maxv)
