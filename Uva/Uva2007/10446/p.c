// @JUDGE_ID:  17051CA  10446  C++
// @begin_of_source_code
/* DP */
#include<stdio.h>
#include<iostream>
#include<stl.h>
#define MAX 65
typedef unsigned long long ullong;

int n, b;
ullong M[MAX][MAX];

int read(){
  cin >> n >> b;
  if ( n > 60 ) return 0;
  else return 1;
}

void init(){
  for ( int i = 0; i < MAX; i++ ) fill ( M[i], M[i] + MAX, 1 );

  for ( int i = 2; i <= 61; i++ ){
    for ( int j = 0; j <= 60; j++ ){
      for ( int k = i-1; k >= i-j; k-- ){
	if ( k <= 1 ) M[i][j]++;
	else M[i][j] += M[k][j];
      }
    }
  }

}

void work(){
  if ( n <= 1 || b <= 0 ) cout << 1 << endl;
  else cout << M[n][b] << endl;
}

main(){
  init();
  for ( int i = 1; read(); i++ ){
    cout << "Case " << i << ": ";
    work();
  }
}
// @end_of_source_code
