// @JUDGE_ID:  17051CA  10680  C++
// @begin_of_source_code
#include<stdio.h>
#include<algorithm>
int gcd(int a, int b){
  int tmp;

  if(a<b) swap(a, b);

  while(b){
    a %= b;
    
    tmp = a;
    a = b;
    b = tmp;
  }

  return a;
}

int lcm(int a, int b){
  if(a<b) swap(a, b);
  return a*b/gcd(a, b);
}

int n;

void work(){
  int l = 1;
  for ( int i = 1; i <= n; i++ ){
    l = lcm( l, i ) % 10000;
    printf("%d\n", l );
  }
}

bool read(){
  scanf("%d", &n ); if ( n == 0 ) return false;
  return true;
}

main(){
  while( read() ){
    work();
  }
}
// @end_of_source_code
