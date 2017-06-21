/**********************
 * Articulation Point *
 **********************/
#include "graph.h"

graph g;
int n;

void _low(graph &g, vector<int> &pi, vector<int> &d, 
	  vector<int> &low, int &time, int u);
void art_points(graph &g, vector<int> &v);
void art_points2(graph &g, vector<int> &v);

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
  vector<int> v;
  art_points(g, v);
  cout << "v : "; for(int i=0; i<v.size(); i++) cout << v[i] << " ";
  cout << endl;
}

/*
 * Recusive function that is used by bellow function
 * art_points, bridge, bcc to calucurate low
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
 * Articulation points
 * @param v: list of articulation points.
 * requirement: function _low¡¢undirected graph and connected graph
 */
void art_points(graph &g, vector<int> &v){
  vector<int> low(g.size()), d(g.size()), pi(g.size(), -1);
  int n = 0, time = 0;
 
  g.reset();
  for(int i=0; i<g.size(); i++)
    if(!d[i]) _low(g, pi, d, low, time, i);

  v.clear();

  vector<bool> b(g.size());
  for(int i=1; i<g.size(); i++){
    int j = pi[i];
    if(j==0) n++;
    else if(d[j]<=low[i] && !b[j]){
      v.push_back(j); 
      b[j] = 1;
    }
  }
  if(n>1) v.push_back(0);

  /* if sorting */
  sort(v.begin(), v.end());
}

/*
 * Articulation points
 * @param v: list of articulation points.
 * !! un-connected graph is OK
 */
void art_points(graph &g, vector<int> &v){
  vector<int> low(g.size()), d(g.size()), pi(g.size(), -1);
  vector<int> b(g.size());
  int n = 0, time = 0;
  v.clear();
  g.reset();
  for(int i=0; i<g.size(); i++){
    if(!d[i]){
      time = 0;
      _low(g, pi, d, low, time, i);
      n = 0;
      for(int k=0; k<g.size(); k++){
	if(b[k]==2) continue;
	int j = pi[k];
	if(j==i) n++;
	else if(j!=-1 && d[j]<=low[k] && !b[j]){
	  v.push_back(j);
	  b[j] = 1;
	}
      }
      if(n>1) v.push_back(i);

      for(int k=0; k<g.size(); k++){
	if(d[k]) b[k] = 2;
      }
    }
  }    
}



