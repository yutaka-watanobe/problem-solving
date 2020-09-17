j,y = map(int, input().split())

def parse(a, b, path):
    if a == j and b == y:
        print(path)
        return
    elif a == 5 and b <= 3 or b == 5 and a <= 3:
        return
    if  a > j or b > y:
        return
    parse(a + 1, b, path + "A")
    parse(a, b + 1, path + "B")

parse(0, 0, "")
