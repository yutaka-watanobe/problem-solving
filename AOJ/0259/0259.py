while True:
    num = input()
    if int(num) == 0: break
    if len(set(num)) == 1:
        print("NA")
        continue
    cnt = 0
    while num != "6174":
        cnt += 1
        L = ''.join(sorted(num))
        S = ''.join(reversed(sorted(num)))
        num = str(int(S) - int(L)).zfill(4)
    print(cnt)
    
