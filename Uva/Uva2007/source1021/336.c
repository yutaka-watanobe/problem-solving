/* @JUDGE_ID: 17051CA 336 C++  */

#include<stdio.h>
#include<stl.h>
#include<slist>
#include<map>
#include<set>
#include<vector>
#include<iostream>
#include<string>
#include<queue>

class graph{
 public:
  vector<slist<int> > adj;
  vector<slist<int>::iterator> pos;

  graph(){}
  graph(int n){
    resize(n);
  }

  void resize(int n){
    adj.resize(n), pos.resize(n);
    for(int i=0; i<n; i++){
      adj[i].clear();
    }
  }

  int size(){ return adj.size();}

  int next(int i){
    if(pos[i]==adj[i].end()) return -1;
    return *pos[i]++;
  }
  
  void insert(int i, int j, int e){
    adj[i].push_front(j);
  }
  void reset(int i){pos[i] = adj[i].begin();}
  void reset(){for(int i=0; i<size(); i++) reset(i);}

  void clear(){adj.clear(), pos.clear();}
};

void work();
int read();
void bfs(graph &g, vector<int> &pi, vector<int> &d, int s);

graph g;
int n;
int caseN;

void work(){
  int ii, jj;
  vector<pair<int, int> > edge;
  edge.clear();
  set<int> ver;

  for(int i=0; i<n; i++){
    cin >> ii >> jj;
    pair<int, int> p;
    p.first = ii;
    p.second = jj;
    edge.push_back(p);
    ver.insert(ii); ver.insert(jj);
  }

  vector<int> v;
  v.resize(ver.size());
  copy(ver.begin(), ver.end(), v.begin());

  g = graph(v.size());
  
  map<int, int> mp;
  
  for(int i=0; i<v.size(); i++){
    mp[ v[i] ] = i;
  }

  for(int i=0; i<edge.size(); i++){
    pair<int, int> e = edge[i];
    g.insert( mp[e.first], mp[e.second], 1 );
    g.insert( mp[e.second], mp[e.first], 1 );
  }

  vector<int> pi, d;
  int  ttl;
  int nd;
  while(1){
    cin >> nd >> ttl;
    if( nd == 0 && ttl==0 ) break;

    int s = mp[nd];
    
    bfs(g, pi, d, s);

    int cnt = 0;
    for(int i=0; i<d.size(); i++){
      if(d[i]>ttl+1 || d[i]==0) cnt++;
    }
   
    cout << "Case " << caseN << ": " << cnt << " nodes not reachable from node " << nd << " with TTL = " << ttl << "." << endl;
    caseN++;
  }

}

void bfs(graph &g, vector<int> &pi, vector<int> &d, int s){
  queue<int> q;
  int u, v;

  pi.resize(g.size());
  fill(pi.begin(), pi.end(), -1);
  d.resize(g.size());
  fill(d.begin(), d.end(), 0);

  q.push(s);
  d[s] = 1;
  g.reset();
  while(!q.empty()){
    u = q.front(), q.pop();
    while((v=g.next(u))!=-1){
      if(!d[v]){
	d[v] = d[u]+1;
	pi[v] = u;
	q.push(v);
      }
    }

  }


}

main(){
  caseN = 1;
  while(read()){
    work();
  }

}

int read(){
  cin >> n;
  if(n==0) return 0;
  return 1;
}
