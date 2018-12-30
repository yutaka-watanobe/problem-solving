H, A, B = map(int, input().split())
cnt = 0;
for i in range(A, B+1):
    cnt += (H % i == 0 )
print(cnt)
