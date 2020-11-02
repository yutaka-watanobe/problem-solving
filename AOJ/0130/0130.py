n = int(input())
for _ in range(n):
    s = input() # 巡回記録
    form = s[0] # 列車の編成
    for i in range(3, len(s), 3):
        if s[i] in form: continue
        if s[i - 1] == '>':
            form += s[i]
        else:
            form = s[i] + form
    print(form)
