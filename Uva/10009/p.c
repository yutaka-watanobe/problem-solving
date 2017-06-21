// @JUDGE_ID:  17051CA  10009  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
#include<slist>
#include<vector>
#include<set>
#include<queue>

/** 
 * class: graph 
 * It must be non-weighted graph !!.
 */
class graph {
 public:
  vector<slist<int> > adj;
  vector<slist<int>::iterator> pos;
  
  /** constructor */
  graph(){}
  graph(int n){ resize(n); }

  /**  @param the number of node */ 
  void resize(int n){
    adj.resize(n), pos.resize(n); 
    for(int i=0; i<n; i++){
      adj[i].clear();
    }
  }
  
  /** @return the number of node */
  int size(){ return adj.size(); }

  /** insert  */
  void insert(int i, int j){
    adj[i].push_front(j);
  }
  
  /** refere to adjacency list of node i, and move one. */
  int next(int i){ 
    if(pos[i]==adj[i].end()) return -1;
    return *pos[i]++; 
  }
  
  /** reset */
  void reset(int i){ pos[i] = adj[i].begin(); }
  void reset(){ for(int i=0; i<size(); i++) reset(i); }

  /* less used methods */
  void erase(int i, int j){
    for(slist<int>::iterator it=adj[i].begin(); it!=adj[i].end(); it++){
      if(*it==j){
	adj[i].erase(it);
	break;
      }
    }
  }

  /** clear all nodes */
  void clear(){ adj.clear(), pos.clear(); }
};

graph g;
void bfs(graph &g, vector<int> &pi, vector<int> &d, int s, int e);


void work(){
  int n, q;
  int size;
  vector<pair<string, string> > edge;
  set<string> city;
  vector<string> cityV;
  map<string, int> mp;

  cin >> n >> q;

  string s1, s2;
  for(int i=0; i<n; i++){
    cin >> s1 >> s2;
    city.insert(s1);
    city.insert(s2);
    edge.push_back( pair<string, string>(s1, s2) );
  }
  
  size = city.size();
  cityV.resize(size);
  copy(city.begin(), city.end(), cityV.begin());

  for(int i=0; i<cityV.size(); i++){
    mp[ cityV[i] ] = i;
  }

  g = graph(size);
  pair<string, string> e;
  for(int i=0; i<n; i++){
    e = edge[i];
    g.insert( mp[e.first], mp[e.second]);
    g.insert( mp[e.second], mp[e.first]);
  }
  
  for(int i=0; i<q; i++){
    string s1, s2, s3;
    cin >> s1 >> s2;
    s3 = "";
    vector<int> pi, d;
    bfs(g, pi, d, mp[s1], mp[s2]);

    int p = pi[ mp[s2] ];
    while(1){
      s3 = cityV[p][0] + s3;
      if(p == mp[s1]) break;
      p = pi[p];
    }
    s3 += cityV[ mp[s2] ][0];
    cout << s3 << endl;
  }


}

main(){
  int testCase;
  cin >> testCase;
  for(int i=0; i<testCase; i++){
    if(i!=0) cout << endl;
    work();
  }
}

/*
 * BFS (Breadth First Search)
 * @param
 * pi: it represet the node that is searched before it.
 *     -1 ---> the node that is not visited.
 * d : it represet level of the node.
 *       0 ---> the node that is not visited.
 *     it is form 1 not zero! (i.e. source is 1).
 * s : source
 * requirement: #include <queue>
 */
void bfs(graph &g, vector<int> &pi, vector<int> &d, int s, int e){
  queue<int> q;
  int u, v;

  pi.resize(g.size(), -1);
  d.resize(g.size(), 0);

  q.push(s);
  d[s] = 1;
  g.reset();
  while(!q.empty()){
    u = q.front(), q.pop();
    if(u==e) return;
    while((v=g.next(u))!=-1){
      if(!d[v]){
	d[v] = d[u]+1;
	pi[v] = u;
	q.push(v);
      }
    }
  }
}

// @end_of_source_code
