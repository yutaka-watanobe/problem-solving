J,Y = map(int, input().split())

<<<<<<< HEAD
def parse(j, y, p):
=======
def parse(j, y, path):
>>>>>>> 9b2e9d282861ec1ae517d4bb729818bfd06feb59
    if j == J and y == Y:
        print(path)
        return
    elif j == 5 and y <= 3 or y == 5 and j <= 3:
        return

    if  j > J or y > Y:
        return
<<<<<<< HEAD
    
    parse(j+1, y, p + "A")
    parse(j, y+1, p + "B")

=======

    parse(j+1, y, path + "A")
    parse(j, y+1, path + "B")

>>>>>>> 9b2e9d282861ec1ae517d4bb729818bfd06feb59
parse(0, 0, "")
