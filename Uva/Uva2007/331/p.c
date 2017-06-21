// @JUDGE_ID:  17051CA  331  C++
// @begin_of_source_code
/* Backtracking */
/* 0.625 sec --> not so good */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
#include<stl.h>

class MappingTheSwap{
 public:
  int N;
  int current[ 6 ];

  int minimumCost;
  int frequency;

  int limit;

  bool isOrdered(){
    for ( int i = 0; i < N-1; i++ ){
      if ( current[i] > current[i+1] ) return false;
    }
    return true;
  }

  void recursive( int depth, int pre ){

    if ( isOrdered() ){
      if ( minimumCost == depth ) frequency++;
      else if ( minimumCost > depth ){
	minimumCost = depth;
	frequency = 1;
      }
      return;
    }
    
    if ( depth > minimumCost ) return ;

    int tmp[ 6 ];

    for ( int i = 0; i < N - 1; i++ ){
      if ( i == pre ) continue;
      memcpy( tmp, current, sizeof( tmp ) );
      current[i] = tmp[i+1];
      current[i+1] = tmp[i];
      recursive( depth + 1, i );
      memcpy( current, tmp, sizeof( current ) );
    }

  }

  int getSwapMap(){
    return frequency;
  }

  void setLimit(){
    limit = 0;
    for ( int i = 1; i < N; i++ ){
      limit += i;
    }
  }

  void work(){
    setLimit();
    minimumCost = limit;
    frequency = 0;
    if ( isOrdered() ) return;
    recursive( 0, -1 );
  }

  bool read(){
    cin >> N;
    if ( N == 0 ) return false;

    for ( int i = 0; i < N ; i++ ){
      cin >> current[i];
    }

    return true;
  }

};

main(){
  MappingTheSwap MTS;
  for ( int i = 1; MTS.read(); i++ ){
    MTS.work();
    cout << "There are " << MTS.getSwapMap();
    cout << " swap maps for input data set " << i << "." << endl;
  }
}


// @end_of_source_code


