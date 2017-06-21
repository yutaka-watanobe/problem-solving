// @JUDGE_ID:  17051CA  584  C++
// @begin_of_source_code
/* Simulation - Bowling */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

class Bowling{
 public:
  char play[30];
  int nplay;
  int score[10];
  int bpoint[10];
  int bonus[10];

  void addBonus( int v ){
    for ( int i = 0; i < 10; i++ ){
      if ( bonus[i] ){
	bpoint[i] += v;
	bonus[i]--;
      }
    }
  }

  void work(){
    fill ( score, score + 10, 0 );
    fill ( bpoint, bpoint + 10, 0 );
    fill ( bonus, bonus + 10, 0 );
    
    char first, second;

    int pos = 0;

    for ( int game = 0; game < 10; game++ ){
      first = play[ pos++ ];

      if ( first == 'X' ){
	score[ game ] += 10;
	addBonus( 10 );
	bonus[game] = 2;
	continue;
      } else if ( isdigit( first ) ){
	score[ game ] += ( first - '0' );
	addBonus( first - '0' );
      } else {
	assert( false );
      } 

      second = play[ pos++ ];

      if ( second == '/' ){
	int s = 10 - score[ game ];
	score[ game ] += s;
	addBonus( s );
	bonus[ game ] = 1;
      } else if ( isdigit( second ) ){
	score[ game ] += ( second - '0' );
	addBonus( second - '0');
      } else {
	assert( false );
      }
    }

    /* last 2 */
    for ( int i = pos; i < nplay; i++ ){
      char ch = play[i];
      if ( ch == 'X' ) addBonus( 10 );
      else if ( isdigit( ch ) ){
	addBonus( ch - '0' );
      } else if ( ch == '/' ){
	bpoint[9] = 10;
      }

    }

    int sum = 0;

    for ( int i = 0; i < 10; i++ ){
      sum += score[i];
      sum += bpoint[i];
    }

    printf("%d\n", sum );
  }

  bool read(){
    char ch;

    nplay = 0;

    while ( 1 ){
      scanf("%c", &ch );
      if ( ch == 'G' ) return false;
      if ( ch == '\n' ) return true;
      if ( ch == ' ' ) continue;
      play[nplay++] = ch;
    }
  }

};

main(){
  Bowling B;
  while ( B.read() ){
    B.work();
  }
}

// @end_of_source_code


