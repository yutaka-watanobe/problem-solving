while ( True ): # 無限ループ
    N = int(input())
    if N == 0 : break # データセットの終わり
    ki = list(map(int, input().split()))
    less1Cnt = 0
    zeroCnt = 0
    for k in ki:
        if k <= 1 : less1Cnt += 1
        if k == 0 : zeroCnt += 1
    if N == less1Cnt : print("NA")
    else : print(N - zeroCnt + 1)
