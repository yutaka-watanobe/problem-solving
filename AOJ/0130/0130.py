# AOJ からの暫定模範解答
# !! 変更する必要あり!!!

I=input
for _ in [0]*int(I()):
    t=I()
    a=t[0]
    for x in range(1,len(t),3):
        if t[x+2] in a:continue
        if t[x]=='-':a+=t[x+2]
        else:a= t[x+2]+a
    print(a)
