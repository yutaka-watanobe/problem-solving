/********************
 * 8 queens problem *
 ********************/
/* 回転,対称をのぞきユニークな１２個の解を出力 */

#include<stdio.h>
#include<iostream>
#define N 8
#define SUCCESS 1
#define FAIL 0
#define FREE 1
#define NOT_FREE 0

int row[N], col[N], pos[2*N-1], neg[2*N-1];
int sum;

void create( int board[N][N]){
  int i, j;
  for ( i = 0; i < N; i++ ){
    for ( j = 0; j < N; j++ ){
      if ( row[i] == j ) board[i][j] = 1;
      else board[i][j] = 0;
    }
  }
}

void cop( int dst[N][N], int src[N][N] ){
  int i, j;
  for ( i = 0; i < N; i++ ){
    for ( j = 0; j < N; j++ ){
      dst[i][j] = src[i][j];
    }
  }
}

void rot( int dst[N][N], int src[N][N] ){
  int i, j;
  int m[N][N];
  for ( i = 0; i < N; i++ ){
    for ( j = 0; j < N; j++ ){
      m[j][N-i-1] = src[i][j];
    }
  }
  cop(dst, m);
}

void mir ( int dst[N][N], int src[N][N] ){
  int i, j;
  int m[N][N];
  for ( i = 0; i < N; i++ ){
    for ( j = 0; j < N; j++ ){
      m[N-i-1][j] = src[i][j];
    }
  }
  cop(dst, m);
}

int cmp( int a[N][N], int b[N][N] ){
  int i, j;
  for ( i = 0; i < N; i++ ){
    for ( j = 0; j < N; j++ ){
      if ( a[i][j] != b[i][j] ) return b[i][j];
    }
  }
  return 0;
}

void print(){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(row[i]==j) cout << "Q";
      else cout << ".";
    }
    cout << endl;
  }
  cout << endl;
  sum++;
}

bool check(){
  int i, m[N][N], board[N][N];
  create( board );
  cop ( m, board );
  for ( i = 1; i <= 3; i++ ){
    rot ( m, m );
    if ( cmp( board, m ) ) return false;
  }
  mir ( m, board );
  if ( cmp(board, m ) ) return false;
  for ( i = 1; i <= 3; i++ ){
    rot ( m, m );
    if ( cmp( board, m ) ) return false;
  }
  return true;
}

void tryqueen(int i, int j){

  if(!(col[j]==FREE && pos[i+j]==FREE && neg[i-j+N-1]==FREE))
    return;
  
  row[i] = j; 
  col[j] = NOT_FREE;
  pos[i+j] = NOT_FREE;
  neg[i-j+N-1] = NOT_FREE;
  
  if(i==N-1){
    if ( check() ) print();
  }else{
    for(int z=0; z<N; z++){
      tryqueen(i+1, z);
    }
  }
  row[i] = -1;
  col[j] = FREE;
  pos[i+j] = FREE;
  neg[i-j+N-1] = FREE;
}

main(){
  for(int i=0; i<N; i++) {row[i] = -1; col[i] = FREE;}
  for(int i=0; i<2*N-1; i++){pos[i] = FREE; neg[i] = FREE;}

  sum = 0;
  for(int j=0; j<N; j++){
    tryqueen(0, j);
  }

  cout << sum << endl;
}

