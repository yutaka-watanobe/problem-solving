def parse(j, y, path, J, Y):
    if j == J and y == Y:
        print(path)
        return
    elif j == 5 and y <= 3 or y == 5 and j <= 3:
        return

    if  j > J or y > Y:
        return
    
    parse(j+1, y, path + "A", J, Y)
    parse(j, y+1, path + "B", J, Y) 

J,Y = map(int, input().split())
parse(0, 0, "", J, Y)
