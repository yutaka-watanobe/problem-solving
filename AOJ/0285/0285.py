#def parse(j, y, p, J, Y):
#    if j == J and y == Y:
#        print(p)
#        return
#    elif j == 5 and y <= 3 or y == 5 and j <= 3:
#        return
#
#    if  j > J or y > Y:
#        return
#    
#    parse(j+1, y, p + "A", J)
#    parse(j, y+1, p + "B", Y) 

J,Y = map(int, input().split())
#parse(0, 0, "", J, Y)
