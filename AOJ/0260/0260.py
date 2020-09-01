MAX = 65000
def merge(J, l, m, r):
    T = []*MAX
    for i in range(l, m): T[i] = J[i]
    for i in range(m, r): T[(r-1)-(i-m)] = J[i]
    i = l
    j = r - 1
    for k in range(l, r):
        if  T[i] <= T[j]: J[k] = T[i]; i += 1
        else: J[k] = T[j]; j -= 1

def mergeSort(J, l, r):
    if l+1 >= r: return
    m = (l + r) / 2
    mergeSort(J, l, m)
    mergeSort(J, m, r)
    merge(J, l, m, r)

while True:
    n = int(input())
    if n == 0: break

    totalp = 0
    P = list(map(int, input().split()))
    for p in P:
        totalp += p
    J = list(map(int, input().split()))

    maxv = 0
    J.sort()
    J.append(0); 
    totalj = 0
    for k in range(0, n):
        totalj += J[n - 1 - k]
        maxv = max((n - k) * (totalj + totalp), maxv)

    print(maxv)



