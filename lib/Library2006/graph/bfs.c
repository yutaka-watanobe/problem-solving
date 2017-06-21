/**********************
 * Breth First Search *
 **********************/
#include "graph.h"
#include<queue>
#include<iostream>

graph g;
int n;

/*
 * BFS (Breadth First Search)
 * @param
 * pi: it represet the node that is searched before it.
 *     -1 ---> the node that is not visited.
 * d : it represet level of the node.
 *       0 ---> the node that is not visited.
 *     it is form 1 not zero! (i.e. source is 1).
 * s : source
 * requirement: #include <queue>
 */
void bfs(graph &g, vector<int> &pi, vector<int> &d, int s){
  queue<int> q;
  int u, v;

  pi.resize(g.size(), -1);
  d.resize(g.size(), 0);

  q.push(s);
  d[s] = 1;

  g.reset();

  while ( !q.empty() ){
    u = q.front(), q.pop();
    while( ( v = g.next(u) ) != -1 ){
      if( !d[v] ){
	d[v] = d[u] + 1;
	pi[v] = u;
	q.push( v );
      }
    }
  }
}

void bfs(graph &g, vector<int> &pi, vector<int> &d, int s);

void read(){
  int i, j;
  cin >> n;
  g = graph(n);
  while(1){
    cin >> i >> j;
    if( cin.eof() ) break;
    g.insert( i, j, 1 ); 
    g.insert( j, i, 1 ); 
  }
}

main(){
  read(); /* read graph */
  vector<int> pi, d;
  g.reset();
  bfs(g, pi, d, 0);
  cout << "pi: "; for(int i=0; i<n; i++) cout << pi[i] << " ";
  cout << endl;
  cout << "d : "; for(int i=0; i<n; i++) cout << d[i] << " ";
  cout << endl;
}
