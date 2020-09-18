N = int(input())
a = list(map(int, input().split()))
w = list(map(int, input().split()))
table = [0] * N
sat = [False] * N
ans = 1000 * N;

def rec(p):
    global ans
    if p == N:
        sum = 0
        for i in range(N):
            if a[table[i]] == 0 and a[table[(i - 1 + N) % N]] == 1 or \
               a[table[i]] == 1 and a[table[(i + 1) % N]] == 0: 
                sum += w[table[i]]
        ans = min(sum, ans)
        return

    for i in range(N):
        if sat[i]: continue
        sat[i] = True
        table[p] = i
        rec(p+1)
        sat[i] = False

rec(0)
print(ans)
