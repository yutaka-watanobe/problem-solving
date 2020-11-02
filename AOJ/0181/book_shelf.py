def isStorable( m, n, w, width ):
    row = 1
    c = 0
    i = 0
    while i < n :
        if c + w[i] <= width :
            c += w[i]
            i += 1
        elif row < m :
            c = 0
            row += 1
        else : return False
    return True

while ( True ):
    m,n = map(int, input().split())
    if m == 0 and n == 0 : break
    w = []
    for i in range(n) : w.append(int(input()))

    minw = 1
    maxw = 1500000
    if not isStorable(m, n, w, maxw) : print("NA")
    
    while maxw > minw :
        mid = int((maxw + minw) / 2)
        if isStorable(m, n, w, mid) : maxw = mid
        else : minw = mid + 1
    print(minw)
