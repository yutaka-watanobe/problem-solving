#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#define MAX 800

using namespace std;


class DisjointSet{
private:
  vector<int> rank, p;

  void link ( int x, int y ){
    if ( rank[x] > rank[y] ){
      p[y] = x;
    } else {
      p[x] = y;
      if ( rank[x] == rank[y] ){
	rank[y]++;
      }
    }
  }

  int findSet( int x ){
    if ( x != p[x] ) p[x] = findSet( p[x] );
    return p[x];
  }

public:
  DisjointSet(){}
  DisjointSet( int size ){
    rank.resize( size, 0 );
    p.resize( size, 0 );
  }
  
  void makeSet( int x ){
    p[x] = x;
    rank[x] = 0;
  }
  
  void merge( int x, int y ){
    link( findSet(x), findSet(y) );
  }

  bool isSameSet( int x, int y ){
    return ( findSet(x) == findSet(y) );
  }
};

// begin_of_source
class edge{
public:
  int source, target;
  double cost;
  edge(){}
  edge( int source, int target, double cost ): 
    source(source), target(target), cost(cost){}

  bool operator < ( const edge &e ) const{
    return cost < e.cost;
  }
};

int N;
vector<edge> edges;

void kruskal( vector<edge> &mst ){

  sort( edges.begin(), edges.end() );

  DisjointSet dset = DisjointSet( N );

  for ( int i = 0; i < N; i++ ) dset.makeSet( i );

  int source, target;
  double cost;
  for ( int i = 0; i < edges.size(); i++ ){
    edge e = edges[i];
    if ( dset.findSet( e.source ) != dset.findSet( e.target ) ){
      mst.push_back( e );
      dset.union( e.source, e.target );
    } 
  }
}
// end_of_source



bool input(){
  if ( scanf("%d", &N) == EOF ) return false;
  pair<int, int> points[MAX];

  for( int i = 0; i < N; i++ ){
    scanf("%d %d", &points[i].first, &points[i].second );
  }

  edges.clear();

  for ( int i = 0; i < N - 1; i++ ){
    for ( int j = i + 1; j < N; j++ ){
      int x1 = points[i].first;
      int x2 = points[j].first;
      int y1 = points[i].second;
      int y2 = points[j].second;
      
      double cost = sqrt( (double)(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
      edges.push_back( edge( i, j, cost) );
    }
  }

  int source, target, m;
  scanf("%d", &m);
  for ( int i = 0; i < m; i++ ){
    scanf("%d %d", &source, &target);
    source--; target--; // zero base
    edges.push_back( edge( source, target, 0.0 ) );
  }

  return true;
}

void compute(){
  double dist;
  kruskal( dist );
  printf("%.2lf\n", dist);
}

main(){
  while ( input() ) compute();
}
