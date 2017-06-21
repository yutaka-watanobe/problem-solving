// @JUDGE_ID:  17051CA  647  C++
// @begin_of_source_code
/* Simulation - SuGoRoKu */
#include<stdio.h>
#include<iostream>
#include<stl.h>
#define NOTHING 0
#define CHUTE 1
#define LADDER 2
#define MISS 3
#define TURN 4

int die[ 1001 ];
int nplayer;
int boardState[ 101 ];
int boardTarget[ 101 ];
bool missed[ 7 ];
int position[ 7 ];
bool determined;
int player;
int current;

void nextPlayer(){
  player++;
  if ( player > nplayer ) player = 1;
}

void play(){
  if ( missed[ player ] ){
    missed[ player ] = false;
    nextPlayer();
    return ;
  }

  int target = position[ player ] + die[ current++ ];

  if ( target == 100 ){
    determined = true;
    return ;
  }
  if ( target > 100 ){
    nextPlayer();
    return ;
  }

  position[ player ] = target;

  if ( boardState[ target ] == CHUTE || boardState[ target ] == LADDER ){
    target = boardTarget[ target ];
    if ( target == 100 ){
      determined = true;
    } else {
      position[ player ] = target;
      nextPlayer();
    }
  } else if ( boardState[ target ] == MISS ){
    missed[ player ] = true;
    nextPlayer();
  } else if ( boardState[ target ] == TURN ){
    return;
  } else {
    nextPlayer();
  }
}

void work(){
  determined = false;
  player = 1;
  current = 0;
  while ( !determined ){
    play();
  }
  cout << player << endl;
}

void init(){
  fill ( boardState, boardState + 101, NOTHING );
  fill ( boardTarget, boardTarget + 101, 0 );
  fill ( missed, missed + 7, false );
  fill ( position, position + 7, 0 );
}

bool read(){
  cin >> nplayer;
  if ( nplayer == 0 ) return false;
  init();
  int i, j;
  while ( 1 ){
    cin >> i >> j;
    if ( i == 0 && j == 0 ) break;
    if ( i < j ){
      boardState[i] = LADDER;
      boardTarget[i] = j;
    } else if ( i > j ){
      boardState[i] = CHUTE;
      boardTarget[i] = j;
    } else {
//      assert( false );
    }
  }

  while ( 1 ){
    cin >> i;
    if ( i == 0 ) break;
    if ( i < 0 ) boardState[ -i ] = MISS;
    if ( i > 0 ) boardState[ i ] = TURN;
  }

  return true;
}

void readDie(){
  int i = 0;
  int k;
  while ( 1 ){
    cin >> k;
    if ( k == 0 ) return ;
    die[ i++ ] = k;
  }
}

main(){
  readDie();
  while ( read() ) {
    work();
  }
}

// @end_of_source_code


