N = int(input())
p = list(map(int, input().split()))

for i in range(100, 0, -1):
    if i <= len([x for x in p if i <= x]):
        print(i)
        break
