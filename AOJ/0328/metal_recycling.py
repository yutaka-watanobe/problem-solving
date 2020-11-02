PMAX = 100000
N = int(input())
T = [0 for i in range(2 * PMAX + 20)]
for i in range(N):
    ab = sum(map(int, input().split()))
    T[ab] += 1

for i in range(2 * PMAX + 20 - 1):
    T[i + 1] += T[i] // 2
    T[i] %= 2
    if T[i] > 0 : print(i, 0)
