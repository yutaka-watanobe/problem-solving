// @JUDGE_ID:  17051CA  423  C++
// @begin_of_source_code
#include<stdio.h>
#include<stl.h> 
#include<vector>
#include<slist>
#include<queue>
#include<string>
#include<iostream>

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

  int next(int i){ 
    if(pos[i]==adj[i].end()) return -1;
    return *pos[i]++; 
  }
  
  void reset(int i){ pos[i] = adj[i].begin(); }
  void reset(){ for(int i=0; i<size(); i++) reset(i); }

  void clear(){ m.clear(), adj.clear(), pos.clear(); }
};

graph g;
int n;
void dijkstra(graph &g, vector<int> &pi, vector<int> &d, int s);

void work(){
  string line;
  int k;
  cin >> n;
  g = graph(n);
  
  for(int i=1; i<n; i++){
    for(int j=0; j<i; j++){
      cin >> line;
      if(line!="x"){
	k = atoi(line.c_str());
	g.insert(i, j, k); g.insert(j, i, k);
      }
    }
  }
  vector<int> pi, d;
  dijkstra(g, pi, d, 0);
  int max = 0;
  for(int i=0; i<d.size(); i++){
    if( max < d[i] && d[i] != INT_MAX){
      max = d[i];
    }
  }
  cout << max << endl;
}

main(){
  work();
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
