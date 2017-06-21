// @JUDGE_ID:  17051CA  10003  C++
// @begin_of_source_code
/* Dynamic Programming */
/* Matrix Chain Multiplication คฮฑþอั */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#define MAX 1010

int total;
int n, N;
int S[MAX + 1];
int cost[MAX][MAX];

int read(){
  cin >> total;
  if ( total == 0 ) return 0;
  cin >> n;
  int pre = 0;
  int k;

  N = n + 1;

  for ( int i = 0; i < n; i++ ){
    cin >> k;
    S[i] = k - pre;
    pre = k;
  }
  S[n] = total - pre;

  return 1;
}

void work(){
  
  for ( int l = 2; l <= N; l++ ){
    for ( int i = 0; i < N - l + 1; i++ ){
      int j = i + l - 1;
      cost[i][j] = INT_MAX;
      for ( int k = i; k <= j-1; k++ ){
	int q = cost[i][k] + cost[k+1][j];
	if ( q < cost[i][j] ) cost[i][j] = q;
      }
      for ( int m = i; m <= j; m++ ){
	cost[i][j] += S[m];
      }
    }
  }

  cout << "The minimum cutting is " << cost[0][n] << "." << endl;
  
}

main(){
  while ( read() ) work();
}
// @end_of_source_code
