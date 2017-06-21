#include<stdio.h>

#define MAX 22

using namespace std;

bool G[MAX][MAX][100];
bool adjMatrix[MAX][MAX];
int size;

// for dfs
bool visited[MAX];

// gossiped
bool gossiped[MAX];
bool parsed[MAX];
bool talked[MAX];
bool hasGossip;

int nnode;

void dfs( int u ){
  nnode++;
  visited[u] = true;
  for ( int v = 0; v < size; v++ ){
    if ( !visited[v] && adjMatrix[u][v] ) dfs( v );
  }
}

bool connected(){
  for ( int i = 0; i < size; i++ ) visited[i] = false;
  nnode = 0;
  dfs(0);
  return ( nnode == size );
}

void parse( int u, int t ){
  parsed[u] = true;
  if ( gossiped[u] ) hasGossip = true;

  for ( int v = 0; v < size; v++ ){
    if ( !parsed[v] && G[u][v][t] ) parse( v, t );
  }
}

void talk( int u, int t ){
  talked[u] = true;
  if ( !gossiped[u] ){
    gossiped[u] = true; nnode++;
  }

  for ( int v = 0; v < size; v++ ){
    if ( !talked[v] && G[u][v][t] ) talk( v, t );
  }
}

void check( int t ){
  for ( int i = 0; i < size; i++ ) {
    parsed[i] = false;
    talked[i] = false;
  }

  for ( int s = 0; s < size; s++ ){
    hasGossip = false;
    parse( s, t );
    if ( hasGossip ){
      talk( s, t );
    }
  }
}

int compute(){

  for ( int i = 0; i < size; i++ ) gossiped[i] = false;

  int time = 0;

  gossiped[0] = true;
  nnode = 1;

  while ( 1 ){
    check( time % 100 );
    if ( nnode == size ) return time;
    time++;
  }
}

void work(){
  if ( !connected() ){
    printf("-1\n");
    return;
  }

  printf("%d\n", compute() );
}

void read(){
  int v, source, target, time;
  scanf("%d %d", &size, &v);
  for ( int t = 0; t < 100; t++ ){
    for ( int i = 0; i < size; i++ ){
      for ( int j = 0; j < size; j++ ){
	G[i][j][t] = G[j][i][t] = false;
      }
    }
  }
  
  for ( int i = 0; i < size; i++ ){
    for ( int j = 0; j < size; j++ ){
      adjMatrix[i][j] = adjMatrix[j][i] = false;
    }
  }

  for ( int i = 0; i < v; i++ ){
    scanf("%d %d %d", &source, &target, &time);
    source--; target--;
    for ( int j = 0; j < time; j++ ){
      int t; scanf("%d", &t);
      G[source][target][t] = G[target][source][t] = true;
    }

    adjMatrix[source][target] = adjMatrix[target][source] = true;
  }
}

main(){
  int tcase; scanf("%d", &tcase);
  for ( int i = 0; i < tcase; i++ ){
    read();
    work();
  }
}
