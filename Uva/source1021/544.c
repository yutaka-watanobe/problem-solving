// @JUDGE_ID:  17051CA  544  C++
// @begin_of_source_code
#include<stdio.h>
#include<stl.h> 
#include<vector>
#include<slist>
#include<queue>
#include<iostream>
#include<string>
#include<map>

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
      fill(m[i].begin(), m[i].end(), -1);
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

graph g;
int n, r;
map<string, int> mp;

int bfs_transive(graph &g, int, int);

int read(){
  cin >> n >> r;
  if(n==0 && r==0) return 0;
  return 1;
}

void work(){
  int i, j, e, source, target;
  string s1, s2;
  set<string> city;
  int size;
  int id = 0;
  g = graph(n);
  for(int i=0; i<r; i++){
    cin >> s1 >> s2 >> e;
    size = city.size();
    city.insert(s1);
    if(size!=city.size()) mp[s1] = id++;
    size = city.size();
    city.insert(s2);
    if(size!=city.size()) mp[s2] = id++;

    g.insert(mp[s1], mp[s2], e);
    g.insert(mp[s2], mp[s1], e);
    /*cout << "insert " << mp[s1] << "-" << mp[s2] << endl;*/
  }
  cin >> s1 >> s2;
  source = mp[s1];
  target = mp[s2];

  cout << bfs_transive(g, source, target) << " tons" << endl;
}

main(){
  for(int i=1; read(); i++){
    cout << "Scenario #" << i << endl;
    work();
    cout << endl;
  }
}

int bfs_transive(graph &g, int s, int t){
  queue<int> q;
  vector<bool> visited;

  visited.resize(g.size(), false);

  q.push(s);
  visited[s] = true;
  int u, v;
  g.reset();
  int e;
  while(!q.empty()){
    u = q.front(); q.pop();
//    if(u==t) return g.m[s][u];

    while((v=g.next(u))!=-1){
      if(!visited[v]){
	
	e = min(g.m[s][u], g.m[u][v]);
	if(g.m[s][v]>=0){
	  e = max(g.m[s][v], e);
	}

	g.insert(s, v, e); g.insert(v, s, e);

	if(v!=t){
	  q.push(v);
	  visited[v] = true;
	}
      }
    }
  }
  return g.m[s][t];
}


// @end_of_source_code
