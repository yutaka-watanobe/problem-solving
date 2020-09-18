#include<stdio.h>

long long gcd(long long x, long long y){ return y ? gcd(y, x % y) : x ; }
long long lcm(long long x, long long y){ return x / gcd(x, y) * y; }
  
int main(){
  int N, A[20], i, bit, valid, cnt = 0;
  long long LCM;
  scanf("%d", &N);
  for ( int i = 0; i < N; i++ ) scanf("%d", &A[i]);

  for ( bit = 1; bit < (1 << N); bit++ ) {
    valid = 1;
    LCM = 1;
    for ( i = 0; i < N; i++ ){
      if ( bit & (1 << i) ) LCM = lcm(LCM, A[i]);
    }
    for ( i = 0; i < N; i++ ){
      if ( (bit & (1 << i)) == 0 )
	if ( LCM >= A[i] && LCM % A[i] == 0 ) valid = 0; 
    }
    if ( valid ) cnt++;
  }
  
  printf("%d\n", cnt);
  return 0;
}
