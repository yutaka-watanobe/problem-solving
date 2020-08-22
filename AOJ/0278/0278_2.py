def min(a, b):
    if a < b: return a
    else: return b

def max(a, b):
    if a > b: return a
    else: return b
    
N = int(input())
for i in range(N):
    x, y, b, p = map(int, input().split())
    print(min(x*b+y*p, (x*max(b,5)+y*max(p,2))*4//5))
