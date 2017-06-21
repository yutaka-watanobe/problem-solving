/*********************************
 * Dijkstra2                     *
 * for get some shortest path !! *
 *********************************/
#include "graph.h"

graph g;
int n;

/**
 * Dijkstra
 * @param 
 *   pi:   previous node vector
 *         sise of pi[i] == 0  --> source and not visited node!!
 *   cost: distance from source
 *          0 --> source
 *         INT_MAX --> not visited node
 */ 
void dijkstra2(graph &g, vector<vector<int> > &pi, vector<int> &cost, int s){
  cost.resize(g.size(), INT_MAX);
  pi.resize(g.size());
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
    int dist;
    while((v=g.next(x))!=-1){
      if( !visited[v] ){
	dist = cost[x] + g.m[x][v];
	if( dist == cost[v] ){
	  pi[v].push_back(x);
	}else if( dist < cost[v] ){ 
	  cost[v] = dist;
	  pi[v].clear();
	  pi[v].push_back(x);
	}
      }
    }

  }
}

/**
 * Print Path. not ordered!
 */
void printPath(vector<vector<int> > &pi, int p){
  cout << p << " ";
  for(int j=0; j<pi[p].size(); j++){
    printPath(pi, pi[p][j]);
  }
}

void read(){
  int i, j, e;
  cin >> n;
  g = graph(n);
  while(1){
    cin >> i >> j >> e;
    if( cin.eof() ) break;
    g.insert(i, j, e); g.insert(j, i, e); 
  }
}

main(){
  read(); /* read graph */
  vector<int> cost;
  vector<vector<int> > pi;
  g.reset();
  dijkstra2(g, pi, cost, 0);

  cout << "cost : "; for(int i=0; i<n; i++) printf("%3d", cost[i]);
  cout << endl;

  printPath(pi, g.size()-1);

}
