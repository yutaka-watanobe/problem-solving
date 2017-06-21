// @JUDGE_ID:  17051CA  280  C++
// @begin_of_source_code
/* Graph Warshal */
/* 2.934 sec --> Use Cash!! */
#include<stdio.h>
#include<iostream>
#include<stl.h>
#include<vector>
#define MAX 105

int M[MAX][MAX];
bool U[MAX];
vector<int> P[MAX];

int n;
int read(){
  cin >> n;
  if ( n == 0 ) return false;

  for ( int i = 1; i <= n; i++ ){
    for ( int j = 1; j <= n; j++ ){
      M[i][j] = 0;
    }
  }

  /* read graph */
  int i, k;
  while ( 1 ){
    cin >> i;
    if ( i == 0 ) return true;
    while ( 1 ){
      cin >> k;
      if ( k == 0 ) goto next;
      M[i][k] = 1;
    }
  next:;
  }
}

/**
 * Warshall
 */ 
void warshall(){
  for( int y = 1; y <= n ; y++ ){
    for( int x = 1; x <= n; x++ ){
      if( M[x][y] ){
	for( int i = 1; i <= n; i++ ){
	  if( M[y][i] )  M[x][i] = 1;
	}
      }
    }
  }
}

void calculation( int i ){
  vector<int> p;

  if ( U[ i ] ) p = P[i];
  else{
    for ( int j = 1; j <= n; j++ ){
      if ( !M[i][j] ) p.push_back( j );
    }
    U[ i ] = true;
    P[ i ] = p;
  }

  cout << p.size();
  for ( int i = 0; i < p.size(); i++ ) cout << " " << p[i];
  cout << endl;
}

void work(){
  int k;
  warshall();

  fill ( U, U + n + 1, false );

  cin >> k;

  for ( int i = 0; i < k; i++ ){
    int x;
    cin >> x;
    calculation( x );
  }
}

main(){
  while ( read() ) work();
}
// @end_of_source_code
