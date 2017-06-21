// @JUDGE_ID:  17051CA  103  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
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


graph g;
int N, M;

void sslp(graph &g, vector<int> &pi, vector<int> &d, int s);
int read(){
  cin >> N >> M;
  if(cin.eof()) return 0;
  return 1;
}

void work(){
  int k;
  vector<vector<int> > v;
  v.resize(N);
  g = graph(N);

  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      cin >> k;
      v[i].push_back(k-1);
    }
    sort(v[i].begin(), v[i].end());
  }

  vector<int> v1, v2;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      v1 = v[i];
      v2 = v[j];
      
      bool nest = true;
      for(int l=0; l<M; l++){
	if(!(v1[l] < v2[l])){
	  nest = false;
	  goto next;
	}
      }

    next:;
      if(nest){
	g.insert(i, j, 1);
      }
    }
  }

  int m = -1;
  vector<int> pi, d, path, gp;
  int pos;
  for(int i=0; i<g.size(); i++){
    sslp(g, pi, d, i);

    for(int j=0; j<g.size(); j++){
      if(m<d[j]){
        m = d[j];
        path.clear();
	gp = pi;
	pos = j;
      }
    }
  }
  path.clear();

   for(int k=pos; k!=-1; k=gp[k]){
     path.push_back(k);
   }

  reverse(path.begin(), path.end());

  cout << path.size() << endl;
  for(int i=0; i<path.size(); i++){
    if(i) cout << " ";
    cout << path[i]+1;
  }
  cout << endl;

}

main(){
  while(read()){
    work();
  }
}

int inf = INT_MIN;

int _sslp(graph &rg, vector<int> &pi, vector<int> &d, int u, int s){
  int m = inf, tmp, v;
  
  while((v=rg.next(u))!=-1){
    if(d[v]!=inf) tmp = d[v];
    else tmp = _sslp(rg, pi, d, v, s);

    if(tmp==inf) continue;

    tmp += rg[u][v];

    if(m<tmp){
      m = tmp;
      pi[u] = v;
    }
  }
  return d[u] = m;
}

void sslp(graph &g, vector<int> &pi, vector<int> &d, int s){
  graph rg(g.size());
  int v;

  pi.assign(g.size(), -1);
  d.assign(g.size(), inf);

  g.reset();
  for(int i=0; i<g.size(); i++){
    while((v=g.next(i))!=-1){
      rg.insert(v, i, g[i][v]);
    }
  }

  d[s] = 0;
  rg.reset();
  for(int i=0; i<g.size(); i++){
    if(d[i]==inf) _sslp(rg, pi, d, i, s);
  }
}
// @end_of_source_code
