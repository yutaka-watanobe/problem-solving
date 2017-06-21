#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

#define MAX_V 100
#define INF (1<<21)

//struct edge { int to, cap, cost, rev; };
class edge { 
public:
  int to, cap, rev;
  double cost;
  edge(){}
  edge(int t, int c, double s, int r):to(t), cap(c), cost(s), rev(r){}
};

int V;
vector<edge> G[MAX_V];
//int dist[MAX_V];
double dist[MAX_V];
int prevv[MAX_V], preve[MAX_V];

//void add_edge( int from, int to, int cap, int cost){
void add_edge( int from, int to, int cap, double cost){
  G[from].push_back(edge(to, cap, cost, G[to].size()));
  G[to].push_back(edge(from, 0, -cost, G[from].size()-1));
}

double min_cost_flow(int s, int t, int f ){
  //int res = 0;
  double res = 0;
  while( f > 0) {
    fill(dist, dist + V, INF);
    dist[s] = 0;
    bool update = true;
    while(update){
      update = false;
      for ( int v = 0; v < V; v++ ){
	if ( dist[v] == INF ) continue;
	for ( int i = 0; i < G[v].size(); i++ ){
	  edge &e = G[v][i];
	  if ( e.cap > 0 && dist[e.to] > dist[v] + e.cost ){
	    dist[e.to] = dist[v] + e.cost;
	    prevv[e.to] = v;
	    preve[e.to] = i;
	    update = true;
	  }
	}
      }
    }
    
    if ( dist[t] == INF ) return -1;
    
    int d = f;
    for ( int v = t; v != s; v = prevv[v] ){
      d = min(d, G[prevv[v]][preve[v]].cap);
    }
    f -= d;
    res += d * dist[t];
    for ( int v = t; v != s; v = prevv[v] ){
      edge &e = G[prevv[v]][preve[v]];
      e.cap -= d;
      G[v][e.rev].cap += d;
    }
  }
  return res;
}

main(){
  int n, m, c, s, t;
  double d;
  while(1){
    cin >> n >> m;
    if ( n == 0 && m == 0 ) break;
    V = n + m + 2;
    for ( int i = 0; i < V; i++ ) G[i].clear();

    for ( int t = 1; t <= n; t++ ){
      for ( int s = 1; s <= m; s++ ){
	cin >> d;
	add_edge(s, t+m, 1, d);
      }
    }

    for ( int i = 1; i <=m; i++ ) add_edge(0, i, 1, 0);
    for ( int i = 1; i <=n; i++ ) add_edge(i+m, V-1, 1, 0);
    double mc = min_cost_flow(0, V-1, n)/n;
    printf("%.2lf\n", mc + 0.000000000001);
  }

}
