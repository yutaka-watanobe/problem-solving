// @JUDGE_ID:  17051CA  694  C++
// @begin_of_source_code
/* Brute Force */
#include<stdio.h>
#include<iostream>
#include<string>

long long A, limit, terms;

int read(){
  cin >> A >> limit;
  if( A < 0 && limit < 0) return 0;
  return 1;
}

void work(){
  terms = 0;
  while ( 1 ){
    terms++;
    if ( A == 1 ) break;
    else if ( A % 2 == 0 ){
      A = A / 2;
    }else{
      A = 3*A + 1;
      if ( A > limit ) break;
    }
  }
  cout << "number of terms = " << terms << endl;
}

main(){
  for ( int i = 1 ; read(); i++ ){
    cout << "Case " << i << ": A = " << A << ", limit = " << limit << ", ";
    work();
  }
}
// @end_of_source_code
