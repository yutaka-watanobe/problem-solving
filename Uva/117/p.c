// @JUDGE_ID:  17051CA  117  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h> 
#include<vector>
#include<slist>
#include<queue>

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
void dijkstra(graph &g, vector<int> &pi, vector<int> &d, int s);
void postal();
int sum;

void work(){
  string line;
  char f, e;
  int i, j, w;
  g = graph(26);
  sum = 0;
  while(1){
    cin >> line;
    if(cin.eof()) return;
    if(line=="deadend"){
      postal();
      g.clear();
      g = graph(26);
      sum = 0;
    }else{
      f = line[0];
      e = line[line.size()-1];
      i = f - 97; j = e - 97;
      w = line.size();
      g.insert(i, j, w); g.insert(j, i, w);
      sum += w;
    }
  }
}

void postal(){
  int odd = 0;
  int i1, i2;
  i1 = -1; 
  for(int i=0; i<26; i++){
    if(g.adj[i].size()%2!=0){
      odd++;
      if(i1 == -1) i1 = i;
      else i2 = i;
    }
  }

  if(odd==0){ /* オイラー回路 */
    cout << sum << endl;
  }else if(odd==2){ /* オイラー小道 */
    vector<int> pi, d;
    dijkstra(g, pi, d, i1);
    cout << sum + d[i2] << endl;
  }
}

main(){
  work();
}

/**
 * Dijkstra
 * @param 
 *   pi:   previous node
 *         -1 --> source and not visited node
 *   cost: distance from source
 *          0 --> source
 *         INT_MAX --> not visited node
 */ 
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
