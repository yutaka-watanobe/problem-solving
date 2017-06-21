// @JUDGE_ID:  17051CA  10450  C++
// @begin_of_source_code
/* DP - Counting */
#include<stdio.h>
#include<iostream>
#define MAX 51
typedef unsigned long long ullong;

ullong M[MAX];

void init(){
  M[0] = 1;
  M[1] = 2;
  M[2] = 3;
  for ( int i = 3; i < MAX; i++ ){
    M[i] = M[i-1] + M[i-2];
  }
}

void work(){
  int n;
  cin >> n;
  cout << M[n] << endl;
  cout << endl;
}

main(){
  init();
  int t;
  cin >> t;
  for ( int i = 1; i <= t; i++ ){
    cout << "Scenario #" << i << ":" << endl;
    work();
  }
}
// @end_of_source_code
