// @JUDGE_ID:  17051CA  10246  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<stl.h>
#define MAX 100
//#define INFTY 9223372036854775807LL
#define INFTY 1000000000000000000LL
typedef long long llong;


class AsterixObelix{
 public:
  llong D[MAX][MAX], C[MAX][MAX];
  int nnode, nquery;
  llong feast[ MAX ];

  void compute(){
    for ( int k = 0; k < nnode; k++ ){
      for ( int i = 0; i < nnode; i++ ){
	if ( D[i][k] == INFTY ) continue;
	for ( int j = 0; j < nnode; j++ ){
	  if ( D[k][j] == INFTY ) continue;
	  if ( D[i][j] == INFTY ||
	       D[i][k] + D[k][j] + max( C[i][k], C[k][j] ) < D[i][j] + C[i][j]){
	    D[i][j] = D[i][k] + D[k][j];
	    C[i][j] = max( C[i][k], C[k][j] );
	  }
	}
      }
    }
  }
  
  void work(){
    int source, target;
    llong cost;
    
    compute();
    //    compute();

    for ( int i = 0; i < nquery; i++ ){
      scanf("%d %d", &source, &target);
      source--; target--;
      if ( D[source][target] == INFTY ) printf("-1\n");
      else printf("%lld\n", D[source][target] + C[source][target]);
    }
  }


  bool read(){
    int m, source, target;
    llong cost;
    scanf("%d %d %d", &nnode, &m, &nquery);

    if ( nnode == 0 && m == 0 && nquery == 0 ) return false;

    for ( int i = 0; i < nnode; i++ ){
      scanf("%lld", &feast[i]);
    }

    for ( int i = 0; i < nnode; i++ ){
      for ( int j = 0; j < nnode; j++ ){
	if ( i == j ) D[i][j] = 0;
	else D[i][j] = INFTY;
	if ( i == j ) C[i][j] = feast[i];
	else C[i][j] = INFTY;
      }
    }

    for ( int i = 0; i < m; i++ ){
      scanf("%d %d %lld", &source, &target, &cost );
      source--; target--;
      if ( source == target ) continue;
      D[source][target] = D[target][source] = cost;
      C[source][target] = C[target][source] = max( feast[source], feast[target]);
    }
    return true;
  }
};

main(){
  AsterixObelix AO;
  for ( int i = 1; AO.read(); i++ ){
    printf("Case #%d\n", i );
    AO.work();
    printf("\n");
  }
}

// @end_of_source_code


