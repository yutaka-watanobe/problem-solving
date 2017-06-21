// @JUDGE_ID:  17051CA  10504  C++
// @begin_of_source_code
/* Grid Calculation */
/* 境界設定に注意 ！*/
#include<stdio.h>
#include<iostream>
#include<string>
#define MAX 101

char G[MAX][MAX];

int N, M;;

int read(){
  cin >> N >> M;
  if ( N == 0 ) return 0;

  for ( int i = 0; i < N; i++ ){
    for ( int j = 0; j < N; j++ ){
      cin >> G[i][j];
    }
  }

  return 1;
}

int count_square(char ch){
  int ni, nj;
  int sum = 0;
  for ( int x = 2; x <= N; x++ ){
    for ( int y = 1; y <= N; y++ ){
      
      for ( int i = y - 1; i <= N - x; i++ ){
	for ( int j = 0; j <= N - ( x + y - 1); j++ ){
	  if( G[i][j] != ch ) continue;

	  ni = i - y + 1;
	  nj = j + x - 1;
	  /* if( !(0 <= ni && 0 <= nj && ni < N && nj < N && G[ni][nj] == ch) ) continue; */
	  if ( G[ni][nj] != ch ) continue;
 
	  ni = i + x - 1;
	  nj = j + y - 1;
	  /* if( !(0 <= ni && 0 <= nj && ni < N && nj < N && G[ni][nj] == ch) ) continue; */
	  if ( G[ni][nj] != ch ) continue;
	  ni = i - y + x;
	  nj = j + x + y - 2;
	  /* if( !(0 <= ni && 0 <= nj && ni < N && nj < N && G[ni][nj] == ch) ) continue; */
	  if ( G[ni][nj] != ch ) continue;

	  sum++;
	}
      }
    }
  }
  
  return sum;
}

void work(){
  char ch;
  for ( int i = 0; i < M; i++ ){
    cin >> ch;
    cout << ch << " " << count_square(ch) << endl;
  }
}

main(){
  while( read() ){
    work();
    cout << endl;
  }
}
// @end_of_source_code
