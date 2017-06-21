// @JUDGE_ID:  17051CA  10474  C++
// @begin_of_source_code
/* Binary Search */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stl.h>

class WhereIsTheMarble{
 public:
  int N, Q;
  vector<int> M;

  void work(){
    sort( M.begin(), M.end() );

    vector<int>::iterator pos;

    int target;
    for ( int i= 0; i < Q; i++ ){
      scanf( "%d", &target );

      if ( binary_search( M.begin(), M.end(), target ) ){
	pos = lower_bound( M.begin(), M.end(), target );
	printf("%d found at %d\n", target, distance( M.begin(), pos ) + 1 );
      } else {
	printf("%d not found\n", target );
      } 

    }
    
  }

  bool read(){
    scanf( "%d %d", &N, &Q );
    if ( N == 0 && Q == 0 ) return false;

    M.clear();
    M.resize( N );

    for ( int i = 0; i < N; i++ ){
      scanf("%d", &M[i] );
    }

    return true;
  }

};

main(){
  WhereIsTheMarble WITM;
  for ( int i = 1; WITM.read(); i++ ){
    printf("CASE# %d:\n", i );
    WITM.work();
  }
}

// @end_of_source_code


