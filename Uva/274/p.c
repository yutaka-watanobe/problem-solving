// @JUDGE_ID:  17051CA  274  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h> 
#include<vector>
#include<slist>
#include<queue>

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

void bfs(graph &g, vector<bool> &can_visit, int s){
  queue<int> q;
  vector<int> pi, d;
  int u, v;

  pi.resize(g.size(), -1);
  d.resize(g.size(), 0);

  q.push(s);
  d[s] = 1;
  g.reset();
  while(!q.empty()){
    u = q.front(), q.pop();
    can_visit[u] = true;
    while((v=g.next(u))!=-1){
      if(!d[v]){
	d[v] = d[u]+1;
	pi[v] = u;
	q.push(v);
      }
    }
  }
}

bool bfs2(graph &g, vector<bool> can_visit_c, int s, int e){
  queue<int> q;
  vector<int> pi, d;
  int u, v;

  pi.resize(g.size(), -1);
  d.resize(g.size(), 0);

  q.push(s);
  d[s] = 1;
  g.reset();
  while(!q.empty()){
    u = q.front(), q.pop();
    if(u==e) return true;
    while((v=g.next(u))!=-1){
      if(!d[v] && !can_visit_c[v]){
	d[v] = d[u]+1;
	pi[v] = u;
	q.push(v);
      }
    }
  }
  return false;
}

int n, c, m;
string line;
vector<bool> can_visit_c, can_visit_m;

graph g_c, g_m;

void read(){
  getline(cin, line);
  sscanf(line.c_str(), "%d %d %d", &n, &c, &m);

  g_c = graph(n);
  g_m = graph(n);

  int A, B;
  
  while(1){
    getline(cin, line);
    sscanf(line.c_str(), "%d %d", &A, &B);
    if(A==-1 && B==-1) break;
    A--; B--;
    g_c.insert(A, B);
  }

  while(1){
    getline(cin, line);
    if(line.size()==0 || cin.eof()) break;
    sscanf(line.c_str(), "%d %d", &A, &B);
    A--; B--;
    g_m.insert(A, B);
  }

}

void work(){
  can_visit_c.clear();
  can_visit_m.clear();
  can_visit_c.resize(n, false);
  can_visit_m.resize(n, false);

  bfs(g_c, can_visit_c, c-1);
  bfs(g_m, can_visit_m, m-1);

  bool meet = false;
  for(int i=0; i<n; i++){
    if(can_visit_c[i] && can_visit_m[i]){ meet = true; break; }
  }

  cout << ( meet ? "Y " : "N ");

  vector<int> start;
  int v;
  g_m.reset();
  while( (v=g_m.next(m-1))!=-1){
    if(!can_visit_c[v] )start.push_back(v);
  }
  
  bool walk = false;
  if(!(c==m || can_visit_c[m-1])){
    for(int i=0; i<start.size(); i++){
      if(bfs2(g_m, can_visit_c, start[i], m-1)) {walk = true; break;}
    }
  }

  cout << (walk ? "Y" : "N") << endl;
}

main(){
  int testCase;
  getline(cin, line);
  testCase = atoi(line.c_str());

  getline(cin, line);

  for(int i=0; i<testCase; i++){
    if(i!=0) cout << endl;
    read();
    work();
  }
}
// @end_of_source_code
