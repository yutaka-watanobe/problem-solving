// @JUDGE_ID:  17051CA  193  C++
// @begin_of_source_code
#include<stdio.h>
#include<stl.h>
#include<slist>
#include<queue>
#define BLACK 1;

class graph{
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
  
  void reset(int i){ pos[i] = adj[i].begin(); }
  void reset(){ for(int i=0; i<size(); i++) reset(i); }


};

void work();

int m, n, k;
graph g;

void work(){
  int i, j;
  cin >> n >> k;
  g = graph(n);
  for(int a=0; a<k; a++){
    cin >> i >> j;
    g.insert(i, j, 1);
    g.insert(j, i, 1);
  }

  

  
}

void bfs(graph &g, vector<int> &pi, vector<int> &d, int s);

void bfs(graph &g, vector<int> &pi, vector<int> &d, int s){
  queue<int> q;
  int u, v;

  pi.resize(g.size());
  fill(pi.begin(), pi.end(), -1);
  d.resize(g.size());
  fill(d.begin(), d.end(), 0);

  q.push(s);
  d[s] = 1;
  g.reset();
  while(!q.empty()){
    u = q.front(), q.pop();
    while( (v=g.next(u) ) != -1){
      if(!d[v]){
	d[v] = d[u]+1;
	pi[v] = u;
	q.push(v);
      }
    }
  }
}

main(){
  cin >> m;
  for(int i=0; i<m; i++){
    work();
  }
}
// @end_of_source_code
