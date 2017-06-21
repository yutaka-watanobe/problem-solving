// @JUDGE_ID:  17051CA  542  C++
// @begin_of_source_code
/* Calculation */
#include<stdio.h>
#include<iostream>
#include<string>
#define MAX 16

string C[MAX]; /* country */
double T[MAX][MAX]; /* table */
double W[4][MAX]; /* win */

void read(){
  string line;

  for ( int i = 0; i < MAX; i++ ){
    cin >> line;
    while ( line.size() < 10 ) line += " ";
    C[i] = line;
  }

  for ( int i = 0; i < MAX; i++ ){
    for ( int j = 0; j < MAX; j++ ){
      cin >> T[i][j];
      T[i][j] *= 0.01;
    }
  }
}

void work(){
  /* 1 win */
  for ( int i = 0; i < MAX; i++ ){
    if ( i % 2 == 0 ){
      W[0][i] = T[i][i+1];
    } else {
      W[0][i] = T[i][i-1];
    }
  }

  /* semi final */
  for ( int i = 0; i < MAX; i++ ){
    int t1, t2;
    if ( i % 4 < 2 ){
      t1 = (i - i%4) + 2;
      t2 = (i - i%4) + 3;
    } else {
      t1 = (i - i%4);
      t2 = (i - i%4) + 1;
    }
    W[1][i] = W[0][i]*(W[0][t1]*T[i][t1] + W[0][t2]*T[i][t2] );
  }

  /* final */
  for ( int i = 0; i < 4; i++ ){
    W[2][i] = 0;
    for ( int t = 4; t < 8; t++ ){
      W[2][i] += W[1][i]*W[1][t]*T[i][t];
    }
  }
  for ( int i = 4; i < 8; i++ ){
    W[2][i] = 0;
    for ( int t = 0; t < 4; t++ ){
      W[2][i] += W[1][i]*W[1][t]*T[i][t];
    }
  }

  for ( int i = 8; i < 12; i++ ){
    W[2][i] = 0;
    for ( int t = 12; t < 16; t++ ){
      W[2][i] += W[1][i] * W[1][t] * T[i][t];
    }
  }
  for ( int i = 12; i < 16; i++ ){
    W[2][i] = 0;
    for ( int t = 8; t < 12; t++ ){
      W[2][i] += W[1][i] * W[1][t] * T[i][t];
    }
  }

  /* champion */
  for ( int i = 0; i < 8; i++ ){
    W[3][i] = 0;
    for ( int t = 8; t < 16; t++ ){
      W[3][i] += W[2][i] * W[2][t] * T[i][t];
    }
  }
  for ( int i = 8; i < 16; i++ ){
    W[3][i] = 0;
    for ( int t = 0; t < 8; t++ ){
      W[3][i] += W[2][i] * W[2][t] * T[i][t];
    }
  }

  
  for ( int i = 0; i < MAX; i++ ){
    cout << C[i];
    printf(" p=%.2lf", W[3][i] * 100 );
    cout << "%" << endl;
  }

}

main(){
  read();
  work();
}
// @end_of_source_code
