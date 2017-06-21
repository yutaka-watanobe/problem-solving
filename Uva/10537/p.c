// @JUDGE_ID:  17051CA  10537  C++
// @begin_of_source_code
/* Shortest Path */
/* must create more than two possible path ! */
#include<stdio.h>
#include<iostream>
#include<slist>
#include<vector>
#include<climits>
#include<stl.h>
#include<cmath>
#include<string>
#define LLONG_MAX       9223372036854775807LL
typedef long long llong;

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

llong getCost( int v, llong cost ){
  if ( 0 <= v && v <= 25 ){  /* village */
    return cost + 1;
  } else if ( 26 <= v && v <= 51 ){ /* town */
    if ( cost % 19 == 0 ){
      return 20 * ( cost / 19 );
    } else {
      return (llong)( ceil( 20.0 * cost / 19.0 ) );
    }
  } else {
    assert( false );
  }
}

/**
 * Dijkstra
 * @param 
 *   pi:   previous node vector
 *         sise of pi[i] == 0  --> source and not visited node!!
 *   cost: distance from source
 *          0 --> source
 *         INT_MAX --> not visited node
 */ 
void dijkstra(graph &g, vector<vector<int> > &pi, vector<llong> &cost, int s, llong p){
  cost.resize(g.size(), LLONG_MAX);
  pi.resize(g.size());
  vector<int> visited(g.size(), 0);
  
  cost[s] = p;
  g.reset();

  while(1){
    llong min = LLONG_MAX;
    int x;
    for(int i=0; i<g.size(); i++){
      if(visited[i]==0 && min > cost[i] ){
	min = cost[i];
	x = i;
      }
    }

    if( min == LLONG_MAX ) break;

    visited[x] = 1;

    int v;

    while((v=g.next(x))!=-1){
      if( !visited[v] ){
	llong next_cost = getCost( x, cost[ x ] );
	
	if( next_cost == cost[v] ){
	  pi[v].push_back(x);
	}else if( next_cost < cost[v] ){ 
	  cost[v] = next_cost;
	  pi[v].clear();
	  pi[v].push_back(x);
	}
      }
    }

  }
}

char getChar ( int index ){
  char ch;
  if ( 0 <= index && index <= 25 ){
    ch = index + 97;
  } else if ( 26 <= index && index <= 51 ){
    ch = index + 65 - 26;
  }
  return ch;
}

graph g;
string current_path;
vector<string> P; /* path list */

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

/**
 * Print Path. not ordered!
 */
void printPath(vector<vector<int> > &pi, int p){

  if ( pi[p].size() == 0 ){
    current_path += getChar( p );
    P.push_back( current_path );
    current_path = "";
    return;
  }

  for(int j=0; j<pi[p].size(); j++){
    current_path += getChar( p );
    printPath(pi, pi[p][j]);
  }

}

void work(){
  char ch1, ch2;
  llong p;
  int source, destination;

  cin >> p >> ch1 >> ch2;
  source = getIndex( ch1 );
  destination = getIndex( ch2 );
  
  vector<llong> cost;
  vector<vector<int> > pi;
  dijkstra( g, pi, cost, destination, p );

  cout << cost[ source ] << endl;

  P.clear();
  current_path = "";
  printPath(pi, source );

  sort( P.begin(), P.end() );

  string path = P[0];
  for ( int j = 0; j < path.size(); j++ ){
    if ( j ) cout << "-";
    cout << path[j];
  }
  cout << endl;

}

main(){
  for ( int i = 1; read(); i++ ){
    cout << "Case " << i << ":" << endl;
    work();
  }
}


// @end_of_source_code
