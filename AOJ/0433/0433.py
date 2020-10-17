P = {"RBYG", "RGBY", "RYGB", "YGRB", "YBGR", "YRBG", \
     "BYRG", "BGYR", "BRGY", "GBRY", "GYBR", "GRYB"};

c1, c2 = input().split()
n = int(input());
for i in range(n):
    x, y = map(int, input().split())
    x %= 4
    y %= 2
    if y == 1: x = 3 - x
    for p in P:
        if p[0] == c1 and p[1] == c2:
            print(p[x])
            break
        
        
