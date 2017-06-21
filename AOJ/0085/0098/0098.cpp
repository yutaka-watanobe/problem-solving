#include<stdio.h>
#include<iostream>
using namespace std;
#define MAX 105

int N; /* size of matrix */
long long M[ MAX ][ MAX ]; /* input matrix */
long long T[ MAX + 1 ]; /* 1 array matrix for DP */
long long S[ MAX + 1 ]; /* cost table for DP */
long long max_value;

void read(){
  cin >> N;

  for ( int i = 1; i <= N; i++ ){
    for ( int j = 1; j <= N; j++ ){
      cin >> M[i][j];
    }
  }
}

/* find maximum sum by DP */
void find_max(){
  S[0] = 0;
  long long current_max = -1000000000;

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
  long long A[MAX][MAX];
  for ( int j = 1; j <= N; j++) A[0][j] = 0;
  for ( int j = 1; j <= N; j++ ){
    for ( int i = 1; i <= N; i++ ){
      A[i][j] = A[i-1][j] + M[i][j];
    }
  }

  max_value = -1000000000;

  for ( int i = 1; i <= N; i++ ){
    for ( int k = i; k <= N; k++ ){
      for ( int j = 1; j <= N; j++ ){
	T[j] = A[k][j] - A[i-1][j];
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
