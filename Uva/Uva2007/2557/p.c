// @JUDGE_ID:  17051CA  2557  C++
// @begin_of_source_code
/* Simple Simulation */
#include<stdio.h>
#include<iostream>
#include<stl.h>
#define MAX 102

int N;
bool C[ MAX ]; /* cell locked ? unlocked ? */

void work(){
  fill ( C, C + N + 1, false );
  cin >> N;

  for ( int i = 1; i <= N; i++ ){
    for ( int j = 1; j <= N; j++ ){
      if ( j % i == 0 ){
	C[ j ] = ( C[ j ] ? false : true );
      }
    }
  }
  
  int sum = 0;
  for ( int i = 1; i <= N; i++ ) {
    if ( C[ i ] ) sum++;
  }

  cout << sum << endl;
}

main(){
  int tcase;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    work();
  }
}

// @end_of_source_code


