// @JUDGE_ID:  17051CA  10182  C++
// @begin_of_source_code
/* create Table by DP */
/* 0.045 sec */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>

#define MAX 110000

short T[MAX][6];
int dx[6] = {0, -1, 0, 1, 1, -1};
int dy[6] = {1, 0, -1, -1, 0, 1};

void init(){
  fill ( T[0], T[0] + 6, 0 );
  fill ( T[1], T[1] + 6, 0 );
  T[2][0] = 1;

  int i = 3;
  int inc = 1;

  while ( i < 101000 ){

    for ( int k = 1; k < 5; k++ ){
      for ( int n = 0; n < inc; n++ ){
	for ( int j = 0; j < 6; j++ ){
	  T[i][j] += T[i-1][j];
	  if( j == k ) T[i][j]++;
	}
	i++;
      }
    }
    
    for ( int n = 0; n < inc + 1; n++ ){
      for ( int j = 0; j < 6; j++ ){
	T[i][j] += T[i-1][j];
	if( j == 0 ) T[i][j]++;
      }
      i++;
    }

    for ( int n = 0; n < inc ; n++ ){
      for ( int j = 0; j < 6; j++ ){
	T[i][j] += T[i-1][j];
	if( j == 5 ) T[i][j]++;
      }
      i++;
    }

    inc++;
  }

}

int N;

int read(){
  cin >> N;
  if ( cin.eof() ) return 0;
  return 1;
}

void work(){
  int x, y;
  x = y = 0;
  for ( int j = 0; j < 6; j++ ){
    x += T[N][j] * dx[j];
    y += T[N][j] * dy[j];
  }

  cout << x << " " << y << endl;
}

main(){
  init();
  while ( read() ) work();
}
// @end_of_source_code
