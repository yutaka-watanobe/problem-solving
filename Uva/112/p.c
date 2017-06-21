// @JUDGE_ID:  17051CA  112  C++
// @begin_of_source_code
/* Tree - Recursion */
#include<stdio.h>
#include<iostream>
#include<string>

int n;
bool able;

int read(){
  cin >> n;
  if ( cin.eof() ) return 0;
  return 1;
}

string rec( int k ) {

  char c;
  string str = "";

  while ( cin >> c && ( isdigit(c) || c == '-' )){
    str += c;
  }
  
  string s1, s2;
  if ( c == '(' ){
    s1 = rec ( k + atoi( str.c_str() ) );
  } else if ( c == ')' ){
    return str;
  }

  cin >> c; /* ')' */

  s2 = rec ( k + atoi( str.c_str() ) );

  if ( s1 == "" && s2 == "" ) {
    //cout << k + atoi( str.c_str() )<< endl;
    if (k + atoi( str.c_str() ) == n ) able = true;
  }

  cin >> c; /* ')' */

  return str;
}

void work(){
  able = false;
  char c;
  cin >> c;
  rec( 0 );
  if ( able ) cout << "yes" << endl;
  else cout << "no" << endl;
}

main(){
  while ( read() ) {
    work();
  }
}
// @end_of_source_code
