#include <stdio.h>

long long val(long long x){
  long long sum = 0;
  while(x){
    sum += x%10;
    x /= 10;
  }
  return sum;
}

int main(){
  long long a, n, m, y, t, x, cnt = 0;
  scanf("%lld %lld %lld", &a, &n, &m);

  for ( y = 1; y <= 72; y++ ){
    x = 1;
    for ( t = 1; t <= n; t++ ){
      x *= (y+a);
    }
    if (x <= m && val(x) == y) cnt++;
  }

  printf("%lld\n", cnt);

  return 0;
}

