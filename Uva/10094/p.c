// @JUDGE_ID:  17051CA  10094  C++
// @begin_of_source_code
/* N Queens Problem */
/* create only one solusion ( very big size ) */
#include<stdio.h>
#include<iostream>
#include<vector>

vector<int> getQueenPositions( int );

int mod(int n, int m ){
  while( n >= m ){
    n -= m;
  }
  return n;
}

bool isEven( int n ){
  return ( n == 2*(n/2) );
}

int queenMod( int r, int n ){
  return ( mod((2*r + n/2 - 3 ), n) );
}

vector<int> getEvenQueens1( int n ){
  vector<int> P;
  P.resize( n );
  for ( int row = 1; row <= n/2; row++ ){
    P[row-1] = 2*row;
  }
  for ( int row = n/2+1; row <= n; row++ ){
    P[row-1] = 2 * row - n - 1;
  }
  return P;
}

vector<int> getEvenQueens2( int n ){
  vector<int> P;
  P.resize( n );
  for ( int row = 1; row <= n/2; row++ ){
    P[row-1] = queenMod(row, n) + 1;
  }
  for ( int row = n/2+1; row <=n; row++ ){
    P[row-1] = n - queenMod(n - row +1, n );
  }
  return P;
}

vector<int> getOddQueens( int n ){
  vector<int> EP = getQueenPositions( n -1 );
  vector<int> P;
  P.resize( n );
  for ( int i = 0; i < n - 1; i++ ){
    P[i] = EP[i];
  }
  P[n-1] = n;
  return P;
}

vector<int> getQueenPositions( int n ){
  if ( isEven( n ) && ( mod(n, 6) != 2 ) ){
    return getEvenQueens1( n );
  } else if ( isEven( n ) ){
    return getEvenQueens2( n );
  } else {
    return getOddQueens( n );
  }
}

void work(int k){
  if ( k == 2 || k == 3 ) {
    cout << "Impossible" << endl;
    return ;
  }
  vector<int> q = getQueenPositions( k );
  for ( int i = 0; i < k; i++ ){
    if ( i ) cout << " ";
    cout << q[i];
  }
  cout << endl;
}

main(){
  int n;
  while ( cin >> n ){
    work( n );
  }
}
// @end_of_source_code
