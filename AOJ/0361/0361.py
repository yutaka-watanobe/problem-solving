def gcd(x, y):
  return gcd(y, x%y) if y > 0 else x

x, y = map(int, input().split())
print((x+1) + (y+1) - (gcd(x, y) - 1) - 2)
