import re

A = ">'(=+)#\\1~$" # A >'======#======~
B = ">\^(Q=)+~~$"  # B >^Q=Q=Q=Q=Q=Q=Q=Q=Q=~~

for i in range(int(input())):
    s = input()
    r = re.match(A, s)

    if re.match(A, s): print('A')
    elif re.match(B, s): print('B')
    else: print('NA')
