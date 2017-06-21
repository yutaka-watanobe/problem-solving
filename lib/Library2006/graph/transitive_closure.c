/**********************
 * Transitive closure *
 **********************/
#include "graph.h"

graph g;
int n;
void warshall(graph &g);

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
  warshall(g);

}

/**
 * Warshall
 */ 
void warshall ( graph &g ){
  for ( int y = 0; y < g.size(); y++ ){
    for ( int x = 0; x < g.size(); x++ ){
      if ( g.m[x][y] ){
	for ( int i = 0; i < g.size(); i++ ){
	  if ( g.m[y][i] )  g.m[x][i] = 1;
	}
      }
    }
  }
}
