// @JUDGE_ID:  17051CA  10424  C++
// @begin_of_source_code
/* Calculation */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>

string name1, name2;

string itoa( int x ){
  char a[20];
  sprintf( a, "%d", x );
  return string( a );
}

void tolower( string &s ){
  for ( int i = 0; i < s.size(); i++ ) s[i] = tolower( s[i] );
}

int read(){
  getline( cin, name1 );
  if ( cin.eof() ) return 0;
  getline( cin, name2 );
  return 1;
}

int compute( string &str ){
  tolower( str );

  int sum = 0;
  for ( int i = 0; i < str.size(); i++ ){
    if ( isalpha( str[i] ) ) sum += str[i] - 'a'+1;
  }

  while ( 1 ){
    if ( sum < 10 )  break;
    str = itoa( sum );
    sum = 0;
    for ( int i = 0; i < str.size(); i++ ){
      sum += str[i] - '0';
    }
  }

  return sum;
}

void work(){
  int n1, n2;
  n1 = compute( name1 );
  n2 = compute( name2 );

  double ratio = 100.0 * min( n1, n2 )/max( n1, n2 );
  
  printf( "%.2f", ratio );
  cout << " %" << endl;
}

main(){
  while ( read() ) work();
}
// @end_of_source_code
