// @JUDGE_ID:  17051CA  343  C++
// @begin_of_source_code
/* Base conversion */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

class WhatBaseIsThis{
 public:
  string input1;
  string input2;
  vector<int> V;
  
  int getNumber( char ch ){
    if ( isdigit( ch ) ){
      return ch - '0';
    } else {
      return ch - 'A' + 10;
    }
  }

  int getValue( string &str, int base ){
    int p = 1;
    int sum = 0;
    for ( int i = str.size() - 1; i >= 0; i-- ){
      sum += p * getNumber ( str[i] );
      p *= base;
    }
    return sum;
  }
  
  int getLowerBase( string str ){
    int max_value = 0;
    for ( int i = 0; i < str.size(); i++ ){
      max_value = max( max_value, getNumber( str[i] ));
    }
    max_value++;
    if ( max_value < 2 ) max_value = 2;
    return max_value;
  }

  void work(){
    V.clear();
    int lower1, lower2;
    lower1 = getLowerBase( input1 );
    lower2 = getLowerBase( input2 );

    for ( int base = lower1; base <= 36; base++ ){
      V.push_back( getValue( input1, base ) );
    }

    for ( int base = lower2; base <= 36; base++ ){
      int value = getValue( input2, base );

      for ( int i = 0; i < V.size(); i++ ){
	if ( V[i] > value ) goto next;
	if ( V[i] == value ){
	  printf("%s (base %d) = %s (base %d)\n",
		 input1.c_str(), i + lower1, input2.c_str(), base );
	  return;
	}
      }
    next:;

    }

    printf("%s is not equal to %s in any base 2..36\n",
	   input1.c_str(), input2.c_str() );
    
  }

  bool read(){
    if ( ! ( cin >> input1 >> input2 ) ) return false;
    return true;
  }
};

main(){
  WhatBaseIsThis WBIT;
  while ( WBIT.read() ){
    WBIT.work();
  }
}

// @end_of_source_code


