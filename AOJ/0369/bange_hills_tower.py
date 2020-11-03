N, t = map(int, input().split())
maxSlope = 0.0
for i in range(N):
    xi,hi = map(float, input().split())
    slope = hi / xi
    if slope > maxSlope : maxSlope = slope
print(t * maxSlope)
