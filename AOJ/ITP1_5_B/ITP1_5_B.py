while True:
    h,w = map(int, input().split())
    if h == 0 and w == 0: break
    for j in range(h):
        for i in range(w):
            if i == 0 or j == 0 or i == w-1 or j == h-1:
                print("#", end="")
            else:
                print(".", end="")
        print()
    print()
