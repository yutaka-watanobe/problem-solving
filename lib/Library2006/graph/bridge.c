/**********
 * Bridge *
 **********/
#include "graph.h"

graph g;
int n;

void _low(graph &g, vector<int> &pi, vector<int> &d, 
	  vector<int> &low, int &time, int u);
void bridge(graph &g, vector<pair<int, int> > &v);

void read(){
  int i, j;
  cin >> n;
  g = graph(n);
  while(1){
    cin >> i >> j;
    if( cin.eof() ) break;
    g.insert(i, j, 1); g.insert(j, i, 1); 
  }
}

main(){
  read(); /* read graph */
  g.reset();
  vector<pair<int, int> > v;
  bridge(g, v);
  for(int i=0; i<v.size(); i++){
    pair<int, int> p = v[i];
    cout << p.first << ", " << p.second << endl;
  }
}

/*
 * Recursive function that is used by bellow function
 *  art_points, bridge, bcc to caluculate low
 */
void _low(graph &g, vector<int> &pi, vector<int> &d, 
	  vector<int> &low, int &time, int u){
  int v;

  d[u] = low[u] = ++time;  
  while((v=g.next(u))!=-1){
    if(!d[v]){
      pi[v] = u;
      _low(g, pi, d, low, time, v);
      low[u] = min(low[u], low[v]);
    }
    else if(pi[u]!=v) low[u] = min(low[u], d[v]);
  }
}

/* 
 * Bridge
 * requirement: function _low¡¢undirected graph and connected graph
 */
void bridge(graph &g, vector<pair<int, int> > &v){
  vector<int> low(g.size()), d(g.size()), pi(g.size(), -1);
  int time = 0;
  
  g.reset();
  for(int i=0; i<g.size();i++)
    if(!d[i]) _low(g, pi, d, low, time, i);
  
  v.clear();
  for(int i=1; i<g.size(); i++){
    if(low[i]==d[i]){
      v.push_back(pair<int, int>(i, pi[i]));
    }
  }
  
  /* if sorting */
  for(int i=0; i<v.size(); i++){
    if(v[i].first > v[i].second) swap(v[i].first, v[i].second);
  }
  sort(v.begin(), v.end());
}
