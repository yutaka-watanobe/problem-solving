// @JUDGE_ID:  17051CA  10080  C++
// @begin_of_source_code
/* Maximum Flow */
/* Maximum bipartite mathcing */

#include<iostream>
#include<string>
#include<stdio.h>
#include<slist>
#include<queue>
#include<stl.h>
#include<cmath>

class edge {
 public:
  int v, f, c;
  slist<edge>::iterator r;
  
  edge(){}
  edge(int v, int c): v(v), c(c), f(0){}
  edge(const edge &e): v(e.v), c(e.c), f(e.f){}
  bool operator!=(int j){ return v!=j; }
  int cf(){ return c-f; }
};

edge null(-1, -1);

class network {
 public:
  vector<slist<edge> > adj;
  vector<slist<edge>::iterator> pos;

  network(int n=0){ resize(n); }
  void resize(int n){
    adj.resize(n), pos.resize(n);

    for(int i=0; i<n; i++) adj[i].clear();
  }
  int size(){ return adj.size(); }
  void insert(int i, int j, int c){
    slist<edge>::iterator it;

    if((it=find(adj[i].begin(), adj[i].end(), j))!=adj[i].end()){
      it->c = c;
    }
    else {
      adj[i].push_front(edge(j, c));
      adj[j].push_front(edge(i, 0));
      adj[i].front().r = adj[j].begin();
      adj[j].front().r = adj[i].begin();
    }
  }
  edge &next(int i){
    if(pos[i]==adj[i].end()) return null;
    return *pos[i]++;
  }
  void reset(int i){ pos[i] = adj[i].begin(); }
  void reset(){ for(int i=0; i<size(); i++) reset(i); }
};

int bfs(network &g, vector<edge> &pi, int s, int t){
  queue<int> q;
  bit_vector d(g.size());
  int u;
  edge e;

  pi.resize(g.size());

  q.push(s);
  d[s] = 1;
  g.reset();
  while(!q.empty()){
    u = q.front(), q.pop();
    if(u==t) return 1;

    while((e=g.next(u))!=-1){
      if(!d[e.v] && e.cf()){
	pi[e.v] = *(e.r);
	d[e.v] = 1;
	q.push(e.v);
      }
    }
  }
  return 0;
}

int edmonds_karp(network &g, int s, int t){
  int f;
  vector<edge> pi;
  edge e;

  while(bfs(g, pi, s, t)){
    f = INT_MAX;
    for(int i=t; i!=s; i=pi[i].v) f = min(f, pi[i].r->cf());
    for(int i=t; i!=s; i=pi[i].v){
      pi[i].r->f += f;
      pi[i].r->r->f -= f;
    }
  }

  g.reset(s);
  for(f=0; (e=g.next(s))!=-1; f+=e.f);

  return f;
}

int n, m;
double s, v;
network g;
vector<pair<double, double> > G;
vector<pair<double, double> > H;

int read(){
  G.clear();
  H.clear();
  cin >> n >> m >> s >> v;
  if ( cin.eof() ) return 0;
  double x, y;

  for ( int i = 0; i < n; i++ ){
    cin >> x >> y;
    G.push_back( make_pair(x, y) );
  }

  for ( int i = 0; i < m; i++ ){
    cin >> x >> y;
    H.push_back( make_pair(x, y) );
  }

  return 1;
}

bool able( double x1, double y1, double x2, double y2){
  double d = sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
  if ( d <= s*v ) return true;
  return false;
}

void createGraph(){
  g = network( n + m + 2 );

  for ( int i = 0; i < n; i++ ){
    for ( int j = 0; j < m; j++ ){
      if ( able(H[j].first, H[j].second, G[i].first, G[i].second) ){
	g.insert( i+1, j+n+1, 1);
	/* g.insert( j+n+1, i+1, 1); */
      }
    }
  }

  for ( int j = 1; j <= n; j++ ){
    g.insert(0, j, 1);
    /* g.insert(j, 0, 1); */
  }

  for ( int j = 1; j <= m; j++ ){
    g.insert(j+n, n+m+1, 1);
    /* g.insert(n+m+1, j+n, 1); */
  }
}

void work(){
  createGraph();
  cout << n - edmonds_karp( g, 0, n+m+1 ) << endl;
}

main(){
  while( read() ) work();
}
// @end_of_source_code

