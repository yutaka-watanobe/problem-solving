// @JUDGE_ID:  17051CA  10544  C++
// @begin_of_source_code
/* Graph */
/* Numbering the Paths */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#include<queue>

#define MAX 26

int G[MAX][MAX]; /* graph */
int G2[MAX][MAX]; /* graph */
int T[MAX]; /* cost */
int OUT[MAX]; /* out degree */
int IN[MAX]; /* in degree */
int U[MAX][MAX];

int N, M;

void init(){
  for ( int i = 0; i < N; i++ ) fill ( G[i], G[i] + N, 0 );
  for ( int i = 0; i < N; i++ ) fill ( G2[i], G2[i] + N, 0 );
  for ( int i = 0; i < N; i++ ) fill ( U[i], U[i] + N, 0 );
  fill ( T, T + N, 0 );
  fill ( OUT, OUT + N, 0 );
  fill ( IN, IN + N, 0 );
}

void read(){
  cin >> N >> M;
  init();
  string str;
  int source, target;
  for ( int i = 0; i < M; i++ ){
    cin >> str;
    source = str[0] - 'A';
    target = str[1] - 'A';
    if ( !G[source][target] ){
      OUT[ str[0] - 'A' ]++;
      IN[ str[1] - 'A' ]++;
    }
    G[source][target] = 1;
    G2[source][target] = 1;
  }
}

int getNumber( string path ){

  int cost = 0;
  int target = path[ path.size()-1 ] - 'A';

  for ( int i = 0; i < path.size()-1; i++ ){
    int next = path[i+1] - 'A';
    int source = path[i] - 'A';
    for ( int j = 0; j < next; j++ ){
      if ( G[source][j] ) cost += T[ j ];
    }
  }

  return cost + 1;
}

void createCostTable(){
  /* init */
  for ( int i = 0; i < N; i++ ){
    if ( OUT[i] == 0 ) T[i] = 1;
    else T[i] = 0;
  }

 next:;
  for ( int i = 0; i < N; i++ ){
    if ( OUT[i] == 0 && IN[i] ){
      for ( int j = 0; j < N; j++ ){
	if ( G2[j][i] ){
	  T[j] += T[i];
	  G2[j][i] = 0;
	  OUT[j]--;
	  IN[i]--;
	}
      }
      goto next;
    }
  }
}

void work(){
  
  createCostTable();
  
  int Q;
  string path;

  cin >> Q;

  for ( int i = 0; i < Q; i++ ){
    cin >> path;
    cout << path << ": " << getNumber( path ) << endl;
  }
}

main(){
  int t;
  cin >> t;
  for ( int i = 0; i < t; i++ ){
    read();
    work();
  }
}
// @end_of_source_code
