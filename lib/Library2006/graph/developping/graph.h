#include<stdio.h>
#include<stl.h> 
#include<vector>
#include<slist>

/**
 * class: graph
 * Í×·ï: #include <slist>
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


/* Graph Algorithm */

/* Search */
void bfs(graph &g, vector<int> &pi, vector<int> &d, int s);

