/***********************
 * Topological Sorting *
 ***********************/
#include "graph.h"
graph g;
int n;

/*
 * Topological Sort
 * 
 */
void _dfs(graph &g, vector<int> &visited, vector<int> &path, int &t, int u){
  int v;

  visited[u] = 1;
  while((v=g.next(u))!=-1){
    if(!visited[v]) _dfs(g, visited, path, t, v);
  }
  path[t++] = u;
}

void tsort(graph &g, vector<int> &path){
  int t = 0;
  vector<int> visited(g.size());

  path.resize(g.size());
  g.reset();
  for(int i=0; i<g.size(); i++)
    if(!visited[i]) _dfs(g, visited, path, t, i);

  reverse(path.begin(), path.end());
}

void read(){
  int i, j;
  cin >> n;
  g = graph(n);
  while(1){
    cin >> i >> j;
    if( cin.eof() ) break;
    g.insert(i, j); 
  }
}

main(){
  read(); /* read graph */
  vector<int> path;
  g.reset();
  tsort(g, path);
  cout << "path: "; for(int i=0; i<n; i++) cout << path[i] << " ";
  cout << endl;

}
