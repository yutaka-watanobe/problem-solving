N = int(input())
A, B, C =list(map(int, input().split())), list(map(int, input().split())), list(map(int, input().split()))
D = set(A[1:] + B[1:] + C[1:])
ans = 0
for e in D:
    if(e not in A[1:] and e in C[1:]) or (e in B[1:] and e in C[1:]):
        ans += 1
print(ans)
