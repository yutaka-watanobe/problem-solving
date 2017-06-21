// @JUDGE_ID:  17051CA  534  C++
// @begin_of_source_code
/* MST + BFS （効率が悪い）*/
/* mst に対して Freddy から Fiona までを BFS でたどり */
/* 最大の道を保持し,最終結果を返す */
#include<stdio.h>
#include<iostream>
#include<string>
#include<slist>
#include<vector>
#include<stl.h>
#include<queue>
typedef pair<int, int> edge;

class graph {
 public:
  vector<vector<double> > m;
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

  void insert(int i, int j, double e){
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

graph g, g2;
int n; 
vector<pair<double, double> > node;
void prim(graph &g, vector<edge> &m);
double bfs(graph &g, int s, int e);

double getDist(int i, int j){
  double x1, y1, x2, y2;
  x1 = node[i].first;
  y1 = node[i].second;
  x2 = node[j].first;
  y2 = node[j].second;
  return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int read(){
  cin >> n;
  return n==0 ? false : true;
}

void work(){

  g = graph(n);

  node.clear();

  for(int i=0; i<n; i++){
    double a, b;
    cin >> a >> b;
    node.push_back(pair<double, double>(a, b));
  }

  pair<double, double> p1, p2;
  double d, x1, y1, x2, y2;
  for(int i=0; i<n-1; i++){
    for(int j=i+1; j<n; j++){
      d = getDist(i, j);
      g.insert(i, j, d);
      g.insert(j, i, d);
    }
  }
  vector<edge> m;
  double mdist;

  prim(g, m);

  g2 = graph(n);

  for(int i=0; i<m.size(); i++){
    g2.insert(m[i].first, m[i].second, 1);
    g2.insert(m[i].second, m[i].first, 1);
  }

  mdist = bfs(g2, 0, 1);
  cout << "Frog Distance = ";
  printf("%.3lf\n", mdist);
}

main(){
  for(int i=1; read(); i++){
    cout << "Scenario #" << i << endl;
    work();
    cout << endl;
  }
}

/**
 * MST Prim's algorithm
 * m: mst
 */
void prim(graph &g, vector<edge> &m){

  vector<int> pi(g.size(), -1);
  vector<double> d(g.size(), INT_MAX);
  vector<int> visited(g.size(), 0);

  int u, v;
  int s = 0;

  d[s] = 0;
  
  g.reset();
  
  while(1){
    double min = INT_MAX;
    for (int i=0; i<g.size(); i++){
      if (visited[i]==0 && d[i]<min) {
	min = d[i];
	u = i;
      }
    }

    if( min == INT_MAX ) break;
    visited[u] = 1;

    while((v=g.next(u))!=-1){
      if (visited[v]==0 && g.m[u][v]<d[v]){
	d[v] = g.m[u][v];
	pi[v] = u;

      }
    }
  }

  m.clear();
  for(int i=0; i<pi.size(); i++){
    if(pi[i]!=-1){
      m.push_back(edge(i, pi[i]));
    }
  }

}

double bfs(graph &g, int s, int e){
  vector<int> pi, d;
  queue<int> q;
  int u, v;

  pi.resize(g.size(), -1);
  d.resize(g.size(), 0);

  q.push(s);
  d[s] = 1;
  g.reset();

  double mdist = 0;

  while(!q.empty()){
    u = q.front(), q.pop();
    if(u==e) goto next;
    while((v=g.next(u))!=-1){
      if(!d[v]){
	d[v] = d[u]+1;
	pi[v] = u;
	q.push(v);
      }
    }
  }

 next:;
  int p = 1;
  while(1){
    if(pi[p]==-1) break;
    mdist = max(mdist, getDist(p, pi[p]));
    p = pi[p];
  }

  return mdist;
}

// @end_of_source_code
