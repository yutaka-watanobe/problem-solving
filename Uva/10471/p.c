// @JUDGE_ID:  17051CA  10471  C++
// @begin_of_source_code
/* Tree + Recursion */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stl.h>

int power(int x, int n){
  int tmp = 1;

  if(n>0){
    tmp = power(x, n/2);
    if(n%2==0) tmp = tmp*tmp;
    else tmp = tmp*tmp*x;
  }
  return tmp;
}

class CantBeTooGreedy{
 public:
  int K;
  int cursor;
  vector<vector<int> > colorTable;

  void recursion( int parent, int degree ){
    
    for ( int i = 1; i <= degree; i++ ){
      cursor++;
      colorTable[ i - 1 ].push_back( cursor );
      cout << parent << " " << cursor << endl;

      recursion( cursor, i - 1 );
    }

  }

  void work(){
    int nnode = power( 2, K - 1);
    cout << nnode << " " << nnode - 1 << endl;

    cursor = 1;
    recursion( cursor, K - 1 );

    colorTable[ K - 1 ].push_back( 1 );

    for ( int i = 0; i < K; i++ ){
      for ( int j = 0; j < colorTable[i].size(); j++ ){
	if ( !( i == 0 && j == 0 ) ) cout << " ";
	cout << colorTable[i][j];
      }
    }
    cout << endl;
  }

  bool read(){
    if ( ! ( cin >> K ) ) return false;
    colorTable.clear();
    colorTable.resize( K );
    return true;
  }
};

main(){
  CantBeTooGreedy greedy;
  while ( greedy.read() ){
    greedy.work();
  }
}

// @end_of_source_code


