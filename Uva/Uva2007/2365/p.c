// @JUDGE_ID:  17051CA  2365  C++
// @begin_of_source_code
/* Simulation */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
#define MAX 20
#define D_SIZE 16

int dx[5] = {0, 0, -1, 0, 1};
int dy[5] = {0, 1, 0, -1, 0};
char density_char[4] = {'.', '!', 'X', '#'};

int D[ D_SIZE ];
int M[ MAX + 2][ MAX + 2]; /* current matrix ( + banpei )*/
int T[ MAX + 2][ MAX + 2]; /* tmp matrix ( + banpei )*/
int days;

void read(){
  
  while ( 1 ){
    cin >> days;
    if ( days ) break;
  }

  for ( int j = 0; j < D_SIZE; j++ ){
    cin >> D[j];
  }

  /* init */
  for ( int i = 0; i < MAX + 2; i++ ){
    for ( int j = 0; j < MAX + 2; j++ ){
      M[i][j] = 0;
    }
  }

  for ( int i = 1; i <= MAX; i++ ){
    for ( int j = 1; j <= MAX; j++ ){
      cin >> M[i][j];
    }
  }
  
}

void simulate(){
  int nx, ny;
  int sum;

  for ( int i = 1; i <= MAX; i++ ){
    for ( int j = 1; j <= MAX; j++ ){
      sum = 0;
      for ( int r = 0; r < 5; r++ ){
	nx = i + dx[r];
	ny = j + dy[r];
	sum += M[nx][ny];
      }
      T[i][j] = D[ sum ];
    }
  }
  
  for ( int i = 1; i <= MAX; i++ ){
    for ( int j = 1; j <= MAX; j++ ){
      int result = T[i][j] + M[i][j];
      if ( result > 3 ) result = 3;
      if ( result < 0 ) result = 0;
      M[i][j] = result;
    }
  }
}

void printResult(){
  for ( int i = 1; i <= MAX; i++ ){
    for ( int j = 1; j <= MAX; j++ ){
      cout << density_char[ M[i][j] ];
    }
    cout << endl;
  }
}

void work(){
  for ( int i = 0; i < days; i++ ){
    simulate ();
  }
  printResult();
}

main(){
  int t_case;
  
  cin >> t_case;

  for ( int i = 0; i < t_case; i++ ){
    if ( i ) cout << endl;
    read();
    work();
  }
}

// @end_of_source_code
