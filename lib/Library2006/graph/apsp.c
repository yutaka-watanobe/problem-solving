/********
 * APSP *
 ********/
#include "graph.h"

/*
 * All-Pairs Shortest Path
 *
 *    d[i][j]:  shortest path from i to j
 *    pi[i][j]: the previout node of j, of d[i][j]
 * if d[x][x] is negative, then x is on a negative cycles.
 * check if there exist a path 1 - > v - > a 
 * where v is a vertex on negative cycle!
 * Solved 10449,
 */
void floyd( graph &g, vector<vector<int> > &pi, vector<vector<int> > &d ){
  int n = g.size(), inf = INT_MIN;

  d = g.m;
  pi.assign( g.size(), vector<int>(g.size(), -1) );

  for ( int i = 0; i < n; i++ ){
    for( int j = 0; j < n; j++ ){
      pi[i][j] = i;
      if ( i != j && d[i][j] == 0 ) d[i][j] = inf;
    }
  }
  for ( int k = 0; k < n; k++ ){
    for ( int i = 0; i < n; i++ ){
      if ( d[i][k] == inf ) continue;
      for ( int j = 0; j < n; j++ ){
	if ( d[k][j] == inf ) continue;
	
	if ( d[i][j] == inf || d[i][k] + d[k][j] < d[i][j] ){
	  d[i][j] = d[i][k] + d[k][j];
	  pi[i][j] = pi[k][j];
	}
      }
    }
  }
}
