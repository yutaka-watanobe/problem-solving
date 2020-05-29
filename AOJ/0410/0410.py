import math
S = [0]*20
A = [0]*20
cnt = 0

def lcm(x, y):
    return x // math.gcd(x, y)*y

def rec(p, LCM, sum):
    global cnt
    if  p == N:
        ok = (sum > 0)
        for i in range(N):
            if  LCM >= A[i] and LCM % A[i] == 0:
                if S[i] == False: ok = False
        if ok:
            cnt += 1
        return

    S[p] = True
    rec(p+1, lcm(LCM, A[p]), sum+1)
    S[p] = False
    rec(p+1, LCM, sum)

N = int(input())
A = list(map(int, input().split()))
cnt = 0
rec(0, 1, 0)
print(cnt)

