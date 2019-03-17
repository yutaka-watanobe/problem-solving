bus = []
for i in range(2):
    l = list(map(int, input().split()))
    N = l[0]
    t = l[1:]
    for j in range(N):
        bus.append(t[j * 2] * 60 + t[j * 2 + 1])
print(' '.join(['{0}:{1:02d}'.format(i // 60, i % 60) for i in sorted(set(bus))]))
