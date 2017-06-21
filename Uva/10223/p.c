// @JUDGE_ID:  17051CA  10223  C++
// @begin_of_source_code
/* Dynamic Programming */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stl.h>
#define MAX 21
#define LIMIT 4294967295UL
typedef unsigned long long ullong;

vector<ullong> M;
int n;

void init(){
  M.resize( MAX );

  M[0] = 1;
  M[1] = 1;
  M[2] = 2;
  
  int index = 3;
  int i, j;
  while ( 1 ){
    M[index] = 0;
    for ( i = index - 1, j = 0; i >= 0; i--, j++ ){
      M[index] += M[i] * M[j];
    }
    if ( M[index] > LIMIT ) break;
    index++;
  }
}

void work(){
  if ( n == 1 ) { cout << 1 << endl; return;}
  vector<ullong>::iterator pos;
  pos = lower_bound( M.begin(), M.end(), n );
  cout << distance( M.begin(), pos ) << endl;
}

main(){
  init();
  while ( cin >> n ){
    work();
  }
}
// @end_of_source_code
