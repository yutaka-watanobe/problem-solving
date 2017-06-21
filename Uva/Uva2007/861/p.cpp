// Backtracking
// two parts -->  BLACK and WHITE
#include<stdio.h>
#include<iostream>
#define BLACK 0
#define WHITE 1

int T[8][64];
int B[2][9][65];

bool horizon[20];
bool vertical[20];

int mode;
int size;

void recursive( int i, int j, int currentk ){

  if ( j >= size ){  
    i++;
    if ( mode == BLACK ) j = ( i % 2 == 0 )? 0 : 1;
    else   j = ( i % 2 == 0 )? 1 : 0;
  }

  if ( i >= size ) return;

  int h, v;
  bool tmph, tmpv;

  h = j - i + size - 1;
  v = i + j;
  tmph = horizon[h];
  tmpv = vertical[v];
  
  // not put
  recursive( i, j + 2, currentk );
  
  if ( !(horizon[h] || vertical[v]) ){
  
    horizon[h] = vertical[v] = true;

    B[mode][size][currentk + 1]++;    

    recursive( i, j+2, currentk + 1 );
    
    horizon[h] = tmph;
    vertical[v] = tmpv;
  }
}

void initVisited(){
  for ( int i = 0; i < size*2; i++ ){
    horizon[i] = false;
    vertical[i] = false;
  }
}

void init(){

  for (int i = 0; i <= 8; i++ ){
    for ( int j = 0; j <= 64; j++ ) B[BLACK][i][j] = B[WHITE][i][j] = 0;
    B[BLACK][i][0] = B[WHITE][i][0] = 1;
  }

  for ( size = 1; size <= 8; size++ ){
    mode = BLACK;
    initVisited();
    recursive( 0, 0, 0 );
  }

  for ( size = 1; size <= 8; size+=2 ){
    mode = WHITE;
    initVisited();
    recursive( 0, 1, 0 );
  }

  for ( int s = 1; s <= 8; s++ ){
    for ( int k = 0; k <= s*s; k++ ) T[s][k] = 0;

    for ( int k = 0; k <= s*s; k++ ){

      if ( s % 2 == 0 ){
	for ( int l = 0; l <= k; l++ ){
	  T[s][k] += B[BLACK][s][l]*B[BLACK][s][k-l];
	}
      } else {
	for ( int l = 0; l <= k; l++ ){
	  T[s][k] += B[BLACK][s][l]*B[WHITE][s][k-l];
	}
      }

    }
  }
}

main(){
  init();
  int n, k;
  while ( 1 ){ 
    scanf("%d %d", &n, &k);
    if ( n == 0 && k == 0 ) break;
    printf("%d\n", T[n][k]);
  }
}
