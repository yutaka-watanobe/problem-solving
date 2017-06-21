// @JUDGE_ID:  17051CA  796  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h> 
#include<vector>
#include<slist>

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
void bridge(graph &g, vector<pair<int, int> > &v);

int read(){
  cin >> n;
  if(cin.eof()) return 0;
  return 1;
}

void work(){

  g = graph(n);
  int i, j, k;
  char c;
  for(int a=0; a<n; a++){
    cin >> i >> c >> k >> c;
    for(int b=0; b<k; b++){
      cin >> j;
      g.insert(i, j);
    }
  }

  vector<pair<int, int> > v;
  vector<pair<int, int> > result;
  pair<int, int> p;
  
  bridge(g, v);
  
  for(int i=0; i<v.size(); i++){
    if(v[i].first == -1 || v[i].second == -1 ) continue;
    p.first = min(v[i].first, v[i].second);
    p.second = max(v[i].first, v[i].second);
    result.push_back(p);
  }
  sort(result.begin(), result.end());
  
  cout << result.size() << " critical links" << endl;
  for(int i=0; i<result.size(); i++){
    p = result[i];
    cout << p.first << " - " << p.second << endl;
  }
}

main(){
  while(read()){
    work();
    cout << endl;
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
 * Bridge
 * 要件: 関数 _low、グラフは無向・連結であること
 */
void bridge(graph &g, vector<pair<int, int> > &v){
  vector<int> low(g.size()), d(g.size()), pi(g.size(), -1);
  int time = 0;
  
  g.reset();
  for(int i=0; i<g.size();i++)
    if(!d[i]) _low(g, pi, d, low, time, i);
  
  v.clear();
  for(int i=1; i<g.size(); i++){
    if(low[i]==d[i]){
      v.push_back(pair<int, int>(i, pi[i]));
    }
  }
  
  /* ソートして返す場合 */
  for(int i=0; i<v.size(); i++){
    if(v[i].first > v[i].second) swap(v[i].first, v[i].second);
  }
  sort(v.begin(), v.end());
}

// @end_of_source_code
