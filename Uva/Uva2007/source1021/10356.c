// @JUDGE_ID:  17051CA  10356  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h> 
#include<vector>
#include<slist>
#include<queue>

class graph {
 public:
  vector<vector<int> > m;
  vector<slist<int> > adj;
  vector<slist<int>::iterator> pos;

  graph(){}
  graph(int n){ resize(n); }

  void resize(int n){
    m.resize(n), adj.resize(n), pos.resize(n); 
    for(int i=0; i<n; i++){
      m[i].resize(n);
      fill(m[i].begin(), m[i].end(), 0);
      adj[i].clear();
    }
  }

  int size(){ return m.size(); }

  void insert(int i, int j, int e){
    m[i][j] = e;
    adj[i].push_front(j);
  }

  vector<int> & operator[](int i){ return m[i]; }

  int next(int i){ 
    if(pos[i]==adj[i].end()) return -1;
    return *pos[i]++; 
  }

  void reset(int i){ pos[i] = adj[i].begin(); }
  void reset(){ for(int i=0; i<size(); i++) reset(i); }

  void clear(){ m.clear(), adj.clear(), pos.clear(); }
};

graph g, g2;
void dijkstra(graph &g, vector<int> &pi, vector<int> &d, int s);
int n, r;

int read(){
  cin >> n >> r;
  if( cin.eof() ) return 0;
  return 1;
}

void work(){
  int a, b, k;
  g = graph(n);
  g2 = graph(n);

  for(int i=0; i<r; i++){
    cin >> a >> b >> k;
    g.insert(a, b, k); g.insert(b, a, k);
  }
  int v1, v2;
  int e1, e2;
  g.reset();
  for(int i=0; i<n; i++){
    while((v1=g.next(i))!=-1){
      e1 = g.m[i][v1];
      while((v2=g.next(v1))!=-1){
	e2 = g.m[v1][v2];
	int ee;
	if(g2[i][v2]) ee = min(g2[i][v2], e1+e2);
	else ee = e1+e2;
	g2.insert(i, v2, ee);
	g2.insert(v2, i, ee);
      }
      g.reset(v1);
    }
    g.reset(i);
  }

  vector<int> pi, d;
  dijkstra(g2, pi, d, 0);

  if(pi[n-1]==-1){
    cout << "?" << endl;
  }else{
    cout << d[n-1] << endl;
  }
}

main(){
  for(int i=1; read(); i++){
    cout << "Set #" << i << endl;
    work();
  }
}

/**
 * Dijkstra
 * @param 
 *   pi:   previous node
 *         -1 --> source and not visited node
 *   cost: distance from source
 *          0 --> source
 *         INT_MAX --> not visited node
 */ 
void dijkstra(graph &g, vector<int> &pi, vector<int> &cost, int s){
  cost.resize(g.size(), INT_MAX);
  pi.resize(g.size(), -1);
  vector<int> visited(g.size(), 0);
  
  cost[s] = 0;
  g.reset();
  while(1){
    int min = INT_MAX;
    int x;
    for(int i=0; i<g.size(); i++){
      if(visited[i]==0 && min > cost[i] ){
	min = cost[i];
	x = i;
      }
    }

    if( min == INT_MAX ) break;

    visited[x] = 1;

    int v;
    while((v=g.next(x))!=-1){
      if( cost[x] + g.m[x][v] < cost[v] ){
	cost[v] = cost[x] + g.m[x][v];
	pi[v] = x;
      }
    }

  }
}

// @end_of_source_code
