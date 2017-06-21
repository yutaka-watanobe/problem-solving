// 10986:Sending email:2.0:Dijkstra
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>

using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)

#define MAX 20000

class Edge{
public:
  int target, cost;
  Edge(int t=0, int c=0):target(t), cost(c){}
};

class State{
public:
  int node, cost;
  State(int n=0, int c=0):node(n), cost(c){}
  bool operator < (const State &s) const{
    return cost > s.cost;
  }
};

vector<Edge> adj[MAX];

int dijkstra(){
  int n, m, S, T, s, t, w;
  cin >> n >> m >> S >> T;
  rep(i, n) adj[i].clear();
  rep(i, m){
    cin >> s >> t >> w;
    adj[s].push_back(Edge(t, w));
    adj[t].push_back(Edge(s, w));
  }
  bool V[MAX]; rep(i, n) V[i] = false;
  int D[MAX]; rep(i, n) D[i] = (1<<21);

  priority_queue<State> PQ;
  PQ.push(State(S, 0));
  D[S] = 0;

  State u;
  while( !PQ.empty() ){
    u = PQ.top(); PQ.pop();
    if ( u.node == T ) return u.cost;

    V[u.node] = true;
    for ( int i = 0; i < adj[u.node].size(); i++ ){
      Edge e = adj[u.node][i];

      if ( V[e.target] ) continue;
      
      if ( D[e.target] > D[u.node] + e.cost ){
	D[e.target] = D[u.node] + e.cost;
	PQ.push(State(e.target, D[e.target]));
      }
    }
  }

  return -1;

}

main(){
  int tcase; cin >> tcase;
  rep(t, tcase){
    cout << "Case #" << t+1 << ": ";
    int cost = dijkstra();
    if ( cost < 0 ) cout << "unreachable" << endl;
    else cout << cost << endl;
  }
}
