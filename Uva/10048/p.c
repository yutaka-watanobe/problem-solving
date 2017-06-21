// @JUDGE_ID:  17051CA  10048  C++
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

  graph(){}
  graph(int n){ resize(n); }

  void resize(int n){
    m.resize(n), adj.resize(n), pos.resize(n); 
    for(int i=0; i<n; i++){
      m[i].resize(n);
      fill(m[i].begin(), m[i].end(), INT_MAX);
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

int C, S, Q;
graph g;

int read(){
  cin >> C >> S >> Q;
  if(C==0 && S==0 && Q==0)  return 0;
  return 1;
}

/**
 * Warshall
 */ 
void warshall(graph &g){
  for(int y=0; y<g.size(); y++){
    for(int x=0; x<g.size(); x++){
      if(g.m[x][y]){
        for(int i=0; i<g.size(); i++){
          if(g.m[y][i]){
	    int m = max(g.m[x][y], g.m[y][i]);
	    if(g.m[x][i] >  m ){
	      g.m[x][i] = m;
	      g.m[i][x] = m;
	    }
	  }
        }
      }
    }
  }
}

void work(){
  g = graph(C);

  int ii, jj, k;

  for(int i=0; i<S; i++){
    cin >> ii >> jj >> k;
    ii--; jj--;
    g.insert(ii, jj, k);
    g.insert(jj, ii, k);
  }

  warshall(g);

  for(int i=0; i<Q; i++){
    cin >> ii >> jj;
    int e = g.m[ii-1][jj-1];
    if(e==INT_MAX) cout << "no path" << endl;
    else cout << e << endl;
  }
}

main(){
  for(int i=1; read(); i++){
    if(i!=1) cout << endl;
    cout << "Case #" << i << endl;
    work();
  }
}
// @end_of_source_code
