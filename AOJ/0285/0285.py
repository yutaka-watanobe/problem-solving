j,y = map(int, input().split())

<<<<<<< HEAD
def parse(a, b, path):
    if a == j and b == y:
=======
<<<<<<< HEAD
def parse(j, y, p):
=======
def parse(j, y, path):
>>>>>>> 9b2e9d282861ec1ae517d4bb729818bfd06feb59
    if j == J and y == Y:
>>>>>>> 08faa0630608918c9521044b96e6ea7b8554d063
        print(path)
        return
    elif a == 5 and b <= 3 or b == 5 and a <= 3:
        return

    if  a > j or b > y:
        return
<<<<<<< HEAD
    
    parse(j+1, y, p + "A")
    parse(j, y+1, p + "B")

=======

    parse(a + 1, b, path + "A")
    parse(a, b + 1, path + "B")

>>>>>>> 9b2e9d282861ec1ae517d4bb729818bfd06feb59
parse(0, 0, "")
