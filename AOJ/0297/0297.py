N = int(input())
for i in range(N):
    K,P = map(int, input().split())
    print((K-1)%P + 1)
