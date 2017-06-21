// BINGO simulation
#include<stdio.h>
#define SIZE 5
#define ANNOUNCE 75
#define NON (-1)

bool visited[SIZE][SIZE];
int buffer[ANNOUNCE + 1];

bool parse(){
  for ( int i = 0; i < SIZE; i++ ){
    bool bingo = true;
    for ( int j = 0; j < SIZE; j++ ){
      if ( visited[i][j] == false ) bingo = false;
    }
    if ( bingo ) return true;
  }

  for ( int j = 0; j < SIZE; j++ ){
    bool bingo = true;
    for ( int i = 0; i < SIZE; i++ ){
      if ( visited[i][j] == false ) bingo = false;
    }
    if ( bingo ) return true;
  }

  bool bingo = true;
  for ( int i = 0; i < SIZE; i++ ){
    if ( visited[i][i] == false ) bingo = false;
  }
  if ( bingo ) return true;
  bingo = true;

  for ( int i = 0; i < SIZE; i++ ){
    if ( visited[SIZE - i - 1][i] == false ) bingo = false;
  }

  if ( bingo ) return true;

  return false;
}

void work(){

  int bingo = -1;
  int number;

  for ( int current = 1; current <= ANNOUNCE; current++ ){
    scanf("%d", &number);

    int pos = buffer[ number ];
    if ( pos == NON ) continue;

    visited[ pos / SIZE ][ pos % SIZE ] = true;
    if( bingo == -1 && parse() ) {
      bingo = current;
    }
  }

  printf("BINGO after %d numbers announced\n", bingo);

}

void read(){

  for ( int i = 0; i < SIZE; i++ ){
    for ( int j = 0; j < SIZE; j++ ){
      visited[i][j] = false;
    }
  }

  visited[2][2] = true;

  for ( int i = 0; i <= ANNOUNCE; i++ ) buffer[i] = NON;
  int number;

  for ( int i = 0; i <= 11; i++ ){
    scanf("%d", &number);
    buffer[number] = i;
  }

  for ( int i = 13; i < 25; i++ ){
    scanf("%d", &number);
    buffer[number] = i;
  }

}

main(){

  int tcase; scanf("%d", &tcase);

  for (int i = 0; i < tcase; i++ ){
    read();
    work();
  }
}




