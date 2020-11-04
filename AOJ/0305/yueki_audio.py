# 円弧と線分の番号から観測点の番号へ変換する
def calcID(r, t) :
    return r + 5 * t

n = int(input())
for i in range(n):
    r,t = map(int, input().split())
    onR = r % 100 == 0
    onT = t % 30 == 0
    r = r // 100
    t = t // 30
    if onR and onT : print(calcID(r, t))
    elif onR : print('{0} {1}'.format(calcID(r, t), calcID(r, t + 1)))
    elif onT : print('{0} {1}'.format(calcID(r, t), calcID(r + 1, t)))
    else : print('{0} {1} {2} {3}'.format(calcID(r, t), calcID(r + 1, t), \
                                          calcID(r, t + 1), calcID(r + 1, t + 1)))
