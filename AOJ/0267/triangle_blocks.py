while True:
    N = int(input())
    if N == 0 : break

    b = list(map(int, input().split()))
    cnt = 0
    while cnt <= 10000 :
        # 三角形になっているかを判定する
        isTriangle = True 
        if b[0] != 1 : isTriangle = False
        for i in range( 1, len(b) ) :
            if b[i] != b[i - 1] + 1 :
                isTriangle = False
                break
        if isTriangle : break

        # ブロックの数が１より多い列で新しい列を作る
        new_column = len(b)
        tmp = []
        for num in b :
            if num > 1 : tmp.append(num - 1)
        b = tmp
        b.append(new_column)

        cnt += 1
    if cnt <= 10000 : print(cnt)
    else : print(-1)
    
