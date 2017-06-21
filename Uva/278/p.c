// @JUDGE_ID:  17051CA  278  C++
// @begin_of_source_code
/* Calculation */
#include<stdio.h>
#include<iostream>
#include<stl.h>

char Piece;
int row, col;

int rook(){
  return min( row, col );
}

int queen(){
  return min( row, col );
}

int knight(){
  int area = row * col;
  if ( area % 2 == 0 ) return area/2;
  else return area/2 + 1;
}

int king(){
  return ( (row+1)/2 ) * ( (col+1)/2 ) ;
}

void work(){
  int possible;
  switch( Piece ){
  case 'r':
    possible = rook(); break;
  case 'k':
    possible = knight(); break;
  case 'Q':
    possible = queen(); break;
  case 'K':
    possible = king(); break;
  }

  cout << possible << endl;
}

main(){
  int t;
  cin >> t;
  for ( int i = 0; i < t; i++ ){
    cin >> Piece >> row >> col;
    work();
  }
}
// @end_of_source_code
