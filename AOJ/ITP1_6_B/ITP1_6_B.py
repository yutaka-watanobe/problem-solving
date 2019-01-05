#     1  2  3  4  5  6  7  8  9 10 11 12 13
# S:  1  2  3  4  5  6  7  8  9 10 11 12 13
# H: 14 15 16 17 18 19 20 21 22 23 24 25 26
# C: 27 28 29 30 31 32 33 34 35 36 37 38 39
# D: 40 41 42 43 44 45 46 47 48 49 50 51 52
cards = list()
suit = ['S', 'H', 'C', 'D']
n = int(input())
for i in range(n):
    s,r = input().split()
    r = int(r)
    if s == "S": cards.append(0 + r)
    elif s == "H": cards.append(13 + r)
    elif s == "C": cards.append(26 + r)
    elif s == "D": cards.append(39 + r)
for i in range(1,53):
    if not (i in cards):
        print(suit[(i-1)//13], (i-1)%13+1)
