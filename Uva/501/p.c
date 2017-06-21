// @JUDGE_ID:  17051CA  501  C++
// @begin_of_source_code
/* Simulaton */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int M, N;
vector<long> A;
vector<int> U;
vector<long> B;

int read(){
  cin >> M >> N;
  A.clear();
  U.clear();

  A.resize( M );
  U.resize( N );

  for ( int i = 0; i < M; i++ ){
    cin >> A[i];
  }

  for ( int i = 0; i < N; i++ ){
    cin >> U[i];
  }

}

void work(){

  B.clear();

  int cursor = 0;
  int i = 0;
  for ( int a = 0; a < A.size(); a++ ){

    B.insert( lower_bound(B.begin(), B.end(), A[a]), A[a] );

    while( cursor < U.size() &&  U[cursor] == B.size() ){
      i++;
      cout << B[i-1] << endl;
      cursor++;
    }

    
  }

}

main(){
  int t;
  cin >> t;
  for ( int i = 0; i < t; i++ ){
    if ( i ) cout << endl;
    read();
    work();
  }
}
// @end_of_source_code
