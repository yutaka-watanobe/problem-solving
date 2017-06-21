// @JUDGE_ID:  17051CA  10473  C++
// @begin_of_source_code
/* Base Conversion */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
typedef long long llong;

class SimpleBaseConversion{
 public:

  bool work(){
    string line;
    cin >> line;
    llong x = atoi( line.c_str() );

    if ( x < 0 ) return false;

    if ( line.size() >= 3 && line[0] == '0' && line[1] == 'x' ){
      sscanf( line.c_str(), "%llX", &x ); 
      printf("%lld\n", x );      
    } else {
      printf("0x%llX\n", x );
    }

    return true;
  }

};

main(){
  SimpleBaseConversion SBC;

  while ( SBC.work() ){}
}

// @end_of_source_code


