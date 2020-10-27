while True:
    N = input()
    if int(N) == 0: break
    if len(set(N)) == 1:
        print("NA")
        continue
    cnt = 0
    while N != "6174":
        L = ''.join(reversed(sorted(N)))  # 
        S = ''.join(sorted(N))             
        N = str(int(L) - int(S)).zfill(4)
        cnt += 1
    print(cnt)
    
