/********************************************
 * Depth First Search ( using recursion )
 ********************************************/
#include "graph.h"
#include<iostream>

/*
 * recursive function that is used below.
 */
void _dfs(graph &g, vector<int> &color, vector<int> &pi, vector<int> &d, 
	  vector<int> &f, int &time, int u){
  int v;

  color[u] = 1, d[u] = ++time;

  /* To keep order !need change !! 
   *
  for(int i=0; i<nodeMax; i++){
    if(M[u][i]==1 && color[i]==0){
      dfs(g, i, color, path);   
    }    
  } 
  */


  while((v=g.next(u))!=-1){
    if(!color[v]){
      pi[v] = u;
      _dfs(g, color, pi, d, f, time, v);
    }
  }
  f[u] = ++time;
}

/*
 * DFS (Depth First Search)
 * d: order of find ( to be Gray )
 * f: order of search ( to be Black )
 * color: whether visited or not
 * pi: same as bfs
 * requirement: function _dfs
 */
void dfs(graph &g, vector<int> &pi, vector<int> &d, vector<int> &f){
  int time = 0;
  vector<int> color(g.size(), 0);
 
  pi.resize(g.size(), -1);
  d.resize(g.size(), 0);
  f.resize(g.size(), 0);

  g.reset();
  for(int i=0; i<g.size(); i++){
    if(!color[i]) _dfs(g, color, pi, d, f, time, i);
  }
}

graph g;
int n;

void dfs(graph &g, vector<int> &pi, vector<int> &d, vector<int> &f);
void _dfs(graph &g, vector<int> &color, vector<int> &pi, vector<int> &d, 
	  vector<int> &f, int &time, int u);

void read(){
  int i, j;
  cin >> n;
  g = graph(n);
  while(1){
    cin >> i >> j;
    if( cin.eof() ) break;
    g.insert(i, j, 1); g.insert(j, i, 1); 
  }
}

main(){
  read(); /* read graph */
  vector<int> pi, d, f;
  g.reset();
  dfs(g, pi, d, f);
  cout << "pi: "; for(int i=0; i<n; i++) cout << pi[i] << " ";
  cout << endl;
  cout << "d : "; for(int i=0; i<n; i++) cout << d[i] << " ";
  cout << endl;
  cout << "f : "; for(int i=0; i<n; i++) cout << f[i] << " ";
  cout << endl;
}


