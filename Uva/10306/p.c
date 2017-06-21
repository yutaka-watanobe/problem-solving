// @JUDGE_ID:  17051CA  10306  C++
// @begin_of_source_code
/* BFS ?? */
/* 0.182 sec */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stl.h>
#define MAX 301

class SortCriterion{
 public:
  bool operator() ( const pair<int, int> p1, const pair<int, int> p2 ) const {
    if( p1.first+p1.second > p2.first+p2.second ) return true;
    else return false;
  }
};

vector<pair<int, int> > V;
map<pair<int, int>, bool> U;

int cost[MAX][MAX];

int m, S;
int min_cost;

int read(){
  cin >> m >> S;
  V.clear();
  int a, b;
  for ( int i = 0; i < m; i++ ){
    cin >> a >> b;
    V.push_back ( pair<int, int>(a, b) );
  }
  sort ( V.begin(), V.end(), SortCriterion() );
  for ( int i = 0; i < MAX; i++ ){
    fill ( cost[i], cost[i] + MAX, INT_MAX );
  }
}

int bfs(){
  
  queue<pair<int, int> > q;
  pair<int, int> u, v;
  int x, y;
  q.push( pair<int, int>(0, 0) );
  cost[0][0] = 0;

  while ( !q.empty() ){
    u = q.front(); q.pop();

    x = u.first; y = u.second;
    
    if ( x*x + y*y == S ){
      return cost[x][y];
    }

    for ( int i = 0; i < m; i++ ){
      x = u.first + V[i].first;
      y = u.second + V[i].second;
      if ( x < MAX && y < MAX && cost[x][y] == INT_MAX ){
	cost[x][y] = cost[u.first][u.second] + 1;
	q.push( pair<int, int>(x, y) );
      }
    }
  }

  return INT_MAX;
}

void work(){
  S = S*S;

  min_cost = bfs();

  if ( min_cost == INT_MAX ){
    cout << "not possible" << endl;
  } else {
    cout << min_cost << endl;
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
