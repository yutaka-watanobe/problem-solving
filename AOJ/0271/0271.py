M = 1000000007
N_MAX = 200000
fact = [0] * (N_MAX+1)
word = [0] * N_MAX

def compute(N, H):
    for i in range(N):
        word[i] = i
        
    for i in range(H):
        s, t = map(int, input().split())
        s = s-1
        t = t-1
        word[s], word[t] = word[t], word[s]

    ans = 0
    deleted = []
    inserted = []
    for i in range(N):
        unable = min(word[i], i)
        for j in range(len(deleted)):
            if ( deleted[j] < word[i] ): unable = unable - 1
        for j in range(len(inserted)):
            if ( inserted[j] < word[i] ): unable = unable + 1

        ans += ((word[i] - unable) * fact[N-i-1])%M
        ans %= M

        if ( word[i] != i ):
            deleted.append(i)
            inserted.append(word[i])

    print(ans)

fact[0] = 1

for i in range(1, N_MAX+1): fact[i] = (fact[i-1]*i)%M

while True:
    N = int(input())
    if ( N == 0 ): break
    H = int(input())
    compute(N, H)
