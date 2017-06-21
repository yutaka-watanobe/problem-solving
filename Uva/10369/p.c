// @JUDGE_ID:  17051CA  10369  C++
// @begin_of_source_code
// Disjoint Set --> MST Kruskal
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 501

class Point{
 public:
  double x, y;
  Point(){}
  Point( double x, double y ): x(x), y(y){}
};

class Edge{
 public:
  int source, target;
  double dist;
  Edge(){}
  Edge(int source, int target, double dist): source(source), target(target), dist(dist){}

  bool operator < ( const Edge &e ) const{
    return dist < e.dist;
  }
};

class DisjointSet{
 public:
  vector<int> rank, p;

  DisjointSet(){}
  DisjointSet(int size){
    rank.resize(size, 0);
    p.resize(size, 0);
  }

  void makeSet(int x){
    p[x] = x;
    rank[x] = 0;
  }

  void merge(int x, int y){
    link(findSet(x), findSet(y));
  }

  void link(int x, int y){
    if(rank[x] > rank[y]){
      p[y] = x;
    }else{   
      p[x] = y;
      if(rank[x] == rank[y]){
	rank[y] = rank[y] + 1;
      }
    }
  }

  int findSet(int x){
    if(x != p[x]){
      p[x] = findSet(p[x]);
    }
    return p[x];
  }
};

int nchannel, npost;
Point P[MAX];
vector<Edge> E;

void read(){
  cin >> nchannel >> npost;
  double x, y;
  for ( int i = 0; i < npost; i++ ){
    cin >> x >> y;
    P[i] = Point(x, y);
  }
}

double getDistance( Point p1, Point p2 ){
  return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + (p1.y-p2.y)*(p1.y-p2.y) );
}

void createGraph(){
  E.clear();
  for (int i = 0; i < npost-1; i++ ){
    for ( int j = i+1; j < npost; j++ ){
      E.push_back( Edge(i, j, getDistance(P[i], P[j]) ) );
    }
  }
}

double kruskal_like(){
  createGraph();
  sort( E.begin(), E.end() );
  
  DisjointSet dset = DisjointSet(npost);
  bool connected[MAX];
  double D = 0;
  for ( int i = 0; i < MAX; i++ ) connected[i] = false;
  
  for ( int i = 0; i < npost; i++ ){
    dset.makeSet(i);
  }
  
  int ncomponent = npost;
  
  for ( int i = 0; i < E.size(); i++ ){
    if ( ncomponent  <= nchannel ) {
      return D;
    }
    Edge edge = E[i];
    int source = edge.source;
    int target = edge.target;


    if ( dset.findSet(source) == dset.findSet(target) ) continue;

    dset.merge( source, target );
    D = edge.dist;

    connected[source] = connected[target] = true;
    ncomponent--;
  }

  return D;

}

void work(){
  printf("%.2lf\n", kruskal_like());
}

main(){
  int tcase; cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){ read(); work();}
}


// @end_of_source_code


