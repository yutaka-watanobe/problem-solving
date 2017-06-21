// @JUDGE_ID:  17051CA  10533  C++
// @begin_of_source_code
/* Number theory (prime) + calculation */
#include<stdio.h>
#include<math.h>
#include<iostream>
#define N 1000000

short prime[N+1];
short digitprime[N+1];
short C[N];

void eratos( int n ){
  for ( int i = 0; i < N; i++ ) prime[i] = 0;

  for ( int i = 3; i <= n; i += 2 ) prime[i] = 1;
  prime[2] = 1;

  for ( int i = 3, limit = (int)sqrt(n); i <= limit; i += 2 ) {
    if ( !prime[i] ) continue;
    for ( int j = i * i, k = i * 2; j <= n; j += k ) prime[j] = 0;
  }
}

int t1, t2;

void work(){
  int cnt = 0;
  int sum;
  int  i;
  scanf( "%d %d", &t1, &t2 );
  printf("%d\n", C[t2] - C[t1-1] );
}

main(){
  int carry[8];
  int sum = 0;
  int i, j, t;
  int dow;
  int cnt = 0;
  for ( i = 0; i < N; i++ ) digitprime[i] = 0;

  eratos( N );

  for ( i = 0; i < 8; i++ ) carry[i] = 0;

  for ( i = 0; i < 1000000; i++ ){
    if ( prime[i] && prime[sum] ){
      digitprime[i] = 1;
    }

    j = 0;
    dow = 1;
    carry[0]++;
    sum++;
    while ( carry[j] == 10 ){
      sum--;
      carry[j] = 0;
      carry[j+1]++;
      j++;
      sum -= 8; 
      dow = 1;
    }
  }

  for ( i = 0; i < N; i++ ){

    if ( digitprime[i] ){
      cnt++;
    }
    C[i] = cnt;
//    cout << i << " " << C[i] << endl;

  }

  scanf( "%d", &t );
  for ( i =0; i < t; i++ ) work();
}
// @end_of_source_code
