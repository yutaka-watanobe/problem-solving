// @JUDGE_ID:  17051CA  10285  C++
// @begin_of_source_code
/* Longest Path */
/* 値の小さいものからみていき （トポロジカルソートのように）*/
/* Relax をする */
/* DAG longest path のようなもの */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#define MAX 105

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int R, C;
string name;
int G[MAX][MAX];
int T[MAX][MAX];

vector<pair<int, pair<int, int> > > Node;

int read(){
  cin >> name >> R >> C;
  Node.clear();
  int k;
  for ( int i = 0; i < R; i++ ){
    for ( int j = 0; j < C; j++ ) {
      cin >> k;
      G[i][j] = k;
      T[i][j] = 1;
      pair<int, pair<int, int> > p;
      p.first = k;
      p.second = pair<int, int>(i, j);
      Node.push_back(p);
    }
  }
  
}

void work(){
  sort( Node.begin(), Node.end() );

  pair<int, int> p;
  int ni, nj;

  for ( int n = 0; n < Node.size(); n++){
    p = Node[n].second;
    int i = p.first;
    int j = p.second;

    for ( int d = 0; d < 4; d++ ){
      ni = i + dx[d];
      nj = j + dy[d];
      if ( 0 <= ni && 0 <= nj && ni < R && nj < C ){
	if ( G[i][j] < G[ni][nj] ){
	  T[ni][nj] = max( T[ni][nj], T[i][j] + 1 );
	}
      }
    }

  }

  int maxV = 0;
  for ( int i = 0; i < R; i++ ) {
    for ( int j = 0; j < C; j++ ){
      maxV = max(maxV, T[i][j]);
    }
  }

  cout << name << ": " << maxV << endl;

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
