// @JUDGE_ID:  17051CA  10520  C++
// @begin_of_source_code
/* Calculation */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#define MAX 21
typedef long long llong;

int n, an1;
llong M[MAX][MAX];

void init(){
  for ( int i = 0; i < MAX; i++ ){
    fill ( M[i], M[i] + MAX, 0 );
  }
}

int read(){
  cin >> n >> an1;
  if ( cin.eof() ) return 0;
  return 1;
}

void work(){

  M[n][1] = an1;
  llong a, b, m;
  for ( int j = 1; j <= n; j++ ){
    for ( int i = n - j + 1; i >= 1; i-- ){
      if ( i == n && j == 1 ) continue;
      if ( i >= j ){
	a = b = 0;
	if ( i == n ) a = 0;
	else{
	  for ( int k = i+1; k <= n; k++ ){
	    a = max( a, M[k][1] + M[k][j] );
	  }
	}
	if ( j==1 ) b = 0;
	else{
	  for ( int k = 1; k < j; k++ ){
	    b = max ( b, M[i][k] + M[n][k] );
	  }
	}
	
	M[i][j] = a+ b;
      }else{
	m = 0;
	for ( int k = i; k < j; k++ ){
	  m = max( m, M[i][k] + M[k+1][j] );
	}
	M[i][j] = m;
      }

      M[n-j+1][n-i+1] = M[i][j];

    }
  }

  cout << M[1][n] << endl;
}

main(){
  init();
  while ( read() ) work();
}
// @end_of_source_code
