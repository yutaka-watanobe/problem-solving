// @JUDGE_ID:  17051CA  10477  C++
// @begin_of_source_code
/* state BFS */
/* 4.47 sec */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<stl.h>
#define KNIGHT 0
#define MUTANT 1
#define PAWN 2
#define LIMIT 1000

int dxP[8] = { 0, -1, 0, 1, -1, -1, 1, 1};
int dyP[8] = { 1, 0, -1, 0, 1, -1, -1, 1};
int dxK[8] = { -1, -2, -2, -1, 1, 2, 2, 1};
int dyK[8] = { 2, 1, -1, -2, -2, -1, 1, 2};
int dxM[8] = { -1, -3, -3, -1, 1, 3, 3, 1};
int dyM[8] = { 3, 1, -1, -3, -3, -1, 1, 3};

class TheHybridKnight{
 public:
  int N, S;
  int d[ 1323 ];
  int cash[ 441 ][ 441 ];
  int Q[ LIMIT + 1];
  int head, tail;
  int size;

  bool empty(){
    return head == tail;
  }

  void init(){
    head = tail = 1;
  }

  void push( int x ){
    Q[ tail ] = x;
    if ( tail == LIMIT ){
      tail = 0;
    } else {
      tail++;
    }
  }

  int front(){
    int x = Q[ head ];
    if ( head == LIMIT ){
      head = 1;
    } else {
      head++;
    }
    return x;
  }

  int bfs( int start, int end ){

    int u, v;
    int r;

    init();

    for ( int i = 0; i < size; i++ ) d[i] = INT_MAX;

    push( start );
    d[ start ] = 0;

    int source, target, type;

    while ( !empty() ){
      u = front();

      source = u / 3;
      target;
      type = u - 3 * source;

      /* if ( source == end ) return d[u] */;

      int x, y, dx, dy;
      x = source / N;
      y = source - x * N;

      if ( type == KNIGHT ){
	for ( r = 0; r < 8; r++ ){
	  dx = x + dxK[r];
	  dy = y + dyK[r];
	  if ( 0 <= dx && 0 <= dy && dx < N && dy < N ){
	    target = dx * N + dy;
	    if ( target == end ) return d[u] + 1;
	    v = target * 3 + MUTANT;
	    if ( d[v] == INT_MAX ){
	      d[v] = d[ u ] + 1;
	      push( v );
	    }
	  }
	}
      } else if ( type == MUTANT ){
	for ( r = 0; r < 8; r++ ){
	  dx = x + dxM[r];
	  dy = y + dyM[r];
	  if ( 0 <= dx && 0 <= dy && dx < N && dy < N ){
	    target = dx * N + dy;
	    if ( target == end ) return d[u] + 1;
	    v = target * 3 + PAWN;
	    if ( d[v] == INT_MAX ){
	      d[v] = d[ u ] + 1;
	      push( v );
	    }
	  }
	}
      } else if ( type == PAWN ){
	for ( r = 0; r < 8; r++ ){
	  dx = x + dxP[r];
	  dy = y + dyP[r];
	  if ( 0 <= dx && 0 <= dy && dx < N && dy < N ){
	    target = dx * N + dy;

	    v = target * 3 + KNIGHT;
	    if ( d[v] == INT_MAX ){
	      if ( r > 3 ){
		if ( target == end ){
		  if ( target == end ) return d[u] + 1;
		  d[v] = d[u] + 1;
		  push( v );		
		}
	      } else {
		if ( target == end ) return d[u] + 1;
		d[v] = d[ u ] + 1;
		push( v);
	      }
	    }
	  }
	}
      } else {
	assert ( false );
      }
    }

    return INT_MAX;
  }

  void compute( int source, int target){
    int cost;
    if ( cash[source][target] != INT_MAX ){
      cost = cash[source][target];
    } else {
      int costP = bfs( source*3 + PAWN, target );
      int costK = bfs( source*3 + KNIGHT, target );
      int costM = bfs( source*3 + MUTANT, target );
      
      cost = min( costP, min( costK, costM ) );
      cash[source][target] = cost;
    }

    if ( cost == INT_MAX ) printf("?\n");
    else printf("%d\n", cost);
  }

  void work(){
    int NN = N * N;
    for ( int i = 0; i < NN; i++ ){
      for ( int j = 0; j < NN; j++ ){
	cash[i][j] = INT_MAX;
      }
    }

    int B, E;

    for ( int i = 0; i < S; i++ ){
      scanf("%d %d", &B, &E );
      compute( B-1, E-1);
    }

  }

  bool read(){
    scanf("%d", &N );
    if ( N == 0 ) return false;
    scanf("%d", &S );

    size = N * N * 3;
    return true;
  }
  

};

main(){
  TheHybridKnight THK;
  for ( int i = 1; THK.read(); i++ ){
    printf("Set %d:\n", i );
    THK.work();
  }
}

// @end_of_source_code


