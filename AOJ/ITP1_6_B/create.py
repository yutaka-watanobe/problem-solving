tbl = [[i+j for i in range(7)] for j in range(5)]

for i, row in enumerate(tbl):
    for j, elem in enumerate(row):
        if j > 0: print(" ", end = "")
        print(elem, end = "")
    print()

# 0 1 2 3 4 5 6
# 1 2 3 4 5 6 7
# 2 3 4 5 6 7 8
# 3 4 5 6 7 8 9
# 4 5 6 7 8 9 10
