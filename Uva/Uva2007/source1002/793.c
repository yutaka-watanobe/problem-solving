// @JUDGE_ID:  17051CA  793  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<slist>
#include<vector>
#include<stl.h>
#include<queue>

void split(vector<string> &d, string &s, char c=' '){
  string t = "";
  for(int i=0; i<s.size(); i++){
    if(s[i]==c){
      if(t!=""){ d.push_back(t); t = "";}
    }
    else t += s[i];
  }
  if(t.size()) d.push_back(t);
}

class graph{
 public:
  vector<slist<int> > adj;
  vector<slist<int>::iterator> pos;

  graph(){}
  graph(int n){
    adj.resize(n), pos.resize(n);
    for(int i=0; i<n; i++){
      adj[i].clear();
    }
  }

  int size(){return adj.size();}

  void insert(int i, int j, int e){
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
void work();
bool bfs(graph &g, int s, int t);

void work(){
  char buff[10000];
  string line;
  int n;
  cin.getline(buff, 10000);
  n = atoi(buff);

  g = graph(n+1);

  int suc, unsuc;
  suc = unsuc = 0;

  while(1){
    cin.getline(buff, 10000);
    line = buff;
    if(line.size()==0 || cin.eof()) break;

    vector<string> com;
    com.clear();
    split(com, line);

    char c = com[0][0];
    int v1 = atoi( com[1].c_str() );
    int v2 = atoi( com[2].c_str() );

    if( c=='c' ){
      g.insert(v1, v2, 1);
      g.insert(v2, v1, 1);
    }else{
      if( bfs(g, v1, v2) ) suc++;
      else unsuc++;
    }
  }

  cout << suc << "," << unsuc << endl;
}

bool bfs(graph &g, int s, int t){
  queue<int> q;
  int u, v;
  vector<int> pi, d;
  pi.resize(g.size());
  fill(pi.begin(), pi.end(), -1);
  d.resize(g.size());
  fill(d.begin(), d.end(), 0);

  q.push(s);
  d[s] = 1;
  g.reset();
  while(!q.empty()){
    u = q.front(), q.pop();

    if( u == t ){
      return true;
    }

    while((v=g.next(u))!=-1){
      if(!d[v]){
	d[v] = d[u]+1;
	pi[v] = u;
	q.push(v);
      }
    }
  }
  return false;
}

main(){
  char buf[10];
  int tcase;
  cin.getline(buf, 10);
  tcase = atoi(buf);
  cin.getline(buf, 10);

  for(int i=0; i<tcase; i++){
    if( i!=0 ) cout << endl;
    work();
  }
}

// @end_of_source_code



