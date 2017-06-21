#include<stdio.h>


int board[100][100];

int n;
int cnt;

void print(){
  for ( int i = 0; i < n; i++ ){
    for ( int j = 0; j < n; j++ ){
      printf( "%d", board[i][j] );
    }
    printf("\n");
  }
  printf("\n");
}


void work(){

  for ( int a = 2; a <= n-2; a++ ){
    for ( int b = 0; b <= n-1; b++ ){
      /* init */
      for ( int x = 0; x < n; x++ ){
	for ( int y = 0; y < n; y++ ){
	  board[x][y] = 0;
	}
      }

      for ( int x = 0; x < n; x++ ){
	int y = ( a*x + b )%n;
	board[x][y] = 1;
      }
      print(); cnt++;
    }
  } 

  printf("%d\n ", cnt );
}

main(){
  n = 5;
  cnt = 0;
  work();
}
