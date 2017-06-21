// @JUDGE_ID:  17051CA  10178  C++
// @begin_of_source_code
/* Graph オイラーの公式 + DFS（連結性） */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h> 
#include<vector>
#include<slist>

/**
 * class: graph
 * 要件: #include <slist>
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
  graph(int n){ resize(n);}

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


int  N, E;
graph g;
int sum;

int read(){
  cin >> N >> E;
  g = graph(N);
  if(cin.eof()) return 0;
  return 1;
}

void dfs(int u, vector<int> &color, vector<int> &p){
  p.push_back(u);
  color[u] = 1;
  int v;
  while( (v=g.next(u))!=-1 ){
    if(!color[v]){
      dfs(v, color, p);
    }
  }

}

void count(vector<int> p){
  int v = p.size();
  
  int e = 0;
  for(int i=0; i<v; i++){
    e += g.adj[p[i]].size();
  }

  sum += 1 - v + e/2;
}

void work(){
  char c1, c2;
  map<char, bool> used;
  map<char, int> index;
  int id = -1;
  for(int i=0; i<E; i++){
    cin >> c1 >> c2;
    int a, b;
    if(!used[c1]){
      id++;
      a = id;
      index[c1] = a;
      used[c1] = true;
    }else{
      a = index[c1];
    }

    if(!used[c2]){
      id++;
      b = id;
      index[c2] = b;
      used[c2] = true;
    }else{
      b = index[c2];
    }

    g.insert(a, b, 1);
    g.insert(b, a, 1);
  }


  vector<int> color;
  color.resize(g.size(), false);
  vector<int> p;

  g.reset();
  sum = 0;

  for(int i=0; i<g.size(); i++){
    if(!color[i]){
      dfs(i, color, p);
      count(p);
      p.clear();
    }
  }

  cout << sum + 1 << endl;

}

main(){
  while(read()) work();
}
// @end_of_source_code
