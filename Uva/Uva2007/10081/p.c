// @JUDGE_ID:  17051CA  10081  C++
// @begin_of_source_code
/* Doulbe Calculation + DP ! */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#define MAX 101

int n, k;
int cnt;

int read(){
  cin >> k >> n;
  if ( cin.eof() ) return 0;
  return 1;
}

void work(){
  if ( k == 0 ){
    printf("%.5f\n", 100.0 );
    return ;
  }

  double T[10][MAX];
  
  for ( int i = 0; i < 10; i++ ){
    fill ( T[i], T[i] + n, 0 );
  }

  for ( int i = 0; i <= k; i++ ) T[i][0] = 1;

  for ( int i = 0; i < n-1; i++ ){
    T[0][i+1] += T[0][i]; 
    T[1][i+1] += T[0][i];
    for ( int j = 1; j < k; j++ ){
      T[j][i+1] += T[j][i];
      T[j+1][i+1] += T[j][i];
      T[j-1][i+1] += T[j][i];
    }
    T[k][i+1] += T[k][i]; 
    T[k-1][i+1] += T[k][i];
  }
  
  double cnt = 0;
  for ( int i = 0; i <= k; i++ ){
    cnt += T[i][n-1];
  }

//  cout << cnt << endl;
  double p  = cnt;
  for  ( int i = 0; i < n; i++ ){
    p /= (k+1);
  }

  printf("%.5f\n", p*100 );
}

main(){
  while ( read() ) work();
}
// @end_of_source_code
