// @JUDGE_ID:  17051CA  10330  C++
// @begin_of_source_code
/* Network : Maxmum flow */
/* Edmonds Karp Algorithm を使用 */
/* Ford Fulkerson method (Algorithm) */
/* ノードにキャパシティがある場合は,ノードをエッジに見立てる */

#include<stdio.h>
#include<iostream>
#include<string>
#include<slist>
#include<queue>
#include<stl.h>

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

int n;
network g;

int read(){
  int M, B, D, source, target, cap;
  cin >> n;
  if(cin.eof()) return 0;
  
  g = network(2*n+2);

  /* cout << "net with " << 2*n+2 << endl; */

  /* 各ノードをエッジに見立てる */
  for(int i=1; i<=2*n; i+=2){
    cin >> cap;
    g.insert(i, i+1, cap); 
    g.insert(i+1, i, cap); 
   /*  cout << i <<"-" << i+1 << "   "; */
/*     cout << i+1 << "-" << i << endl; */
  }

  cin >> M;

  for(int i=0; i<M; i++){
    cin >> source >> target >> cap;
    g.insert(source*2, target*2-1, cap);
    /* cout << source*2 << "--->" << target*2-1 << endl; */
  }

  cin >> B >> D;

  for(int i=0; i<B; i++){
    cin >> target;
    g.insert(0, target*2-1, INT_MAX);
    /* cout << 0 << "--->" << target*2-1 << endl; */
  }

  for(int i=0; i<D; i++){
    cin >> source;
    g.insert(source*2, 2*n+1, INT_MAX);
    /* cout << source*2 << "--->" << 2*n+1 << endl; */
  }

  return 1;
}


void work(){
  cout << edmonds_karp(g, 0, 2*n+1) << endl;
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
