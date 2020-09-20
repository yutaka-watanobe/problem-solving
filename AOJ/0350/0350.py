def gcd(x, y):
    return gcd(y, x % y) if y else x

def printV(x, y):
    g = gcd(x, y)
    print(str(x // g) + "/" +  str(y // g))

S = input()
o = S.find('.')
p = S.find('(')
d = len(S) - o - 1

if p == -1:
    all = S[0:o] + S[o + 1:len(S)]
    printV(int(all), 10**d)
else:
    sub = S[0:o] + S[o + 1:p]
    all = sub + S[p + 1:len(S) - 1]
    l = p - o - 1
    d -= 2 # for ()
    printV(int(all) - int(sub), 10**d - 10**l)
