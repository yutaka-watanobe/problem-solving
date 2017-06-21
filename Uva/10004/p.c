// @JUDGE_ID:  17051CA  10004  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<slist>
#include<vector>
#include<queue>

#define EMPTY 0
#define BLACK 1
#define WHITE 2

class graph {
 public:
  vector<slist<int> > adj;
  vector<slist<int>::iterator> pos;
  
  graph(){}
  graph(int n){ resize(n); }

  void resize(int n){
    adj.resize(n), pos.resize(n); 
    for(int i=0; i<n; i++){
      adj[i].clear();
    }
  }
  
  int size(){ return adj.size(); }

  void insert(int i, int j){
    adj[i].push_front(j);
  }
  
  int next(int i){ 
    if(pos[i]==adj[i].end()) return -1;
    return *pos[i]++; 
  }
  
  void reset(int i){ pos[i] = adj[i].begin(); }
  void reset(){ for(int i=0; i<size(); i++) reset(i); }

  void clear(){ adj.clear(), pos.clear(); }
};

graph g;
int n;
bool bfs(graph &g);

int read(){
  cin >> n;
  if(n==0) return 0;
  return 1;
}

void work(){
  int k;
  g = graph(n);

  cin >> k;
  int a, b;
  for(int i=0; i<k; i++){
    cin >> a >> b;
    g.insert(a, b);
    g.insert(b, a);
  }

  bool bicolorable = bfs(g);
  if(bicolorable) cout << "BICOLORABLE." << endl;
  else cout << "NOT BICOLORABLE." << endl;

}

bool bfs(graph &g){
  int s = 0;
  vector<int> pi, d;
  vector<int> color;

  queue<int> q;
  int u, v;

  pi.resize(g.size(), -1);
  d.resize(g.size(), 0);
  color.resize(g.size(), EMPTY);

  q.push(s);
  d[s] = 1;
  color[s] = BLACK;

  g.reset();
  while(!q.empty()){
    u = q.front(), q.pop();
    while((v=g.next(u))!=-1){
      if(color[u]==color[v]) return false;
      if(!d[v]){
	d[v] = d[u]+1;
	pi[v] = u;
	if(color[u]==BLACK) color[v] = WHITE;
	else color[v] = BLACK;
	q.push(v);
      }
    }
  }

  return true;
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
