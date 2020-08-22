J,Y = map(int, input().split())

def parse(j, y, p):
    if j == J and y == Y:
        print(p)
        return
    elif j == 5 and y <= 3 or y == 5 and j <= 3:
        return

    if  j > J or y > Y:
        return
    
    parse(j+1, y, p + "A")
    parse(j, y+1, p + "B")

parse(0, 0, "")
