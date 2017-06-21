// @JUDGE_ID:  17051CA  208  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<slist>
#include<vector>
#include<stl.h>
#include<queue>

#define MAX 25

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

  void erase(int i, int j){
    for(slist<int>::iterator it=adj[i].begin(); it!=adj[i].end(); it++){
      if(*it==j){
	adj[i].erase(it);
	break;
      }
    }
  }

  void clear(){ adj.clear(), pos.clear(); }
};

int n;
int M[MAX][MAX];
int nodeMax;
int sum;

void dfs(graph g, int u, vector<int> color, vector<int> path){
  int v;
  color[u] = 1;
  path.push_back(u);

  if(u==n-1){
    for(int i=0; i<path.size(); i++){
      if(i!=0) cout << " ";
      cout << path[i]+1 ;
    }
    cout << endl;
    sum++;
    return;
  }

  for(int i=0; i<nodeMax; i++){     
    if(M[u][i]==1 && color[i]==0){     
      dfs(g, i, color, path);     
      }    
  }     
  
  /* g.reset();    */
  /*    while((v=g.next(u))!=-1){     */
  /*      if(color[v]==0){     */
  /*        dfs(g, v, color, path);     */
  /*      }     */
  /*    }     */
}

bool bfs(graph &g, int s, int end){
  vector<int> pi, d;
  queue<int> q;
  int u, v;

  pi.resize(g.size(), -1);
  d.resize(g.size(), 0);

  q.push(s);
  d[s] = 1;
  g.reset();
  while(!q.empty()){
    u = q.front(), q.pop();
    if(u == end) return true;
    while((v=g.next(u))!=-1){
      if(!d[v]){
	d[v] = d[u]+1;
	pi[v] = u;
	q.push(v);
      }
    }
  }
  return false;
}

graph g;

int read(){
  cin >> n;
  if(cin.eof()) return 0;
  return 1;
}

void work(){
  int a, b;
  g = graph(MAX);

  for(int i=0; i<MAX; i++){
    for(int j=0; j<MAX; j++){
      M[i][j] = 0;
    }
  }

  while(1){
    cin >> a >> b;
    if(a==0 && b==0) break;
    nodeMax = max(max(nodeMax, a), b);
    a--; b--;
    g.insert(a, b);
    g.insert(b, a);
    M[a][b] = M[b][a] = 1;
  }

  if(bfs(g, 0, n-1)){
    vector<int> color, path;
    color.resize(g.size(), 0);
    g.reset();
    sum = 0;
    dfs(g, 0, color, path);
    cout << "There are " << sum << " routes from the firestation to streetcorner " << n << "." << endl;
  }
  else{ 
    cout << "There are 0 routes from the firestation to streetcorner " << n << "." << endl;
  } 
}

main(){
  for(int i=1; read(); i++){
    cout << "CASE " << i << ":" << endl;
    work();
  }
}
// @end_of_source_code
