L, N = map(int, input().split())
snake = input()
oocnt = 0
for i in range(len(snake) - 1):
    if snake[i] == 'o' and snake[i + 1] == 'o' :
        oocnt = oocnt + 1
total = 0
for i in range(N):
    total = total + oocnt
    oocnt = oocnt * 2
print(3 * total + L)
