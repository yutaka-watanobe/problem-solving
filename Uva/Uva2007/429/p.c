// @JUDGE_ID:  17051CA  429  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<slist>
#include<map>
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

graph g;

int bfs(graph &g, int s, int t);
bool isNext(string, string);

void work(){
  map<string, int> mp;
  vector<string> v;
  v.clear();
  int node = 0;

  g = graph(201);

  string line;
  while(1){
    getline(cin, line);
    if( line=="*" ) break;

    v.push_back(line);
    mp[line] = node++;
    for(int i=0; i<v.size(); i++){
      if(isNext(line, v[i])){
	g.insert(mp[line], mp[v[i]]);
	g.insert(mp[v[i]], mp[line]);
      }
    }
  }

  int cost;
  
  while(1){
    bool iseof = false;
    getline(cin, line);

    if(line.size()==0 ) break;
    if(cin.eof() ) iseof = true;
    
    string s1, s2;
    bool nx = false;
    s1 = s2 = "";
    for(int i=0; i<line.size(); i++){
      char c = line[i];
      if(c==' ') nx = true;
      else{
	if( nx ) s2 = s2 + c;
	else s1 = s1 + c;
      }
    }
    cost = bfs(g, mp[s1], mp[s2]);
    cout << s1 << " " << s2 << " " << cost << endl;
    if( iseof) break;
  }

}

bool isNext(string s1, string s2){
  if( s1.size() != s2.size() || s1 == s2) return false;
  int nm = 0;
  for(int i=0; i<s1.size(); i++){
    if( s1[i] != s2[i] ) nm++;
    if(nm >=2 ) return false;
  }
  return true;
}

main(){
  int n;
  string line;
  char buf[10000];
  cin.getline(buf, 10000);
  n = atoi(buf);
  getline(cin, line);
  for(int i=0; i<n; i++){
    if( i!=0 ) cout << endl;
    work();
  }
}

int bfs(graph &g, int s, int t){
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
    if( u == t ) return d[u]-1;

    while((v=g.next(u))!=-1){
      if(!d[v]){
	d[v] = d[u]+1;
	pi[v] = u;
	q.push(v);
      }
    }
  }

  return -1;
}
// @end_of_source_code
