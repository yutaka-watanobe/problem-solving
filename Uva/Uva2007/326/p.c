// @JUDGE_ID:  17051CA  326  C++
// @begin_of_source_code
/* Calculation */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

vector<vector<int> > T;
vector<int> V;
int n, k;

int read(){
  T.clear();
  V.clear();
  cin >> n;
  if ( n == 0 ) return 0;

  T.resize( n );
  T[0].resize( n );
  V.resize( n );

  for ( int i = 0; i < n; i++ ){
    cin >> T[0][n-i-1];
  }

  cin >> k;

  /* create */
  for ( int i = 0; i < n-1; i++ ){
    for ( int j = 0; j < T[i].size()-1; j++ ){
      T[i+1].push_back( T[i][j] - T[i][j+1] );
    }
  }

  for ( int i = 0; i < n; i++ ){
    V[i] = T[i][0];
  }
  return 1;
}

void extrapolation(){
  for ( int i = n-2; i >=0; i-- ){
    V[i] = V[i] + V[i+1];
  }
}

void work(){

  for ( int i = 0; i < k; i++ ){
    extrapolation();
  }

  cout << "Term " << n+k << " of the sequence is " << V[0] << endl;
}

main(){
  while ( read() ){
    work();
  }
}
// @end_of_source_code
