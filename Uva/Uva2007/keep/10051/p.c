// @JUDGE_ID:  17051CA  10051  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>

#define MAX 501

int N;
int M[MAX][6];
int P[MAX][6];
int L[MAX][6];

int BT[6] = {1, 0, 3, 2, 5, 4};

int read(){
  cin >> N;
  if ( N == 0 ) return 0;
  for ( int i = 0; i < N; i++ ){
    for ( int j = 0; j < 6; j++ ){
      cin >> M[i][j];
    }
  }

  return 1;
}

void work(){
  pair<int, int> longest;
  int len = 0;
  
  for ( int i = 0; i < N; i++ ) {
    fill ( L[i], L[i] + 6, 0 );
  }

  for ( int i = 0; i < N - 1; i++ ){
    for ( int j = 0; j < 6; j++ ){
      for ( int k = 0; k < 6; k++ ){
	if ( M[i][BT[j]] == M[i+1][k] ({
	  if( L[i][BT[j]] + 1 > L[i+1][k] ){
	    L[i+1][k] = L[i][BT[j]] + 1;
	  }
	}else{
	  if( L[i][BT[j]] > L[i+1][k] ){
	    L[i+1][k] = L[i][BT[j]];
	  }
	}
      }
    }
  }
  
  for ( int i = 0; i < N; i++ ){
    for ( int j = 0; j < 6; j++ ){
      cout << L[i][j] << " ";
    }
    cout << endl;
  }
}

main(){
  for ( int i = 1; read(); i++ ){
    if ( i > 1 ) cout << endl;
    cout << "Case #" << i << endl;
    work();
  }
}
// @end_of_source_code
