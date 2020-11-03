N = int(input())
x = list(map(int,input().split()))
print(max(x) - int((min(x) + max(x)) / 2))
