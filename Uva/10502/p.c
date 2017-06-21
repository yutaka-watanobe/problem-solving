// @JUDGE_ID:  17051CA  10502  C++
// @begin_of_source_code
/* Grid Calculation */
#include<stdio.h>
#include<iostream>
#include<string>
#define MAX 101

int R, C;
char G[MAX][MAX];
int HT[MAX][MAX];
int VT[MAX][MAX][MAX];

int read(){
  cin >> R >> C;
  if ( R == 0 ) return 0;

  char ch;
  for ( int i = 0; i < R; i++ ){
    for ( int j = 0; j < C; j++ ){
      cin >> G[i][j];  
    }
  }
  return 1;

}

int createTable(){
  int sum = 0;

  for ( int i = 0; i < R; i++ ){
    int cnt = 0;
    for ( int j = C-1; j >= 0; j-- ){
      if( G[i][j] == '0' ) cnt = 0;
      else cnt++;
      HT[i][j] = cnt;
    }
  }

  for ( int k = 0; k < C; k++ ){
    for ( int j = 0; j < C; j++ ){
      int cnt = 0;
      for (int i = R-1; i >= 0; i-- ){
	if( HT[i][j] >= k+1 ) cnt++;
	else cnt = 0;
	VT[i][j][k] = cnt;
	sum += cnt;
      }
    }
  }

  return sum;
  /*
  for ( int i = 0; i < R; i++ ){
    for ( int j = 0; j < C; j++ ){
      cout << HT[i][j];
    }
    cout << endl;
  }
  cout << endl;

  for ( int k = 0; k < C; k++ ){
    for ( int i = 0; i < R; i++ ){
      for ( int j = 0; j < C; j++ ){
	cout << VT[i][j][k] ;
      }
      cout << endl;
    }
    cout << endl;
  }
  */
}

void work(){
  cout << createTable() << endl;
}

main(){
  while ( read() ){
    work();
  }
}
// @end_of_source_code
