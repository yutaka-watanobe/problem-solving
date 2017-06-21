// @JUDGE_ID:  17051CA  2432  C++
// @begin_of_source_code
/* Graph Ordering */
#include<stdio.h>
#include<iostream>
#include<vector>
#define MAX 102

class ProjectFile{
 public:
  int M[ MAX ][ MAX ];
  int inD[ MAX ];
  int used[ MAX ];
  int N;
  vector<int> path;

  int getCandidate(){
    int v = INT_MAX;
    
    for ( int i = 0; i < N; i++ ){
      if ( used[i] ) continue;
      
      if ( inD[ i ] == 0 && i < v ){
	v = i;
      }

    }

    if ( v != INT_MAX ) {
      used[v] = 1;
      for ( int i = 0; i < N; i++ ){
	if ( M[v][i] ){
	  M[v][i] = 0;
	  inD[i]--;
	}
      }
    }

    return v;
  }

  void work(){

    path.clear();
    int v;
    while ( ( v = getCandidate() ) != INT_MAX ){
      path.push_back( v + 1 );
    } 

    for ( int i = 0; i < N; i++ ){
      printf("%d ", path[i] );
    }
    printf("\n");
  }

  void read(){
    scanf("%d", &N );
    for ( int i = 0; i < N; i++ ){
      inD[i] = 0;
      used[i] = 0;
      for ( int j = 0; j < N; j++ ) M[i][j] = 0;
    }

    int m, k, source, target;
    scanf("%d", &m );
    for ( int i = 0; i < m; i++ ){
      scanf("%d %d", &target, &k);
      for ( int j = 0; j < k; j++ ){
	scanf("%d", &source);
	M[source-1][target-1] = 1;
	inD[ target-1 ]++;
      }
    }
  }

};

main(){
  ProjectFile PF;
  int tcase;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    if ( i ) cout << endl;
    PF.read();
    PF.work();
  }
}
// @end_of_source_code


