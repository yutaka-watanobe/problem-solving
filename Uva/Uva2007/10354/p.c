// @JUDGE_ID:  17051CA  10354  C++
// @begin_of_source_code
/* Graph Shortest Path */
/* There are some shortest Path!! */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h> 
#include<vector>
#include<slist>

/**
 * class: graph
 * usage: #include <slist>
 */
class graph {
 public:
  vector<vector<int> > m;
  vector<slist<int> > adj;
  vector<slist<int>::iterator> pos;
  
  /**
   * Constructor
   * @param the number of nodes
   */
  graph(){}
  graph(int n){ resize(n); }

  /** 
   * @param the number of node
   */ 
  void resize(int n){
    m.resize(n), adj.resize(n), pos.resize(n); 
    for(int i=0; i<n; i++){
      m[i].resize(n);
      fill(m[i].begin(), m[i].end(), 0);
      adj[i].clear();
    }
  }
  
  /**
   * @return the number of node
   */
  int size(){ return m.size(); }

  /**
   * insert e between i and j;
   * @param i, j, e(weight)
   * if it is non-weighted graph, e should be 1.
   * if it is undirected graph, Do insert(i, j, e) and insert(j, i, e).
   */
  void insert(int i, int j, int e){
    m[i][j] = e;
    adj[i].push_front(j);
  }
  
  /**
   * refer to weight.
   * usage: using g[i][j], edge weight can be refered.
   */
  vector<int> & operator[](int i){ return m[i]; }

  /**
   * refere to adjacency list of node i, and move one.
   */
  int next(int i){ 
    if(pos[i]==adj[i].end()) return -1;
    return *pos[i]++; 
  }
  
  /**
   * begin again of adjacency list reference of node i.
   */
  void reset(int i){ pos[i] = adj[i].begin(); }

  /**
   * begin again of adjacency list reference of all node.
   * Before use graph, it must be called !!!.
   */
  void reset(){ for(int i=0; i<size(); i++) reset(i); }

  /* less used methods */
  void erase(int i, int j){
    m[i][j] = 0;
    for(slist<int>::iterator it=adj[i].begin(); it!=adj[i].end(); it++){
      if(*it==j){
	adj[i].erase(it);
	break;
      }
    }
  }

  /** clear all nodes */
  void clear(){ m.clear(), adj.clear(), pos.clear(); }

  graph & operator=(const graph &g){
    m = g.m;
    adj = g.adj;
    pos.resize(m.size());
    for(int i=0; i<m.size(); i++)
      pos[i] = adj[i].begin();
  }
};


/**
 * Dijkstra
 * @param 
 *   pi:   previous node
 *         -1 --> source and not visited node
 *   cost: distance from source
 *          0 --> source
 *         INT_MAX --> not visited node
 * Solved 10171,
 */ 
void dijkstra(graph &g, vector<int> &pi, vector<int> &cost, int s, vector<bool> &bossV){
  cost.resize(g.size(), INT_MAX);
  pi.resize(g.size(), -1);
  vector<int> visited(g.size(), 0);
  
  if(bossV[s]) return;

  cost[s] = 0;
  g.reset();
  while(1){
    int min = INT_MAX;
    int x;
    for(int i=0; i<g.size(); i++){
      if(visited[i]==0 && bossV[i]==0 && min > cost[i] ){
	min = cost[i];
	x = i;
      }
    }

    if( min == INT_MAX ) break;

    visited[x] = 1;

    int v;
    while((v=g.next(x))!=-1){
      if( !visited[v] && !bossV[v] && cost[x] + g.m[x][v] < cost[v] ){ 
	cost[v] = cost[x] + g.m[x][v];
	pi[v] = x;
      }
    }

  }
}

void dijkstra2(graph &g, vector<vector<int> > &pi, vector<int> &cost, int s){
  cost.resize(g.size(), INT_MAX);
  pi.resize(g.size());
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
    int dist;
    while((v=g.next(x))!=-1){
      if( !visited[v] ){
	dist = cost[x] + g.m[x][v];
	if( dist == cost[v] ){
	  pi[v].push_back(x);
	}else if( dist < cost[v] ){ 
	  cost[v] = dist;
	  pi[v].clear();
	  pi[v].push_back(x);
	}
      }
    }

  }
}

void printPath(vector<vector<int> > &pi, int p, vector<bool> &bV){
  /* cout << p << " "; */
  bV[p] = true;
  for(int j=0; j<pi[p].size(); j++){
    printPath(pi, pi[p][j], bV);
  }
}

int P, R, BH, OF, YH, M;
graph g;
vector<bool> bossVisited;

int read(){
  cin >> P >> R >> BH >> OF >> YH >> M;
  if(cin.eof()) return 0;
  BH--; OF--; YH--; M--;
  g = graph(P);
  bossVisited.clear();
  bossVisited.resize(P, false);
  
  int a, b, e;
  for(int i=0; i<R; i++){
    cin >> a >> b >> e;
    a--; b--;
    g.insert(a, b, e);
    g.insert(b, a, e);
  }
  return 1;

}

void work(){
  vector<int>  pi, cost;
  vector<vector<int> > pi2;

  dijkstra2(g, pi2, cost, BH);

  printPath(pi2, OF, bossVisited);

  pi.clear();
  cost.clear();

  dijkstra(g, pi, cost, YH, bossVisited);
  
  if(cost[M]==INT_MAX) cout << "MISSION IMPOSSIBLE." << endl;
  else cout << cost[M] << endl;

}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
