// @JUDGE_ID:  17051CA  515  C++
// @begin_of_source_code
#include<stdio.h>
#include<stl.h>
typedef pair<int, int> edge;
#define MAX 102
#define null edge( -1, -1 )

class graph {
 public:
  int size;
  vector<edge>  adj[ MAX ];
  vector<edge>::iterator pos[ MAX ];

  graph(){}
  graph( int n ){ resize(n); }

  void resize( int n ){
    size = n;
    for ( int i = 0; i < n; i++ ) adj[i].clear();
  }

  int getSize(){ return size; }

  void insert( int i, int j, int e ){
    adj[i].push_back( make_pair(j, e) );
  }

  edge next( int i ){ 
    if( pos[i] == adj[i].end() ) return null;
    return *pos[i]++; 
  }
  
  void reset(){
    for ( int i = 0; i < size; i++ ) pos[i] = adj[i].begin(); 
   }
};

class King{
 public:
  graph g;
  int n, m;

  void work(){
    createConstraintGraph();
    if ( bellman( g, 0 ) ) printf("lamentable kingdom\n");
    else printf("successful conspiracy\n");
  }

  void createConstraintGraph(){
    int si, ni, ki;
    char comparison[3];
    scanf("%d", &m);
    g = graph( n + 2 );
    for ( int i = 1; i < n + 2; i++ ) g.insert( 0, i, 0 );
    for ( int i = 0; i < m; i++ ){
      scanf("%d %d %s %d", &si, &ni, comparison, &ki );
      addConstraint( si, si + ni + 1, comparison[0], ki );
    }
  }

  void addConstraint( int left, int right, char comparison, int ki ){
    if ( comparison == 'g' ) g.insert( right, left, -(ki + 1) );
    else g.insert( left, right, ki - 1 );
  }

  bool read(){
    scanf("%d", &n);
    if ( n == 0 ) return false;
    return true;
  }
  
  bool bellman(graph &g, int s ){
    int d[ MAX ];
    for ( int i = 0; i < g.getSize(); i++ ) d[i] = 0;
    
    d[s] = 0;
    
    edge v;
    
    for ( int i = 0; i < g.getSize() -1; i++ ){
      g.reset();
      bool revalidated = false;
      for ( int u = 1; u < g.getSize(); u++ ){
	while ( (v = g.next(u) ) != null ){
	  if ( d[v.first] > d[u] + v.second ){
	    d[v.first] = d[u] + v.second;
	    revalidated = true;
	  }
	}
      }
      if ( !revalidated ) break;
    }
    
    g.reset();
    for ( int u = 0; u < g.getSize(); u++ ){
      while ( (v = g.next(u) ) != null ){
	if ( d[v.first] > d[u] + v.second )  return false;
      }
    }
    return true;
  }
};

main(){
  King K;
  while ( K.read() ){
    K.work();
  }
}


