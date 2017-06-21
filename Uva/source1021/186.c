// @JUDGE_ID:  17051CA  186  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stdio.h>
#include<stl.h> 
#include<vector>
#include<slist>
#include<queue>

void split(vector<string> &d, const string &s, char c){
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
  vector<vector<int> > m;
  vector<slist<int> > adj;
  vector<slist<int>::iterator> pos;

  graph(){}
  graph(int n){ resize(n); }

  void resize(int n){
    m.resize(n), adj.resize(n), pos.resize(n); 
    for(int i=0; i<n; i++){
      m[i].resize(n);
      fill(m[i].begin(), m[i].end(), 0);
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
map<pair<int, int>, string> route;
map<string, int> mp;
map<int, string> mp2;
set<string> city;

void parse(int, int);
void space(string &s, int);
void dijkstra(graph &g, vector<int> &pi, vector<int> &d, int s);

void work(){
  string line;
  vector<string> seg;
  int size;
  int id = 0;
  int i, j, e;
  g = graph(100);
  string source, target, name;
  pair<int, int> p;
  while(1){
    getline(cin, line);
    if(line.size()==0) break;
    seg.clear();
    split(seg, line, ',');
    source = seg[0];
    target = seg[1];
    name = seg[2];

    size = city.size();
    city.insert(source);
    if(size!=city.size()){ mp[source] = id; mp2[id] = source; id++;}

    size = city.size();
    city.insert(target);
    if(size!=city.size()){ mp[target] = id; mp2[id] = target; id++;}

    i = mp[source];
    j = mp[target];
    e = atoi(seg[3].c_str());
    
    if(g.m[i][j] && e > g.m[i][j]){

    }else{
      g.insert(i, j, e); g.insert(j, i, e);
      p.first = i; p.second = j;
      route[p] = name;
      p.first = j; p.second = i;
      route[p] = name;
    }
  }

  bool first = true;
  while(1){
    getline(cin, line);
    if(cin.eof()) break;
    seg.clear();
    split(seg, line, ',');
    source = seg[0];
    target = seg[1];
    cout << endl << endl;
    parse(mp[source], mp[target]);
    first = false;
  }
}

void parse(int source, int target){
  vector<int> pi, cost;
  dijkstra(g, pi, cost, source);
  vector<int> path;
  path.clear();
  int next = target;
  while(1){
    if(next==-1) break;
    path.push_back(next);
    next = pi[next];
  }
  reverse(path.begin(), path.end());
  cout << "From                 To                   Route      Miles" << endl;
  cout << "-------------------- -------------------- ---------- -----" << endl;
  
  string From, To, Route;
  int s, t, Miles, total;
  pair<int, int> p;
  total = cost[target];
  for(int i=0; i<path.size()-1; i++){
    s = path[i]; t = path[i+1];
    From = mp2[s];
    To = mp2[t];
    p.first = s; p.second = t;
    Route = route[p];
    Miles = g.m[s][t];
    space(From, 20); space(To, 20); space(Route, 10);
    cout << From << " " << To << " " << Route << " ";
    printf("%5d\n", Miles);
  }
  cout << "                                                     -----" << endl;
  cout << "                                          Total      ";
  printf("%5d\n", total);

}

void space(string &s, int d){
  while(1){
    if(s.size()==d) break;
    s += " ";
  }
}

main(){
  work();
}

void dijkstra(graph &g, vector<int> &pi, vector<int> &cost, int s){
  cost.resize(g.size(), INT_MAX);
  pi.resize(g.size(), -1);
  vector<int> visited(g.size(), 0);
  
  cost[s] = 0;
  g.reset();
  while(1){
    int min = INT_MAX;
    int x;
    for(int i=0; i<g.size(); i++){
      if(visited[i]==0 && min > cost[i] ){
	min = cost[i];
	x = i;
      }
    }

    if( min == INT_MAX ) break;

    visited[x] = 1;

    int v;
    while((v=g.next(x))!=-1){
      if( cost[x] + g.m[x][v] < cost[v] ){
	cost[v] = cost[x] + g.m[x][v];
	pi[v] = x;
      }
    }

  }
}


// @end_of_source_code
