#include "graph.h"

/*
 * 関数 dijkstra, prim に使われるヒープのための比較オブジェクト
 */
class heap_cmp: binary_function<int, int, bool> {
 public:
  vector<int> *l;

  heap_cmp(vector<int> &v): l(&v){}
  bool operator()(int i, int j) const{ 
    vector<int> &v = *l;

    if(v[i]==v[j]) return i<j;
    return v[i]<v[j];
  }
};

/*
 * Single-Source Shortest Path (Dijkstraのアルゴリズム)
 * 要件: グラフのエッジは非負であること、class heap_cmp
 */
void dijkstra(graph &g, vector<int> &pi, vector<int> &d, int s){
  heap_cmp cmp(d);
  set<int, heap_cmp> heap(cmp);
  vector<set<int, heap_cmp>::iterator> ptr(g.size());
  vector<int> b(g.size());
  int u, v;

  pi.resize(g.size());
  d.resize(g.size());

  for(int i=0; i<g.size(); i++){
    pi[i] = -1;
    d[i] = INT_MAX;
    ptr[i] = heap.end();
  }

  d[s] = 0;
  ptr[s] = heap.insert(s).first;

  g.reset();
  while(heap.size()){
    u = *heap.begin();
    heap.erase(ptr[u]);
    b[u] = 1;

    while((v=g.next(u))!=-1){
      if(g[u][v] && !b[v]){
	if(d[v]==INT_MAX || d[u]+g[u][v]<d[v]){
	  if(ptr[v]!=heap.end()) heap.erase(ptr[v]);
	  d[v] = d[u]+g[u][v];
	  pi[v] = u;
	  ptr[v] = heap.insert(v).first;
	}
      }
    }
  }
}

/*
 * Single-Source Shortest Path (Bellman-Fordのアルゴリズム)
 * 要件: なし
 * 注意: 負の閉路があるときはssspは存在しないので、そのときは
 *       負の閉路に含まれるノードを返す（これによって負の閉路を
 *       見つけることができる）。それ以外は-1を返す。
 * !! Needs debugging !!
 */
int bellman_ford(graph &g, vector<int> &pi, vector<int> &d, int s){
  int u, v, n = 0;
  vector<int> inf(g.size(), 1);
  queue<int> q;

  d.resize(g.size());
  pi.resize(g.size());
  fill(pi.begin(), pi.end(), -1);

  inf[s] = d[s] = 0;
  q.push(s), q.push(g.size());
  g.reset();
  while(!q.empty()){
    u = q.front(), q.pop();

    if(u==g.size()){
      if(n++>g.size()) break;
      q.push(g.size());
    }
    else {
      g.reset(u);
      while((v=g.next(u))!=-1){
	if(inf[v] || d[v] > d[u]+g[u][v]){
	  inf[v] = 0;
	  d[v] = d[u]+g[u][v];
	  q.push(v);
	  pi[v] = u;
	}
      }
    }
  }

  if(pi[s]!=-1) return s;
  for(int i=0; i<g.size(); i++){
    for(int v=pi[i]; v!=-1; v=pi[v]){
      if(v==i) return v;
    }
  }
  return -1;
}

main(){
  graph g;
  vector<int> d, pi;
  
  while(1){
    int n, m;

    cin >> n >> m;

    if(cin.eof()) break;

    g.resize(n);
    for(int i=0; i<m; i++){
      int u, v, e;

      cin >> u >> v >> e;

      g.insert(u, v, e);
    }

    int u;
    vector<int> p;

    if((u=bellman_ford(g, pi, d, 0))!=-1){
      p.push_back(u);
      for(int v=pi[u]; v!=u; v=pi[v]){
	p.push_back(v);
      }
      copy(pi.begin(), pi.end(), ostream_iterator<int>(cout, " "));
      cout << endl;
      reverse(p.begin(), p.end());
      copy(p.begin(), p.end(), ostream_iterator<int>(cout, " "));
      cout << endl;
    }
    else cout << "No negative cycles." << endl;

  }
}





