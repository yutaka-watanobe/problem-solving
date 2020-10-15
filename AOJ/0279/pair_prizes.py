while ( True ):
    n = int(input())
    if n == 0 : break
    ki = list(map(int, input().split()))
    less1Cnt = 0
    zeroCnt = 0
    for k in ki:
        if k <= 1 : less1Cnt += 1
        if k == 0 : zeroCnt += 1
    if n == less1Cnt : print("NA")
    else : print(n - zeroCnt + 1)
