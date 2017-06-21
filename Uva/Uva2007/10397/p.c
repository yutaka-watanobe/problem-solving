// @JUDGE_ID:  17051CA  10397  C++
// @begin_of_source_code
/* Graph -- MST */
/* すでに connect されているところを０とし、prim をかます */
#include<iostream>
#include<string>
#include<stdio.h>
#include<stl.h> 
#include<vector>
#include<slist>

typedef pair<int, int> edge;

class Point{
 public:
  int x, y;
  Point(){}
  Point(int x, int y): x(x), y(y){}
};

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

/**
 * MST Prim's algorithm
 * m: mst
 * Solved Problem: 10034, 534
 */
void prim(graph &g, double &dist){

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

  dist = 0;
  for(int i=0; i<pi.size(); i++){
    if(pi[i]!=-1){
      dist += g.m[i][pi[i]];
    }
  }
}

double getDist(Point p1, Point p2){
  return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

graph g;
vector<Point> p;
int n;

int read(){
  cin >> n;
  if(cin.eof()) return 0;

  p.clear();
  g = graph(n);
  int a, b;
  for(int i=0; i<n; i++){
    cin >> a >> b;
    p.push_back(Point(a, b));
  }

  double d;
  for(int i=0; i<n-1; i++){
    for(int j=i+1; j<n; j++){
      d = getDist(p[i], p[j]);
      g.insert(i, j, d);
      g.insert(j, i, d);
    }
  }
  int m;
  cin >> m;
  for(int i=0; i<m; i++){
    cin >> a >> b;
    a--; b--;
    g.m[a][b] = 0;
    g.m[b][a] = 0;
  }

  return 1;
}

void work(){
  double dist;
  prim(g, dist);

  printf("%.2f\n", dist);
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
