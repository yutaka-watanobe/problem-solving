// @JUDGE_ID:  17051CA  626  C++
// @begin_of_source_code
/* DFS ?  */
/* 9.2 sec --> Very Slow!!! */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

#define MAX 101
#define NON 0
#define ASCEND 1
#define DESCEND 2

int M[ MAX ][ MAX ]; /* graph matrix */
int n;
int total;
int source;

int read(){
  if ( !( cin >> n ) ) return false;

  for ( int i = 0; i < n ; i++ ){
    for ( int j = 0; j < n; j++ ){
      cin >> M[i][j];
    }
  }

  return true;
}

void printResult( vector<int> P ){
  for ( int i = 0; i < P.size() - 1; i++ ){
    if ( i ) cout << " ";
    cout << P[i] + 1;
  }
  cout << endl;
  total++;
}

void dfs( int i, vector<int> U, vector<int> P, int state ){

  if ( P.size() == 4 ){
    if ( P[3] == P[0] ){
      printResult( P );
    }
    return ;
  }

  for ( int j = 0; j < n; j++ ){
    if ( M[i][j] && !U[j] ){
      vector<int> u;
      vector<int> p;
      u = U;
      p = P;
      u[j] = 1;
      p.push_back( j );
      if ( state == ASCEND && ( i < j || j == source ) ){
	dfs( j, u, p, ASCEND );
      } else if ( state == DESCEND && ( i < j || j == source ) ){
	dfs( j, u, p, DESCEND );
      } else {
	int s;
	if ( i < j ) s = ASCEND;
	else s = DESCEND;
	dfs( j, u, p, s );
      }
    }
  }
}

void work(){
  total = 0;
  for ( int i = 0; i < n; i++ ){
    vector<int> U, P;
    U.resize( n, false );
    P.clear();
    P.push_back( i );
    source = i;
    dfs( i, U, P, NON );
  }
  cout << "total:" << total << endl;
}

main(){
  while ( read() ){
    work();
    cout << endl;
  }
}
// @end_of_source_code
