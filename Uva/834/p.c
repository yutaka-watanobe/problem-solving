// @JUDGE_ID:  17051CA  834  C++
// @begin_of_source_code
/* Number */
#include<stdio.h>
#include<iostream>
#include<vector>

int numerator, denominator;
vector<int> B;

bool read(){
  if ( !( cin >> numerator >> denominator ) ) return false;
  return true;
}

void work(){
  B.clear();
  int b, tmp;
  while ( 1 ){

    if ( denominator <= 1 ) {
      B.push_back( numerator );
      break;
    }

    b = numerator / denominator;

    B.push_back( b );

    numerator = numerator % denominator;
    
    /* swap */
    tmp = numerator;
    numerator = denominator;
    denominator = tmp;
  }

  cout << "[" << B[0] <<";";
  for ( int i = 1; i < B.size(); i++ ){
    if ( i > 1) cout << ",";
    cout << B[i];
  }
  cout << "]" << endl;
}

main(){
  while ( read() ){
    work();
  }
}

// @end_of_source_code
