def getScore(iwa, yam, a, b, c, d):
    return iwa * a + yam * b + \
        (iwa // 10) * c + (yam // 20) * d;

h1, h2 = map(int, input().split())
k1, k2 = map(int, input().split())
a, b, c, d = map(int, input().split())
hiro = getScore(h1, h2, a, b, c, d)
ken = getScore(k1, k2, a, b, c, d)

if   hiro > ken: print("hiroshi")
elif hiro < ken: print("kenjiro")
else: print("even")
