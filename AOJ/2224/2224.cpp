#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
#define REP(i, b, e) for ( int i = b; i < (int)e; i++ )
#define rep(i, n) REP(i, 0, n)
static const int MAX = 10000;

pair<int, int> P[MAX];
vector<pair<int, double> > G[MAX];
int N, M;

double getDist(double x1, double y1, double x2, double y2){
  return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

double prim(){
  double sum = 0.0;
  priority_queue<pair<double, int> > PQ;
  bool V[MAX];
  rep(i, N) V[i] = false;

  rep(s, N){
    if ( V[s] ) continue;
    PQ.push(make_pair(0, s));
    pair<double, int> u;
    while( !PQ.empty() ){
      u = PQ.top(); PQ.pop();
      if ( V[u.second] ) continue;
      V[u.second] = true;
      sum += u.first;
      rep(i, G[u.second].size()){
	int v = G[u.second][i].first;
	double c = G[u.second][i].second;
	if ( V[v] ) continue;
	PQ.push(make_pair(c, v));
      }
    }
  }
  return sum;
}

main(){
  int s, t;
  double sum = 0;
  cin >> N >> M;
  rep(i, N) cin >> P[i].first >> P[i].second;
  rep(i, N) G[i].clear();
  rep(i, M){
    cin >> s >> t;
    s--; t--;
    double d = getDist(P[s].first, P[s].second, P[t].first, P[t].second);
    sum += d;
    G[s].push_back(make_pair(t, d));
    G[t].push_back(make_pair(s, d));
  }
  printf("%.8lf\n", sum - prim());
}
