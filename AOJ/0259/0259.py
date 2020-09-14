while True:
    N = input()
    if int(N) == 0: break
    if len(set(N)) == 1:
        print("NA")
        continue
    cnt = 0
    while N != "6174":
        L = ''.join(sorted(N))
        S = ''.join(reversed(sorted(N)))
        N = str(int(S) - int(L)).zfill(4)
        cnt += 1
    print(cnt)
    
