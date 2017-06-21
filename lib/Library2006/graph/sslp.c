#include "graph.h"

/*
 * Single-Source Longest Path
 * !! Needs debugging !!
 */

int inf = INT_MIN;

int _sslp(graph &rg, vector<int> &pi, vector<int> &d, int u, int s){
  int m = inf, tmp, v;
  
  while((v=rg.next(u))!=-1){
    if(d[v]!=inf) tmp = d[v];
    else tmp = _sslp(rg, pi, d, v, s);

    if(tmp==inf) continue;

    tmp += rg[u][v];

    if(m<tmp){
      m = tmp;
      pi[u] = v;
    }
  }
  return d[u] = m;
}

void sslp(graph &g, vector<int> &pi, vector<int> &d, int s){
  graph rg(g.size());
  int v;

  pi.assign(g.size(), -1);
  d.assign(g.size(), inf);

  g.reset();
  for(int i=0; i<g.size(); i++){
    while((v=g.next(i))!=-1){
      rg.insert(v, i, g[i][v]);
    }
  }

  d[s] = 0;
  rg.reset();
  for(int i=0; i<g.size(); i++){
    if(d[i]==inf) _sslp(rg, pi, d, i, s);
  }
}

main(){

  graph g = graph(6);

  g.insert(0, 1, 1);
  g.insert(0, 3, 1);
  g.insert(1, 2, 1);
  g.insert(1, 3, 1);
  g.insert(1, 4, 1);
  g.insert(2, 5, 1);
  g.insert(3, 4, 1);
  g.insert(4, 2, 1);
  g.insert(4, 5, 1);

  vector<int> pi, d;

  sslp(g, pi, d, 0);

  for(int i=0; i<pi.size(); i++){
    cout << pi[i] << " ";
  }
  cout << endl;
  for(int i=0; i<pi.size(); i++){
    cout << d[i] << " ";
  }
  cout << endl;
}
