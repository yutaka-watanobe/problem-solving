def solve():
    D = [[0,0]]*6
    for i in range(6):
        h, w = sorted(map(int,input().split()))
        D[i] = [h, w]
    D.sort()
    for i in range(0,6,2):
        if D[i] != D[i+1]: return False

    return D[0][0] == D[2][0] and D[0][1] == D[4][0] and D[2][1] == D[4][1]

if solve(): print('yes')
else: print('no')
