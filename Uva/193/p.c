// @JUDGE_ID:  17051CA  193  C++
// @begin_of_source_code
#include<stdio.h>
#define MAX 101
#define SPACE 0
#define WHITE 1
#define BLACK 2

class graph{
 public:
  int adj[MAX][MAX];
  int tsize[MAX];
  int size;

  graph(){}
  graph(int size): size(size){
    for ( int i = 0; i < size; i++ ){
      tsize[i] = 0;
    }
  }

  void insert( int i, int j ){
    adj[i][ tsize[i]++ ] = j;
  }
};

class State{
 public:
  int color[MAX];
  int nblack;
  int n;
  State(){}
  State(int n):n(n){
    for ( int i = 0; i < n; i++ ) color[i] = SPACE;
    nblack = 0;
  }
};

class GraphColoring{
 public:
  graph g;
  int maxValue, n;
  State state, goal;

  void update(){
    if ( maxValue < state.nblack ){
      maxValue = state.nblack;
      goal = state;
    }
  }

  void recursive( int pos ){
    bool hasBlack = false;
    int target;
    for ( int v = 0; v < g.tsize[pos]; v++ ){
      target = g.adj[pos][v];
      if ( state.color[target] == BLACK ){ hasBlack = true; break;}
    }

    State tmp = state;
    bool changed = false;

    state.color[pos] = WHITE;
    for ( int i = 0; i < n; i++ ){
      if ( state.color[i] == SPACE ) { recursive( i ); changed = true;}
    }
    state = tmp;
    if ( !changed ){ update(); }
    
    if ( !hasBlack ){
      state.color[pos] = BLACK; state.nblack++;
      for ( int v = 0; v < g.tsize[pos]; v++ ){
	target = g.adj[pos][v];
	state.color[target] = WHITE;
      }
      changed = false;
      for ( int i = 0; i < n; i++ ){
	if ( state.color[i] == SPACE ) { recursive( i ); changed = true;}
      } 
      if ( !changed ) update();
    }

  }

  void work(){
    maxValue = -1;
    state = State(n);
    for ( int i = 0; i < n; i++ ){
      if ( state.color[i] == SPACE ) recursive( i );
    }

    printf("%d\n", maxValue );
    bool isfirst = true;
    for ( int i = 0; i < n; i++ ){
      if ( goal.color[i] == BLACK ){
	if ( !isfirst ) printf(" ");
	printf("%d", i+1 );
	isfirst = false;
      }
    }
    printf("\n");

  }

  void read(){
    int  k, source, target;
    scanf("%d %d", &n, &k );
    g = graph ( n );
    for ( int i = 0; i < k; i++ ){
      scanf("%d %d", &source, &target );
      source--; target--;
      g.insert( source, target ); g.insert( target, source );
    }
  }
};

main(){
  GraphColoring GC;
  int tcase;
  scanf("%d", &tcase );
  for ( int i = 0; i < tcase; i++ ){
    GC.read(); GC.work();
  }
}
// @end_of_source_code
