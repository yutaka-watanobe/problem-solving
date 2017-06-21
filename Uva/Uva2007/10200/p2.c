// @JUDGE_ID:  17051CA  10200  C++
// @begin_of_source_code
/* Prime & Cash */
#include<stdio.h>
#include<iostream>
#define N 10000
typedef  long long ullong;

bool prime[N+1];

int base[6] = {0, 2, 3, 5, 7, 11};
ullong limit[4] = {2047, 1373653, 25326001, 2147483647};

bool isprime(ullong x){

  if ( x <= 2 ) return false;
  if ( x % 2 == 0 ) return false;
  ullong r = (ullong)sqrt(x);
  for ( int i = 3; i <= r; i+=2){
    if ( x % i == 0 ) return false;
  }
  return true;
}

void init(){
  for ( int i = 0; i <= N; i++ ){
    if ( isprime( i*i + i + 41 ) ) prime[i] = true;
    else prime[i] = false;
  }
}

class PrimeTime{
 public:
  int lower, upper;

  void work(){
    int cnt = 0;
    for ( int i = lower; i <= upper; i++ ){
      if ( prime[i] ) cnt++;
    }
    printf("%.2lf\n", 100.0 * cnt / ( upper - lower + 1 ) );
  }

  bool read(){
    if ( scanf("%d %d", &lower, &upper ) == EOF ) return false;
    return true;
  }
};

main(){
  PrimeTime PT;
  init();
  while ( PT.read() ){
    PT.work();
  }
}
// @end_of_source_code


