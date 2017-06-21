// @JUDGE_ID:  17051CA  108  C++
// @begin_of_source_code
/* Maximum Sum - DP */
/* 0.489 sec */
#include<stdio.h>
#include<iostream>
#include<stl.h>
#define MAX 105

int N; /* size of matrix */
int M[ MAX ][ MAX ]; /* input matrix */
int T[ MAX + 1 ]; /* 1 array matrix for DP */
int S[ MAX + 1 ]; /* cost table for DP */
int max_value;

void read(){
  cin >> N;
  for ( int i = 0; i < N; i++ ){
    for ( int j = 0; j < N; j++ ){
      cin >> M[i][j];
    }
  }
}

/* find maximum sum by DP */
void find_max(){
  S[0] = 0;
  int current_max = -INT_MAX;

  for ( int i = 1; i <= N; i++ ){
    if ( S[i-1] >= 0 ){
      S[i] = S[i-1] + T[i];
    } else {
      S[i] = T[i];
    }
    current_max = max( current_max, S[i] );
  }

  max_value = max( max_value, current_max );
}

void work(){

  max_value = -INT_MAX;

  for ( int k = 1; k <= N; k++ ){
    for ( int i = 0; i <= N - k; i++ ){
      for ( int j = 0; j < N; j++ ){
	T[j+1] = 0;
	for ( int m = i; m < i + k; m++ ){
	  T[j+1] += M[ m ][ j ];
	}
      }
      find_max();
    }
  }

  cout << max_value << endl;
}

main(){
  read();
  work();
}

// @end_of_source_code
