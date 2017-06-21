// @JUDGE_ID:  17051CA  10293  C++
// @begin_of_source_code
/* Count */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#define MAX 50

int T[MAX];

void init(){
  fill ( T, T + MAX, 0 );
}

int work(){
  char ch;
  int len = 0;
  char pre = ' ';

  init();

  while ( 1 ){
    cin.get( ch ); if ( cin.eof() ) return false;
    if ( ch == '#' ) goto next;
    
    if ( ch == ' ' || ch == '.' || ch == ',' || ch == '?' || ch == '!' ){
      if ( len ) T[ len ]++;
      len = 0;
    }else if ( ch == '\n' && pre != '-' ){
      if ( len ) T[ len ]++;
      len = 0;
    }else {
      if ( isalpha( ch ) ) len++;
    }

    pre = ch;
  }

 next:;
  for ( int i = 1; i < MAX; i++ ){
    if ( T[i] ){
      cout << i << " " << T[i] << endl;
    }
  }
  cout << endl;

  return true;
}

main(){
  while ( work() );
}
// @end_of_source_code
