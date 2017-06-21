// @JUDGE_ID:  17051CA  521  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
#include<slist>
#include<queue>


/*
 * Greatest Common Divisor
 * requirement: a > b > 0 
 */
int gcd(int a, int b){
  if(b==0) return a;
  return gcd(b, a%b);
}

/*
 * Least Common Multiplier
 * requirement: a, b > 0  , a < b is OK,   gcd function
 */
int lcm(int a, int b){
  if(a<b) swap(a, b);
  return a*b/gcd(a, b);
}

void split(vector<string> &d, const string &s, char c=' '){
  d.clear();
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

class Bus{
 public:
  vector<int> line;
  int pos, len;
  Bus(){}
  Bus(vector<int> l, int sv){
    line = l;
    for(int i=0; i<line.size(); i++){
      if(line[i]==sv){ pos = i; break;}
    }
    len = line.size();
  }

};

int n, d, s;
string line;
vector<Bus> bus;

bool bfs(graph &g);

int read(){
  vector<string> v;
  getline(cin, line);
  split(v, line);
  n = atoi(v[0].c_str());
  d = atoi(v[1].c_str());
  s = atoi(v[2].c_str());
  if(n==0 && d==0 && s==0) return 0;
  return 1;
}

bool meet(Bus b1, Bus b2){
  int k = lcm(b1.len, b2.len);
  for(int i=0; i<k+3; i++){
    if(b1.line[b1.pos]==b2.line[b2.pos]){
      return true;
    }
    b1.pos++; b2.pos++;
    if(b1.pos>=b1.len) b1.pos = 0;
    if(b2.pos>=b2.len) b2.pos = 0;
  }
  return false;
}

void work(){
  bus.clear();
  bus.resize(d);
  vector<string> v;
  int b, start;

  for(int i=0; i<n; i++){
    vector<int> bus_line;
    getline(cin, line);
    split(v, line);
    for(int j=0; j<v.size(); j++) bus_line.push_back(atoi(v[j].c_str()));
    getline(cin, line);
    split(v, line);
    for(int j=0; j<v.size()-1; j+=2){
      start = atoi(v[j].c_str());
      b = atoi(v[j+1].c_str());
      Bus bs = Bus(bus_line, start);
      bus[b-1] = bs;
    }
  }
  
  graph g = graph(d);
  
  for(int i=0; i<d-1; i++){
    for(int j=i+1; j<d; j++){
      if(meet(bus[i], bus[j])){
	g.insert(i, j);
	g.insert(j, i);
      }
    }
  }
  
  if(bfs(g)) cout << "Yes" << endl;
  else  cout << "No" << endl;
  
}

bool bfs(graph &g){
  s = 0;
  vector<int> pi, d;
  queue<int> q;
  int u, v;

  pi.resize(g.size(), -1);
  d.resize(g.size(), 0);

  q.push(s);
  d[s] = 1;
  g.reset();
  int sum = 0;

  while(!q.empty()){
    u = q.front(), q.pop();
    sum++;
    while((v=g.next(u))!=-1){
      if(!d[v]){
        d[v] = d[u]+1;
        pi[v] = u;
        q.push(v);
      }
    }
  }
  if(sum==g.size()) return true;
  return false;
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
