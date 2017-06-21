// @JUDGE_ID:  17051CA  679  C++
// @begin_of_source_code
/* Tree Indexing ? */
/* 1.3 sec */
#include<stdio.h>
#include<iostream>
#include<stl.h>
#include<vector>
#define MAX 524289

vector<vector<int> > M; /* map */
int D, I, N;
int leaf;

int power( int x, int n ){
  int tmp = 1;
  if(n>0){
    tmp = power(x, n/2);
    if(n%2==0) tmp = tmp*tmp;
    else tmp = tmp*tmp*x;
  }
  return tmp;
}

bool read(){
  cin >> D >> I;
  if ( D == -1 ) return false;
  return true;
}

void createMap(){
  for ( int d = 2; d <= 20; d++ ){
    int index = 0;
    int n = power( 2, d - 1 );
    M[d].resize( n );
    M[d][0] = index++;
    
    int p = 1;
    int dec = n / 2;
    
    while ( 1 ){
      if ( index >= n ) break;
      for ( int i = 0; i < p; i++ ){
	int pos = M[d][ i ];
	M[d][ pos + dec ] = index;
	M[d][index] = pos + dec;
	index++;
      }
      p *= 2;
      dec /= 2;
    }
  }

}

void work(){
  N = power( 2, D - 1 );
  I--;
  I = I % N;
  cout << N + M[ D ][ I ] << endl;
}

main(){
  M.resize( 21 );
  createMap();
  int t;
  cin >> t;
  for ( int i = 0; i < t; i++ ){
    read();
    work();
  }
}
// @end_of_source_code
