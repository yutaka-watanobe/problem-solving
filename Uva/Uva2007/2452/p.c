// @JUDGE_ID:  17051CA  2452  C++
// @begin_of_source_code
/* £²Ê¬Ë¡ */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#define MAX 10001

int N, L;
int Cable[ MAX ];
int maxLength;

int function( int x ){
  int sum = 0;
  for ( int i = 0; i < N; i++ ){
    sum += Cable[ i ] / x;
  }
  return sum - L ;
}

int bisection( int lower, int upper ){
  int mid;
  int epsilon = 1;

  while ( 1 ){
    if ( abs(lower - upper) <= 1 ) return lower;
    mid = ( lower + upper ) / 2;
    int fc = function( mid );

    if ( fc < 0 ) upper = mid;
    else if ( fc >= 0 ) lower = mid;
  }
  return lower;
}

void work(){

  int ans = bisection( 0, maxLength + 1);

  if ( ans == 0 ) cout << "0.00" << endl;
  else printf("%d.%02d\n", ans / 100, ans % 100 );
}

int read(){
  cin >> N >> L;

  int left, right;
  char ch;
  maxLength = 0;
  for ( int i = 0; i < N; i++ ){
    cin >> left >> ch >> right;
    Cable[ i ] = left * 100 + right;
    maxLength = max( Cable[i], maxLength );
  }
}

main(){
  int tcase;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    if ( i ) cout << endl;
    read();
    work();
  }    

}
// @end_of_source_code
