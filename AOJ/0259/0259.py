while True:
    N = input()
    if int(N) == 0: break
    if len(set(N)) == 1:
        print("NA")
        continue
    cnt = 0
    while N != "6174":
        L = ''.join(reversed(sorted(N)))  # 降順にソート
        S = ''.join(sorted(N))            # 昇順にソート
        N = str(int(L) - int(S)).zfill(4)
        cnt += 1
    print(cnt)
    
