import math
def lcm(x, y):
    return x // math.gcd(x, y) * y

N = int(input())
A = list(map(int, input().split()))
cnt = 0
for bit in range(1, (1 << N)):
    valid = True
    LCM = 1
    for i in range(N):
        if (bit & (1 << i)): LCM = lcm(LCM, A[i])
    for i in range(N):
        if (bit & (1 << i)) == 0:
            if  LCM >= A[i] and LCM % A[i] == 0: valid = False 
    if valid: cnt += 1

print(cnt)

