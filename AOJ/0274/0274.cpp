#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define DMAX 10
#define KMAX 10
#define SMAX 60000
#define LMAX 10
#define MMAX 200
#define PMAX 200

#define INFTY (1<<21)

class edge { 
public:
  int to, cap, rev, cost;
  edge(){}
  edge(int t, int c, int s, int r):to(t), cap(c), cost(s), rev(r){}
};

const int MAX_V = 3 + PMAX + MMAX;

int D, K, L, NS, M, N, P;
int GS[MMAX]; // goal state
int TS[PMAX]; // template state
int C[DMAX][KMAX];
int dp[2][SMAX][LMAX+1];
int dp2[SMAX];

int V;
vector<edge> G[MAX_V];
int dist[MAX_V];
int h[MAX_V]; // potentail
int prevv[MAX_V], preve[MAX_V];

void add_edge( int from, int to, int cap, int cost){
  G[from].push_back(edge(to, cap, cost, G[to].size()));
  G[to].push_back(edge(from, 0, -cost, G[from].size()-1));
}

int min_cost_flow(int s, int t, int f){
  int res = 0;
  fill(h, h+V, 0);
  while( f > 0 ){
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
    fill(dist, dist + V, INFTY );
    dist[s] = 0;
    que.push(make_pair(0, s));
    while(!que.empty()){
      pair<int, int>  p = que.top(); que.pop();
      int v = p.second;
      if ( dist[v] < p.first) continue;
      for ( int i = 0; i < G[v].size(); i++ ){
	edge &e = G[v][i];
	if ( e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to] ){
	  dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
	  prevv[e.to] = v;
	  preve[e.to] = i;
	  que.push(make_pair(dist[e.to], e.to));
	}
      }
    }
    if ( dist[t] == INFTY ){
      return -1;
    }
    for ( int v = 0; v < V; v++ ) h[v] += dist[v];

    int d = f;
    for ( int v = t; v != s; v = prevv[v] ){
      d = min(d, G[prevv[v]][preve[v]].cap);
    }
    f -= d;
    res += d * h[t];
    for ( int v = t; v != s; v = prevv[v]){
      edge &e = G[prevv[v]][preve[v]];
      e.cap -= d;
      G[v][e.rev].cap += d;
    }
  }
  return res;
}
int min_cost_flow_bell(int s, int t, int f ){
  int res = 0;
  while( f > 0) {
    fill(dist, dist + V, INFTY);
    dist[s] = 0;
    bool update = true;
    while(update){
      update = false;
      for ( int v = 0; v < V; v++ ){
	if ( dist[v] == INFTY ) continue;
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
    
    if ( dist[t] == INFTY ) return -1;
    
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

void parse( int n ){
  if ( n) parse(n/3);
  cout << n%3;
}

int weight(int n, int b){
  const int t[] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049};
  return (n%t[b+1])/t[b];
}

int power(int x, int p){
  int f = 1;
  for ( int i = 0; i < p; i++ ) f *= x;
  return f;
}

void createCostTable(){
 const int t[] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147};
 
  for ( int j = 0; j < NS; j++ ) dp2[j] = INFTY;
  
dp2[0] = 0;
  for ( int i = 0; i < D; i++ ){
    for ( int l = 0; l < L; l++ ){
      for ( int s = NS-1; s >= 0 ; s-- ){
	for ( int k = 0, p = 1; k < K; k++, p *= 3 ){
	  if ( (s%t[k+1])/t[k] >= 2 ) continue;
	  int nx = s + p;
	  if ( nx >= NS ) continue;
	  dp2[nx] = min(dp2[nx], dp2[s] + C[i][k] );
	}
      }
    }
  }
}
 
int getCost(int st){
  return dp2[st];
}

void parse(int s1, int s2, int k, int p, int &sum, bool &res ){
  if ( k ) parse(s1/3, s2/3, k-1, p*3, sum, res);
  int diff = s2%3 - s1%3;
  if ( diff < 0 ) res = false;
  else sum += diff*p;
}

int getRemCost(int s1, int s2){
  int sum = 0;
  bool res = true;
  parse(s1, s2, K, 1, sum, res);
  return res?getCost(sum):INFTY;
}
 
main(){
  while(1){
    cin >> D >> K >> L;
    if ( D == 0 && K == 0 && L == 0 ) break;
    
    for ( int i = 0; i < D; i++ ){
      for ( int j = 0; j < K; j++ ){
	cin >> C[i][j];
      }
    }
    
    NS = power(3, K);
    
    createCostTable();
    
    cin >> M >> N >> P;
    
    int b;
    for ( int i = 0; i < M; i++ ){
      
      int st = 0;
      for ( int j = 0, p = 1; j < K; j++, p *= 3){
	cin >> b;
	st += b * p;
      }
      GS[i] = st;
    }
    
    for ( int i = 0; i < P; i++ ){
      int st = 0;
      for ( int j = 0, p = 1; j < K; j++, p *= 3){
	cin >> b;
	st += b * p;
      }
      TS[i] = st;
    }
    
    V = 2 + 1 + P + M;
    for ( int i = 0; i < V; i++ ) G[i].clear();
    add_edge(0, 1, INFTY, 0);

    for ( int i = 0; i < P; i++ ) {
      add_edge(0, 2 + i, 1, 0);
    }
    
    for ( int i = 0; i < M; i++ ){
      if ( getCost(GS[i]) >= INFTY ) continue;
      add_edge(1, 2 + P + i, 1, getCost(GS[i]));
    }

    
    for ( int i = 0; i < P; i++ ){
      for ( int j = 0; j < M; j++ ){
	int pcost = getRemCost(TS[i], GS[j]);
	if ( pcost == INFTY ) continue;
	add_edge(2 + i, 2 + P + j, 1, pcost); 
      }
    }

    for ( int i = 0; i < M; i++ ){
      add_edge(2 + P + i, V-1, 1, 0);
    }
    
    int ans = min_cost_flow(0, V-1, N);
    if ( ans == INFTY ) ans = -1;
    cout << ans << endl;
  }
}
