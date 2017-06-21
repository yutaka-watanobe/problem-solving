// @JUDGE_ID:  17051CA  2561  C++
// @begin_of_source_code
/* Puzzle - Lights Out */
#include<stdio.h>
#include<iostream>

class ExtendedLightsOut{
 public:
  char M[30];
  char P[30];

  bool check(){
    for ( int i = 0; i < 30; i++ ) if ( M[i] == '1' ) return false;
    return true;
  }

  void flipM( int pos ){
    M[pos] = ( M[pos] == '0' ) ? '1' : '0';
  }

  void flipP( int pos ){
    P[pos] = ( P[pos] == '0' ) ? '1' : '0';
  }

  void press( int pos ){
    int x, y, nx, ny;
    x = pos / 6;
    y = pos % 6;

    flipM( pos );
    flipP( pos );

    nx = x + 1;
    ny = y;
    if ( 0 <= nx && 0 <= ny && nx < 5 && ny < 6 ) flipM( nx*6 + ny );

    nx = x;
    ny = y + 1;
    if ( 0 <= nx && 0 <= ny && nx < 5 && ny < 6 ) flipM( nx*6 + ny );

    nx = x - 1;
    ny = y;
    if ( 0 <= nx && 0 <= ny && nx < 5 && ny < 6 ) flipM( nx*6 + ny );

    nx = x;
    ny = y - 1;
    if ( 0 <= nx && 0 <= ny && nx < 5 && ny < 6 ) flipM( nx*6 + ny );

  }

  bool recursive( int pos ){

    if ( pos == 30 ){
      return check();
    }

    if ( pos < 6 ){
      press( pos );   
      if ( recursive( pos + 1 ) ) return true;
      press( pos );
      if ( recursive( pos + 1 ) ) return true;

    } else {
      int p = pos - 12;
      if ( p > 0 && M[p] == '1' ) return false;
      int v = pos - 6;
      if ( M[v] == '1' ) {
	press( pos );
	if ( recursive( pos + 1 ) ) return true;
	press( pos );
      } else {
	if ( recursive( pos + 1 ) ) return true;
      }
    }
    return false;
  }

  void work(){
    for ( int i = 0; i < 30; i++ ){
	P[i] = '0';
    }

    if ( recursive( 0 ) ){
      for ( int i = 0; i < 30; i++ ){
	printf("%c ", P[i] );
	if ( (i+1)%6 == 0 ) printf("\n");
      }
    } else {
      printf("error\n");
    }
  }

  void read(){
    for ( int i = 0; i < 30; i++ ){
      cin >> M[i];
    }
  }
};

main(){
  ExtendedLightsOut ELO;
  int tcase;
  cin >> tcase;
  for ( int i = 1; i <= tcase; i++ ){
    printf("PUZZLE #%d\n", i );
    ELO.read();
    ELO.work();
  }
}

// @end_of_source_code


