N = int(input())
for i in range(N): # N 回繰り返す
    K,P = map(int, input().split())
    print((K - 1) % P + 1)
