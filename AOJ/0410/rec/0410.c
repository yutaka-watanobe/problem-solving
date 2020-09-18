#include<stdio.h>
typedef unsigned long long ull;
int N, A[20], cnt;
int selected[20];

ull gcd(ull x, ull y){ return y ? gcd(y, x % y) : x; }
ull lcm(ull x, ull y){ return x / gcd(x, y)*y; }
  
void rec(int p, ull LCM, int sum){
  int ok;
  if ( p == N ){
    ok = (sum > 0); // 一人以上いる
    for ( int i = 0; i < N; i++ ){
      //　選ばれていない人の周期
      if ( LCM >= A[i] && LCM % A[i] == 0 && selected[i] == 0 ) ok = 0; 
    }
    if ( ok ) cnt++;
  } else {
    selected[p] = 1;
    rec(p+1, lcm(LCM, A[p]), sum + 1);
    selected[p] = 0;
    rec(p+1, LCM, sum);
  }
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
