// @JUDGE_ID:  17051CA  200  C++
// @begin_of_source_code
#include<stdio.h>
#include<vector>
#include<slist>
#include<queue>
#include<iostream>
#include<stl.h>
#include<string>

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
vector<bool> b;
map<int, char> mp;

/*
 * Topological Sort
 * 
 */
void _dfs(graph &g, vector<int> &visited, vector<int> &path, int &t, int u){
  int v;
  visited[u] = 1;
  while((v=g.next(u))!=-1){
    if(!visited[v]) _dfs(g, visited, path, t, v);
  }
  path[t++] = u;
}

void tsort(graph &g, vector<int> &path){
  int t = 0;
  vector<int> visited(g.size());

  path.resize(g.size());
  g.reset();
  for(int i=0; i<g.size(); i++)
    if(!visited[i]) _dfs(g, visited, path, t, i);

  reverse(path.begin(), path.end());
}

vector<string> v;
bool same(int, int, int);

void work(){
  g = graph(30);
  b.resize(30, false);
  string line;
  while(1){
    getline(cin, line);
    if(line[0]=='#') break;
    while(line.size()<22) line += " ";
    v.push_back(line);
  }

  char pre, c;
  int ei, ej;
  for(int j=0; j<21; j++){
    for(int i=0; i<v.size(); i++){
      c = v[i][j];
      if(i==0){
	pre = c;
      }else{
	if(pre!=c){
	  if(same(j, i-1, i) && pre != ' ' && c != ' '){
	    ei = pre - 65;
	    ej = c - 65;
	    g.insert(ei, ej);
	    b[ei] = true; b[ej] = true;
	    mp[ei] = pre; mp[ej] = c;
	  }
	}
	pre = c;
      }
    }
  }

  vector<int> path;
  tsort(g, path);
  
  for(int i=0; i<path.size(); i++){
    if(b[path[i]]) cout << mp[path[i]];
  }
  cout << endl;
}

bool same(int jj, int i1, int i2){
  if(jj==0) return true;
  for(int j=jj-1; j>=0; j--){
    if( v[i1][j] != v[i2][j] ) return false;
  }
  return true;
}

main(){
  work();
}

// @end_of_source_code
