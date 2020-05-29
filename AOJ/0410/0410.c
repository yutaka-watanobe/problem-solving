#include<stdio.h>
typedef unsigned long long ull;
int N, A[20], cnt;
int S[20]; // select?

ull gcd(ull x, ull y){
  ull r, t;
  if ( x < y ) { t = x; x = y; y = t; }
  while( y > 0 ){
    r = x % y;
    x = y;
    y = r;
  }
  return x;
}
ull lcm(ull x, ull y){
  return x/gcd(x, y)*y;
}
  
void rec(int p, ull LCM, int sum){
  int ok;
  if ( p == N ){
    ok = (sum > 0); // 一人以上いる
    for ( int i = 0; i < N; i++ ){
      if ( LCM >= A[i] && LCM % A[i] == 0 ){
        if ( S[i] == 0 ) ok = 0; //　選ばれていない人の周期
      }
    }
    if ( ok ) cnt++;
    return;
  }
  S[p] = 1;
  rec(p+1, lcm(LCM, A[p]), sum+1);
  S[p] = 0;
  rec(p+1, LCM, sum);
}
int main(){
  int i;
  scanf("%d", &N);
  for ( i = 0; i < N; i++ ) scanf("%d", &A[i]);
  cnt = 0;
  rec(0, 1, 0);
  printf("%d\n", cnt);
  return 0;
}
