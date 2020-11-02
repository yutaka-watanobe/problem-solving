unit = ("", "Man", "Oku", "Cho", "Kei", "Gai", "Jo", "Jou", "Ko", "Kan", "Sei", \
        "Sai", "Gok", "Ggs", "Asg", "Nyt", "Fks", "Mts")

while True:
    m, n = map(int, input().split())
    if m == 0 and n == 0: break
    val = m ** n
    res = ""
    for u in unit :
        val, m = divmod(val, 10000)
        if m :
            res = str(m) + u + res
    print(res)
