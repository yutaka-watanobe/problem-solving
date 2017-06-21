// @JUDGE_ID:  17051CA  10137  C++
// @begin_of_source_code
/* Caluculation */
/* Do Not use double ! */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>

int n;

int read(){
  cin >> n;
  if ( n == 0 ) return 0;
  return 1;
}

void work(){
  vector<int> money;
  money.resize( n );

  int sum = 0;
  int doll, cent, average;
  char ch;

  for ( int i = 0; i < n; i++ ){
    cin >> doll >> ch >> cent;
    sum += doll * 100 + cent;
    money[i] = doll * 100 + cent;
  }

  average = (int)((1.0* sum / n) + 0.5);

  int plus = 0;
  int minus = 0;

  int a, m;
  a = average;
  for ( int i = 0; i < n; i++ ){
    m = money[i];
    if ( a < m ){
      plus += m - a;
    }
    if ( a > m ){
      minus += a - m;
    } 
  }

  int ans = min( plus, minus );

  cout << "$" << ans/100 << ".";
  if ( ans%100 < 10 ) cout << "0";
  cout << ans%100 << endl;
}

main(){
  while ( read() ) work();
}
// @end_of_source_code
