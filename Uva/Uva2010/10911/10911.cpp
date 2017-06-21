// 10911:Forming Quiz Teams:3.0:DB + BFS
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#include<cfloat>

using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)

#define MAX 16

double D[MAX][MAX];
int N;

double getDist(pair<int, int> p1, pair<int, int> p2){
  return sqrt((p1.first-p2.first)*(p1.first-p2.first) +
	      (p1.second-p2.second)*(p1.second-p2.second));
}

void compute(){
  double T[(1<<MAX)];
  bool V[(1<<MAX)];
  rep(i, (1<<N)) {
    T[i] = FLT_MAX;
    V[i] = false;
  }
  queue<int> q;
  
  for ( int i = 0; i < N-1; i++ ){
    for ( int j = i+1; j < N; j++ ){
      int mask = ((1<<i) | (1<<j));
      V[mask] = true;
      T[mask] = D[i][j];
      q.push(mask);
    }
  }

  int f1, f2;
 
  while(!q.empty()){

    int p = q.front(); q.pop();

    for ( int i = 0; i < N-1; i++ ){
      f1 = (1<<i);
      if ( (f1 & p) != 0 ) continue;
      for ( int j = i+1; j < N; j++ ){
	f2 = (1<<j);
	if ( (f2 & p) != 0 ) continue;
	int mask = (f1 | f2);
	int value = (mask | p);

	T[value] = min(T[value], T[p] + D[i][j]);

	if ( !V[value] ) {
	  V[value] = true;
	  q.push(value);
	}

      }
    }
  }

  printf("%.2lf\n", T[(1<<N)-1]);
}

main(){
  string name;
  int x, y;
  pair<int, int> P[MAX];
  int tcase = 1;
  int n;
  while( cin >> n && n ){
    cout << "Case " << tcase++ << ": ";
    N = 2*n;
    rep(i, N){
      cin >> name >> x >> y;
      P[i] = make_pair(x, y);
    }
    rep(i, N) rep(j, N) D[i][j] = getDist(P[i], P[j]);
    compute();
  }
}
