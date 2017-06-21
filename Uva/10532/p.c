// @JUDGE_ID:  17051CA  10532  C++
// @begin_of_source_code
/* Combination - Dynamic Programming */
#include<stdio.h>
#include<iostream>
#include<stl.h>
#define MAX 51
typedef unsigned long long ullong;

int n, m;
vector<int> G;
vector<int> T;
void combination( int );

int read(){
  cin >> n >> m;
  if ( n == 0 && m == 0 ) return 0;
  T.clear(); 
  G.clear();
  T.resize( n );
  for ( int i = 0; i < n; i++ ){
    cin >> T[i];
  }

  sort( T.begin(), T.end() );
  T.push_back( T[T.size()+1] + 1 );

  int cnt = 1;
  for ( int i = 0; i < T.size() - 1; i++ ){
    if ( T[i] != T[i+1] ){
      G.push_back( cnt );
      cnt = 1;
    }else{
      cnt++;
    }
  }

  return 1;
}

void work(){
  int r;
  for ( int i = 0; i < m; i++ ){
    cin >> r;
    combination( r );
  }
}

void combination(int r){
  ullong M[MAX][MAX];
  int g = G.size();

  /* init */
  for ( int i = 0; i <= r; i++ ){
    fill ( M[i], M[i] + g , 0 ); 
  }

  for ( int i = 0; i <= G[0]; i++ ){
    M[i][0] = 1;
  }
  
  for ( int j = 1; j < g; j++ ){
    for ( int i = 0; i <= r; i++ ){
      for ( int k = 0; k <= G[j]; k++ ){
	int index = i - k;
	if ( index >= 0 ) M[i][j] += M[index][j-1];
      }
    }
  }
  
  cout << M[r][G.size()-1] << endl;
  
}

main(){
  for ( int i = 1; read(); i++ ) {
    cout << "Case " << i << ":" << endl;
    work();
  }
}
// @end_of_source_code
