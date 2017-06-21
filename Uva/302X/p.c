#include<iostream>
#include<stdio.h>
#include<set>

#define MAX 2000
#define EMAX 50

using namespace std;

class Edge{
 public:
  int id, target;
  Edge(){}
  Edge(int id, int target): id(id), target(target){}

  bool operator < ( const Edge &edge ) const{
    return ( id < edge.id );
  }
};

class Node{
 public:
  set<Edge> edges;
  
  Node(){
    edges.clear();
  }
  
  void addEdge( Edge edge){
    edges.insert( edge );
  }
};

int nnode;
Node nodes[MAX];
int degree[MAX];
bool visited[EMAX];
int path[EMAX];
int nedge;
int start;

bool checkDegree(){
  for ( int i = 0; i < MAX; i++ ){
    if ( degree[i] % 2 != 0 ) return false;
  }
  return true;
}

bool rec( int pos, int n ){
  
  if ( pos == 1 && n == nedge ) {
    for ( int i = 0; i < nedge; i++ ){
      if ( i ) printf(" ");
      printf("%d", path[i]);
    }
    cout << endl;
    return true;
  }

  Node node = nodes[pos];
  set<Edge> edges = node.edges;
  set<Edge>::iterator epos;
  for ( epos = edges.begin(); epos != edges.end(); epos++ ){
    Edge edge = *epos;
    
    if ( !visited[edge.id] ){
      path[n] = edge.id;
      visited[edge.id] = true;
      if ( rec( edge.target, n + 1 ) ) return true;
      visited[edge.id] = false;
    }
  }

  return false;
}

void work(){
  if ( !checkDegree() ) {
    printf("Round trip does not exist.\n");
    return;
  }
  
  for (int i = 0; i < EMAX; i++ ) visited[i] = false;
  rec( start, 0 );
}

bool read(){
  int x, y, z;
  nnode = 0;
  nedge = 0;
  start = INT_MAX;

  scanf("%d %d", &x, &y);
  if ( x == 0 && y == 0 ) return false;
  scanf("%d", &z);
  
  start = min( y, x );

  for ( int i = 0; i < MAX; i++ ){
    nodes[i] = Node();
    degree[i] = 0;
  }
  
  nodes[x].addEdge( Edge(z, y) );
  nodes[y].addEdge( Edge(z, x) );
  degree[x]++;
  degree[y]++;
  nedge++;

  while ( 1 ){
    scanf("%d %d", &x, &y);
    if ( x == 0 && y == 0 ) break;
    scanf("%d", &z);
    nodes[x].addEdge( Edge(z, y) );
    nodes[y].addEdge( Edge(z, x) );
    degree[x]++;
    degree[y]++;
    nedge++;
    start = min( start, x );
    start = min( start, y );
  }

  /*
  for ( int i = 0; i < MAX; i++ ){
    set<Edge> edges = nodes[i].edges;
    set<Edge>::iterator pos;
    for ( pos = edges.begin(); pos != edges.end(); pos++ ){
      Edge edge = *pos;
      printf("%d ", edge.id);
    }
    printf("\n");
    }*/

  return true;
}

main(){
  while ( read() ) { work(); cout << endl; }
}
