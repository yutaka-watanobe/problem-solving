// @JUDGE_ID:  17051CA  10308  C++
// @begin_of_source_code
#include<stdio.h>
#include<string>
#include<vector>
#include<slist>
#include<queue>
#include<iostream>
#include<algorithm>
#include<stl.h>

void split(vector<string> &d, string &s, char c=' '){
  string t = "";

  s += c;
  for(int i=0; i<s.size(); i++){
    if(s[i]==c){
      if(t!=""){ d.push_back(t); t = "" ; }
      continue;
    }
    t += s[i];
  }
  s.erase(s.end()-1);
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

graph g;
map<pair<int, int>, int>  edge;
vector<pair<int, int> > p;
int n;
void bfs(graph &g, vector<int> &pi, vector<int> &d, int s);
void work(int);

void read(){
  int i, j, k;
  p.clear();
  pair<int, int> key;
  string line;
  vector<string> com;
  n =0;
  while(1){
    getline(cin, line);

    if(line.size()==0 ){
      if(cin.eof()) {
	work(i);return;
      }
      work(i);
      p.clear();
      n = 0;
      goto next;
    }
    com.clear();
    split(com, line);
    i = atoi(com[0].c_str());
    j = atoi(com[1].c_str());
    k = atoi(com[2].c_str());
    key.first = i; key.second = j;
    p.push_back(key);
    edge[key] = k;
    key.first = j; key.second = i;
    edge[key] = k;
    n = max( n, max(i, j) );
    
    if(cin.eof()) {
      work(i);
      return;
    }

  next:;
  }
}

void work(int k){  
//  g = graph(p.size()+10);
//  g = graph(10000);
  g = graph(n+1); 
  for(int i=0; i<p.size(); i++){
    g.insert(p[i].first, p[i].second);
    g.insert(p[i].second, p[i].first);
  }
  vector<int> pi, d;
  bfs(g, pi, d, k);
  
  int max = -1;
  int mi;
  for(int i=0; i<d.size(); i++){
    if(d[i] > max ) {
      max = d[i];
      mi = i;
    }
  }
  pi.clear(); d.clear();
  bfs(g, pi, d, mi);
  cout << *max_element(d.begin(), d.end() ) -1 << endl;
}

main(){
  read();
}

void bfs(graph &g, vector<int> &pi, vector<int> &d, int s){
  queue<int> q;
  int u, v;
  pair<int, int> key;
  pi.resize(g.size(), -1);
  d.resize(g.size(), 0);

  q.push(s);
  d[s] = 1;
  g.reset();
  while(!q.empty()){
    u = q.front(), q.pop();
    while((v=g.next(u))!=-1){
      if(!d[v]){
	key.first = u; key.second = v;
	d[v] = d[u]+edge[key];
	pi[v] = u;
	q.push(v);
      }
    }
  }
}

// @end_of_source_code
