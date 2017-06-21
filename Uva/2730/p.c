// @JUDGE_ID:  17051CA  2730  C++
// @begin_of_source_code
/* Shortest Path */
#include<stdio.h>
#include<iostream>
#include<slist>
#include<vector>
#include<climits>
#include<stl.h>
#include<cmath>

class graph {
 public:
  vector<slist<int> > adj;
  vector<slist<int>::iterator> pos;

  graph(){}
  graph(int n){ resize(n); }

  void resize(int n){
    adj.resize(n), pos.resize(n); 
    for(int i=0; i<n; i++){
      adj[i].clear();
    }
  }

  int size(){ return adj.size(); }

  void insert(int i, int j){
    adj[i].push_front(j);
  }
  
  int next(int i){ 
    if(pos[i]==adj[i].end()) return -1;
    return *pos[i]++; 
  }
  
  void reset(int i){ pos[i] = adj[i].begin(); }
  void reset(){ for(int i=0; i<size(); i++) reset(i); }

  void clear(){ adj.clear(), pos.clear(); }
};

long getCost( int v, long cost ){
  if ( 0 <= v && v <= 25 ){  /* village */
    return cost + 1;
  } else if ( 26 <= v && v <= 51 ){ /* town */
    if ( cost % 19 == 0 ){
      return 20 * ( cost / 19 );
    } else {
      return (long)( ceil( 20.0 * cost / 19.0 ) );
    }
  } else {
    assert( false );
  }
}
/**
 * Dijkstra
 * @param 
 *   pi:   previous node
 *         -1 --> source and not visited node
 *   cost: distance from source
 *          0 --> source
 *         INT_MAX --> not visited node
 * Solved 10171,
 */ 
void dijkstra(graph &g, vector<long> &cost, int s, long p){
  vector<int> pi;
  cost.resize(g.size(), INT_MAX);
  pi.resize(g.size(), -1);
  vector<int> visited(g.size(), 0);
  
  cost[s] = p;
  g.reset();
  while(1){
    long min = INT_MAX;
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
    while((v=g.next(x))!=-1){
      long next_cost = getCost( x, cost[ x ] );
      if( !visited[v] && next_cost < cost[v] ){ 
	cost[v] = next_cost;
	pi[v] = x;
      }
    }

  }
}

graph g;

int getIndex( char ch ){
  int index;
  if ( 97 <= ch && ch <= 122 ){
    index = ch - 97;
  } else if ( 65 <= ch && ch <= 90 ){
    index = ch - 65 + 26;
  }
  return index;
}

int read(){
  g.clear();
  g = graph( 52 ); /* a - z, A - Z */

  int n;
  cin >> n;
  if ( n == -1 ) return 0;

  char ch1, ch2;
  int source, destination;
  for ( int i = 0; i < n; i++ ){
    cin >> ch1 >> ch2;
    source = getIndex( ch1 );
    destination = getIndex( ch2 );
    g.insert( source, destination );
    g.insert( destination, source );
  }

  return 1;
}

void work(){
  char ch1, ch2;
  long p;
  int source, destination;

  cin >> p >> ch1 >> ch2;
  source = getIndex( ch1 );
  destination = getIndex( ch2 );
  
  vector<long> cost;
  dijkstra( g, cost, destination, p );

  /*
  for ( int i = 0; i < cost.size(); i++ ){
    cout << i << " " << cost[i] << endl;
  }
  */


  cout << cost[ source ] << endl;
}

main(){
  for ( int i = 1; read(); i++ ){
    cout << "Case " << i << ": ";
    work();
  }
}


// @end_of_source_code
