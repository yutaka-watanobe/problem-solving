// @JUDGE_ID:  17051CA  315  C++
// @begin_of_source_code
#include<stdio.h>
#include<vector>
#include<slist>
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>

void split(vector<string> &d, const string &s, char c=' '){
  string t = "";

  for(int i=0; i<s.size(); i++){    
    if(s[i]==c){
      if(t!=""){ d.push_back(t); t = ""; }
    }
    else t += s[i];
  }
  if(t.size()) d.push_back(t);
}

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

void _low(graph &g, vector<int> &pi, vector<int> &d, 
	  vector<int> &low, int &time, int u);
void art_points(graph &g, vector<int> &v);

int read(){
  string line;
  getline(cin, line);
  n = atoi(line.c_str());
  if(n==0) return 0;
  return 1;
}

void work(){
  int i, j;
  string line;
  g = graph(n);
  vector<string> com;

  while(1){
    getline(cin, line);
    com.clear();
    split(com, line);
    i = atoi(com[0].c_str());
    if(i==0) break;
    for(int k=1; k<com.size(); k++){
      j = atoi(com[k].c_str());
      g.insert(i-1, j-1); g.insert(j-1, i-1);
    }
  }
  
  vector<int> v;
  art_points(g, v);
  cout << v.size() << endl;

}

main(){
  while(read()){
    work();
  }
}

/*
 * 下の関数 art_points, bridge, bcc に使われる、lowを計算する再帰関数。
 */
void _low(graph &g, vector<int> &pi, vector<int> &d, 
	  vector<int> &low, int &time, int u){
  int v;

  d[u] = low[u] = ++time;  
  while((v=g.next(u))!=-1){
    if(!d[v]){
      pi[v] = u;
      _low(g, pi, d, low, time, v);
      low[u] = min(low[u], low[v]);
    }
    else if(pi[u]!=v) low[u] = min(low[u], d[v]);
  }
}

/*
 * Articulation points
 * @param v: list of articulation points.
 * 要件: 関数 _low、グラフは無向・連結であること
 */
void art_points(graph &g, vector<int> &v){
  vector<int> low(g.size()), d(g.size()), pi(g.size(), -1);
  int n = 0, time = 0;
 
  g.reset();
  for(int i=0; i<g.size(); i++)
    if(!d[i]) _low(g, pi, d, low, time, i);

  v.clear();

  vector<bool> b(g.size());
  for(int i=1; i<g.size(); i++){
    int j = pi[i];
    if(j==0) n++;
    else if(d[j]<=low[i] && !b[j]){
      v.push_back(j); 
      b[j] = 1;
    }
  }
  if(n>1) v.push_back(0);
}


// @end_of_source_code
