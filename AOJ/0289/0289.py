def solve(src, dst):
    if src == dst: return 0
    answer = 0
    if src % 2 != 0:
        answer += 1
        src += 1
    if dst % 2 != 0:
        answer += 1
        dst -= 1
    answer += solve(src // 2, dst // 2)
    return answer

N = int(input())
for i in range(N):
    s,d = map(int, input().split())
    print(solve(s,d))
