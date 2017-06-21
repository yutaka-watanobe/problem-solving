// @JUDGE_ID:  17051CA  539  C++
// @begin_of_source_code
/* DFS ( BF ) */
#include<stdio.h>
#include<stl.h>
#define MAX 30

class TheSettlersOfCatan{
 public:
  int nnode;
  int adj[ MAX ][ 5 ];
  int nadj[ MAX ];
  int used[ MAX ][ MAX ];
  int max_len;

  void reset(){
    for ( int i = 0; i < nnode; i++ ){
      for ( int j = 0; j < nnode; j++ ){
	used[i][j] = false;
      }
    }
  }

  void dfs( int u, int depth ){

    max_len  = max( depth, max_len );

    for ( int j = 0; j < nadj[ u ]; j++ ){
      int v = adj[ u ][ j ];
      if ( !used[u][v] ){
	used[u][v] = true;
	used[v][u] = true;
	dfs( v, depth + 1 );
	used[u][v] = false;
	used[v][u] = false;
      }
    }
  }


  void work(){
    max_len = 0;

    for ( int i = 0; i < nnode; i++ ){
      reset();
      dfs( i, 0 );
    }
    printf("%d\n", max_len);
  }

  bool read(){
    int m;
    scanf("%d %d", &nnode, &m);

    if ( nnode == 0 && m == 0 ) return false;
    for ( int i = 0; i < nnode; i++ ){
      nadj[i] = 0;
    }

    int source, target;
    for ( int i = 0; i < m; i++ ){
      scanf("%d %d", &source, &target );
      adj[ source ][ nadj[source]++ ] = target;
      adj[ target ][ nadj[target]++ ] = source;
    }

    return true;
  }

};

main(){
  TheSettlersOfCatan TSOC;
  while ( TSOC.read() ){
    TSOC.work();
  }
}

// @end_of_source_code


