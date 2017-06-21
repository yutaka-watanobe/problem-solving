// @JUDGE_ID:  17051CA  10323  C++
// @begin_of_source_code
/* Factorial */
/* Fuckin Problem! */
#include<stdio.h>
#include<iostream>
#define UPPER 6227020800ULL
#define LOWER 10000
typedef unsigned long long ullong;

class Kidding{
 public:
  int n;

  void compute(){
    ullong fac = 1;
    for ( int i = 1; i <= n; i++ ){
      fac *= i;
      if ( fac > UPPER ){
	cout << "Overflow!" << endl;
	return;
      }
    }

    if ( fac < LOWER ){
      cout << "Underflow!" << endl;
      return;
    }
    
    cout << fac << endl;
  }

  void work(){
    if ( n < 0 ){
      n = -n;
      if ( n % 2 == 0 ) cout << "Underflow!" << endl;
      else cout << "Overflow!" << endl;
    } else {
      compute();
    }
  }

  bool read(){
    if ( ! ( cin >> n ) ) return false;
    return true;
  }
};

main(){
  Kidding K;
  while ( K.read() ){
    K.work();
  }
}
// @end_of_source_code
