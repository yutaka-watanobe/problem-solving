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

void parse(vector<string> v);

void work(){
  vector<string> v;
  g = graph(30);
  string line;
  while(1){
    cin >> line;
    if(line=="#") break;
    v.push_back(line);
  }

  parse(v);

}

void parse(vector<string> v){
  cout << "parse!!--" << endl;
  for(int i=0; i<v.size(); i++){
    cout << v[i] << endl;
  }
  cout << "-------" << endl;

  char pre, c;
  int cnt;
  string str;
  int ei, ej;
  vector<string> next;
  next.clear();

  for(int i=0; i<v.size(); i++){
    str = v[i]; c = str[0];
    cout << str << endl;
    next.push_back(str);
    if(i==0){/* first */
      pre = c;
    }else{
      
      if(pre!=c || i==v.size()-1){
	if(next.size()>1){
	  for(int n=0; n<next.size(); n++){
	    string s = next[i];
	    s.erase(s.begin()+0);
	    next[i] = s;
	  }
	  parse(next);
	}
	next.clear();
      }

      if(pre!=c){
	ei = pre - 65;
	ej = c - 65;
	cout << ei << "-->" << ej << endl;
	g.insert(ei, ej);
      }
      
      pre = c;
    }
  }
}

main(){
  work();
}

// @end_of_source_code
