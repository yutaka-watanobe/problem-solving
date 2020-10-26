N = int(input())
A = list(map(int, input().split()))
maxr = 0
cnt = 0
for i in range(N-1, -1, -1):
    if A[i] > maxr:
        cnt += 1
        maxr = A[i]
print(cnt)
