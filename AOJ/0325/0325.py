N = 6
def solve():
    D = [[0,0]] * N
    for i in range(N):
        h, w = sorted(map(int,input().split()))
        D[i] = [h, w]
    # バブルソート
    for i in range(N - 2):
        j = N - 2
        while j >= i:
            if D[j] > D[j + 1]: D[j], D[j + 1] = D[j + 1], D[j]
            j -= 1
    for i in range(0, N, 2):
        if D[i] != D[i + 1]: return False

    return D[0][0] == D[2][0] and D[0][1] == D[4][0] and D[2][1] == D[4][1]

print("yes" if solve() else "no")


