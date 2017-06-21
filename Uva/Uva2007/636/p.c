// @JUDGE_ID:  17051CA  636  C++
// @begin_of_source_code
/* Brute Force */
#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>

class Squeares{
 public:
  string input;

  int getNumber( int base ){
    int p = 1;
    int size = input.size();
    int sum = 0;
    for ( int i = size - 1; i >= 0; i-- ){
      sum += ( input[i] - '0' ) * p;
      p *= base;
    }
    return sum;
  }
  
  bool isSqueare( int x ){
    int sq = (int)sqrt( (double)x );
    return x == sq * sq;
  }

  void work(){
    int maxbase = 1;

    for ( int i = 0; i < input.size(); i++ ){
      if ( maxbase < input[i] - '0' ) maxbase = input[i] - '0';
    }

    for ( int base = maxbase + 1; base < 100; base++ ){
      int x = getNumber( base );
      if ( isSqueare( x ) ){
	printf("%d\n", base );
	return;
      }
    }
  }

  bool read(){
    cin >> input;
    if ( input == "0" ) return false;
    return true;
  }

};

main(){
  Squeares S;
  while ( S.read() ){
    S.work();
  }
}

// @end_of_source_code


