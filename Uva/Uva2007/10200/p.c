// @JUDGE_ID:  17051CA  10200  C++
// @begin_of_source_code
/* Prime & Cash */
#include<stdio.h>
#include<iostream>
#define N 10000
typedef unsigned long long ullong;

bool prime[N+1];

int base[6] = {0, 2, 3, 5, 7, 11};
ullong limit[4] = {2047, 1373653, 25326001, 2147483647};

bool isprime(ullong x){

  ullong d, d1, prod, a2j;
  int s;

  if(x==2) return 1;
  if(x%2==0) return 0;
  
  for(d=x-1, s=0; d>0 && d%2==0; d/=2, s++);
  d1 = d;
  
  for(int i=1; i<=5; i++){
    a2j = base[i]; prod = 1; d = d1;
    while(d > 0){
      if(d%2==1) prod = (prod*a2j)%x;
      d /= 2;
      a2j = (a2j*a2j)%x;
    }
    
    if(prod==1 || prod==x-1) goto lim_check;
    
    for(unsigned long long j=1; j<=s-1; j++){
      prod = (prod*prod)%x;
      if(prod==1) return 0;
      if(prod==x-1) goto lim_check;
    }
    return 0;
  lim_check:
    if(x < limit[i]) return 1;
  }
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


