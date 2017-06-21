// @JUDGE_ID:  17051CA  580  C++
// @begin_of_source_code
/* Dynamic Programming */
#include<stdio.h>
#include<iostream>
#include<string>
#define MAX 32

int n;
int M[MAX][3];
int P[MAX];

int read(){
  cin >> n;
  if ( n == 0 ) return 0;
  return 1;
}

void init(){
  M[1][0] = 1;
  M[1][1] = 1;
  M[1][2] = 0;

  for ( int i = 2; i < MAX; i++ ){
    M[i][0] = M[i-1][0] + M[i-1][1] + M[i-1][2];
    M[i][1] = M[i-1][0];
    M[i][2] = M[i-1][1];
  }

  P[0] = 0;
  P[1] = 2;
  for ( int i = 2; i < MAX; i++ ){
    P[i] = P[i-1]*2;
  }

}

void work(){
  cout << P[n] - ( M[n][0] + M[n][1] + M[n][2]) << endl;
}

main(){
  init();
  while ( read() ) work();
}
// @end_of_source_code
