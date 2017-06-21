// @JUDGE_ID:  17051CA  10164  C++
// @begin_of_source_code
/* Backtrack */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

int N;
vector<int> P;
vector<int> V;

int read(){
  cin >> N;
  if ( N == 0 ) return 0;

  V.clear();
  V.resize( 2*N - 1 );
  
  for ( int i = 0; i < 2*N-1; i++ ){
    cin >> V[i];
  }
  return 1;
}

bool rec( int index, int cnt, int sum ){
  if( cnt == N ){
    if ( sum % N == 0 ) return true;
    else return false;
  }

  if( index >= V.size() ) return false;

  P.push_back( V[index] );

  if ( !rec( index+1, cnt + 1, sum + V[index]) ) {
    P.erase( P.begin() + P.size()-1 );
    return rec( index+1, cnt, sum );
  }else{
    return true;
  }

}

void work(){
  P.clear();

  if ( rec( 0, 0, 0 ) ){
    cout << "Yes" << endl;
    for ( int i = 0; i < P.size(); i++ ){
      if ( i ) cout << " ";
      cout << P[i];
    }
    cout << endl;
  } else {
    cout << "No" << endl;
  }
}

main(){
  while ( read() ){
    work();
  }
}
// @end_of_source_code
