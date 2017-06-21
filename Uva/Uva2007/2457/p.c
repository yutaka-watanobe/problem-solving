// @JUDGE_ID:  17051CA  2457  C++
// @begin_of_source_code
/* Number */
/* LciR + LR = N と表現 */
/* L*10^(i+1) + c*10^i + R + L*10^i + R = N */
/* 1) まず R を決定する */
/* 繰り上がる場合があるので場合分けをする, すなわち */
/* R = ( N % 10i ) / 2 or */
/* R = ( N % 10i + 10i ) / 2   ( 10i = pow( 10, i ) ) */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
typedef unsigned long long ullong;

string ltoa(ullong x){
  char a[25];
  sprintf(a, "%lld", x);
  return string(a);
}

ullong power(ullong x, int n){
  ullong tmp = 1;
  if(n>0){
    tmp = power(x, n/2);
    if(n%2==0) tmp = tmp*tmp;
    else tmp = tmp*tmp*x;
  }
  return tmp;
}

ullong  N;
set< pair<ullong, ullong> > resultList;

void insert( ullong left, ullong right, int c, ullong power_i ){

  ullong leftSide = left*power_i*10 + c*power_i + right;
  ullong rightSide = left*power_i + right;

  if ( leftSide + rightSide == N  && leftSide != rightSide && leftSide <= N && rightSide <= N ){
    resultList.insert( make_pair(leftSide, rightSide ) );
  }
}

void check( int i,  int c ){
  ullong L, R;

  ullong power_i = power( 10, i );

  ullong targetN = N;

  targetN = N % power_i;
  
  R = targetN / 2;
  L = ( N - 2*R - c*power_i ) / ( 11*power_i );
  insert( L, R, c, power_i );
  
  targetN = N % power_i + power_i;
  R = targetN / 2;
  L = ( N - 2*R - c*power_i ) / ( 11*power_i );
  insert( L, R, c, power_i );

}

void work(){
  string number;
  cin >> number;
  N = atoi( number.c_str() );

  resultList.clear();

  for ( int i = 0; i <= number.size(); i++ ){
    for ( int c = 0; c <= 9; c++ ){
      check( i, c );
    }
  }

  cout << resultList.size() << endl;

  set<pair<ullong, ullong> >::iterator pos;

  for ( pos = resultList.begin(); pos != resultList.end(); pos++ ){
    pair<ullong, ullong> candidate = *pos;
    ullong left = candidate.first;
    ullong right = candidate.second;
    string L = ltoa( left );
    string R = ltoa( right );

    while ( R.size() < L.size() -1 ) R = '0' + R;
    cout << L << " + " << R << " = " << N << endl;
  }
}

main(){
  int tcase;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    if ( i ) cout << endl;
    work();
  }
}
// @end_of_source_code
