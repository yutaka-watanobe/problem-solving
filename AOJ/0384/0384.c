#include <stdio.h>

long long getY(long long x){
  long long y = 0;
  while(x){
    y += x % 10;
    x /= 10;
  }
  return y;
}

int main(){
  long long a, n, m, y, t, x, cnt = 0;
  scanf("%lld %lld %lld", &a, &n, &m);
  for ( y = 1; y <= 72; y++ ){
    x = 1;
    for ( t = 1; t <= n; t++ ){
      x *= (y + a);
    }
    if (x <= m && getY(x) == y) cnt++;
  }
  printf("%lld\n", cnt);
  return 0;
}

