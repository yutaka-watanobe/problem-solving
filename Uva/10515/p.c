// @JUDGE_ID:  17051CA  10515  C++
// @begin_of_source_code
/* Number */
#include<stdio.h>
#include<iostream>
#include<string>

string M, N;

int read(){
  cin >> M >> N;
  if ( M == "0" && N == "0" ) return 0;
  return 1;
}

void work(){

  int m = atoi ( M.substr( M.size()-1, 1 ).c_str() ); 
  int n = atoi ( N.substr( N.size()-1, 1 ).c_str() ); 

  if( N.size() > 1 ) n = atoi ( N.substr( N.size()-2, 2 ).c_str() ); 


  if( m == 0 || m == 1 || m == 5 || m == 6){
    cout << m << endl;
    return;
  }

  int r = n % 4;

  if( m == 2 ){
    if ( r == 1 ) cout << 2 << endl;
    if ( r == 2 ) cout << 4 << endl;
    if ( r == 3 ) cout << 8 << endl;
    if ( r == 0 ) cout << 6 << endl;
  }

  if( m == 3 ){
    if ( r == 1 ) cout << 3 << endl;
    if ( r == 2 ) cout << 9 << endl;
    if ( r == 3 ) cout << 7 << endl;
    if ( r == 0 ) cout << 1 << endl;
  }

  if( m == 7 ){
    if ( r == 1 ) cout << 7 << endl;
    if ( r == 2 ) cout << 9 << endl;
    if ( r == 3 ) cout << 3 << endl;
    if ( r == 0 ) cout << 1 << endl;
  }

  if( m == 8 ){
    if ( r == 1 ) cout << 8 << endl;
    if ( r == 2 ) cout << 4 << endl;
    if ( r == 3 ) cout << 2 << endl;
    if ( r == 0 ) cout << 6 << endl;
  }

  r = n % 2;

  if( m == 4 ){
    if ( r == 1 ) cout << 4 << endl;
    if ( r == 0 ) cout << 6 << endl;
  }

  if( m == 9 ){
    if ( r == 1 ) cout << 9 << endl;
    if ( r == 0 ) cout << 1 << endl;
  }

}

main(){
  while( read() ){
    work();
  }
}
// @end_of_source_code
