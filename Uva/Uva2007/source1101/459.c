// @JUDGE_ID:  17051CA  459  C++
// @begin_of_source_code
#include<stdio.h>
#include<vector>
#include<slist>
#include<iostream>
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
int n;

int dfs(graph &g, vector<int> &pi, vector<int> &d, vector<int> &f);
void _dfs(graph &g, vector<int> &color, vector<int> &pi, vector<int> &d, 
	  vector<int> &f, int &time, int u);

void work(){
  int i, j;
  string line;
  bool first = true;
  char c, c1, c2;
  while(1){
    getline(cin, line);
    if(cin.eof() || line.size()==0) break;

    if(first){
      c = line[0];
      g = graph( c - 65 + 1);
      first = false;
    }else{
      c1 = line[0];
      c2 = line[1];
      i = c1 - 65; 
      j = c2 - 65;
      g.insert(i, j); g.insert(j, i);
    }
  }

  vector<int> pi, d, f;
  
  cout << dfs(g, pi, d, f) << endl;


}

main(){
  int testCase;
  string line;
  getline(cin, line);
  testCase = atoi(line.c_str());
  getline(cin, line);
  for(int i=0; i<testCase; i++){
    if(i!=0) cout << endl;
    work();
  }
}

/*
 * recursive function that is used below.
 */
void _dfs(graph &g, vector<int> &color, vector<int> &pi, vector<int> &d, 
	  vector<int> &f, int &time, int u){
  int v;

  color[u] = 1, d[u] = ++time;
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
 * d: そのノードが何番目に発見されたか（グレイになったか）を指す。
 * f: そのノードが何番目に探索されたか（黒になったか）を指す。
 * color: そのノードがすでに探索されたかどうかを指す。
 * pi: bfsと同じ。
 * 要件: 関数 _dfs
 */
int dfs(graph &g, vector<int> &pi, vector<int> &d, vector<int> &f){
  int time = 0;
  vector<int> color(g.size(), 0);
  int count = 0;
  pi.resize(g.size(), -1);
  d.resize(g.size(), 0);
  f.resize(g.size(), 0);

  g.reset();
  for(int i=0; i<g.size(); i++){
    if(!color[i]) {
      _dfs(g, color, pi, d, f, time, i);
      count++;
    }
  }
  return count;
}
// @end_of_source_code
