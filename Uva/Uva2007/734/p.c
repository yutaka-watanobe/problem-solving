// @JUDGE_ID:  17051CA  734  C++
// @begin_of_source_code
/* Puzzle Backtracking */
/* 0.826 sec */
#include<stdio.h>
#include<iostream>
#include<stl.h>

char symbolTable[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

class Piece{
 public:
  char content[6];
  char symbol;
  Piece(){}
  Piece( char symbol ): symbol( symbol ){}
};

class TheProgrammersHex{
 public:
  Piece pieces[7][6];
  Piece frame[7];
  bool used[7];

  void createRotatedPieces(){
    for ( int p = 0; p < 7; p++ ){
      for ( int i = 1; i < 6; i++ ){
	pieces[p][i].symbol = pieces[p][i-1].symbol;
	pieces[p][i].content[5] = pieces[p][i-1].content[0];
	pieces[p][i].content[0] = pieces[p][i-1].content[1];
	pieces[p][i].content[1] = pieces[p][i-1].content[2];
	pieces[p][i].content[2] = pieces[p][i-1].content[3];
	pieces[p][i].content[3] = pieces[p][i-1].content[4];
	pieces[p][i].content[4] = pieces[p][i-1].content[5];
      }
    }
  }

  bool recursive( int pos ){
    if ( pos == 7 ) return true;

    Piece piece;

    if ( pos == 0 ){
      for ( int p = 0; p < 7; p++ ){
	used[p] = true;
	for ( int r = 0; r < 6; r++ ){
	  frame[pos] = pieces[p][r];
	  if ( recursive( 1 ) ) return true;
	}
	used[p] = false;
      }
    } else if ( pos == 1 ){
      for ( int p = 0; p < 7; p++ ){
	if ( used[p] ) continue;
	used[p] = true;
	for ( int r = 0; r < 6; r++ ){
	  piece = pieces[p][r];
	  if ( frame[0].content[0] == piece.content[3] ){
	    frame[1] = piece;
	    if ( recursive( 2 ) ) return true;
	  }
	}
	used[p] = false;
      }
    } else if ( pos == 2 ){
      for ( int p = 0; p < 7; p++ ){
	if ( used[p] ) continue;
	used[p] = true;
	for ( int r = 0; r < 6; r++ ){
	  piece = pieces[p][r];
	  if ( frame[0].content[1] == piece.content[4] &&
	       frame[1].content[2] == piece.content[5] ){
	    frame[2] = piece;
	    if ( recursive( 3 ) ) return true;
	  }
	}
	used[p] = false;
      }
    } else if ( pos == 3 ){
      for ( int p = 0; p < 7; p++ ){
	if ( used[p] ) continue;
	used[p] = true;
	for ( int r = 0; r < 6; r++ ){
	  piece = pieces[p][r];
	  if ( frame[0].content[2] == piece.content[5] &&
	       frame[2].content[3] == piece.content[0] ){
	    frame[3] = piece;
	    if ( recursive( 4 ) ) return true;
	  }
	}
	used[p] = false;
      }
    } else if ( pos == 4 ){
      for ( int p = 0; p < 7; p++ ){
	if ( used[p] ) continue;
	used[p] = true;
	for ( int r = 0; r < 6; r++ ){
	  piece = pieces[p][r];
	  if ( frame[0].content[3] == piece.content[0] &&
	       frame[3].content[4] == piece.content[1] ){
	    frame[4] = piece;
	    if ( recursive( 5 ) ) return true;
	  }
	}
	used[p] = false;
      }
    } else if ( pos == 5 ){
      for ( int p = 0; p < 7; p++ ){
	if ( used[p] ) continue;
	used[p] = true;
	for ( int r = 0; r < 6; r++ ){
	  piece = pieces[p][r];
	  if ( frame[0].content[4] == piece.content[1] &&
	       frame[4].content[5] == piece.content[2] ){
	    frame[5] = piece;
	    if ( recursive( 6 ) ) return true;
	  }
	}
	used[p] = false;
      }
    } else if ( pos == 6 ){
      for ( int p = 0; p < 7; p++ ){
	if ( used[p] ) continue;
	used[p] = true;
	for ( int r = 0; r < 6; r++ ){
	  piece = pieces[p][r];
	  if ( frame[0].content[5] == piece.content[2] &&
	       frame[5].content[0] == piece.content[3] &&
	       frame[1].content[4] == piece.content[1] ){
	    frame[6] = piece;
	    if ( recursive( 7 ) ) return true;
	  }
	}
	used[p] = false;
      }
    }

    return false;
  }

  void init(){
    for ( int i = 0; i < 7; i++ ) used[i] = false;
  }

  void printResult(){
    printf("PEG   HEX   POSITION\n" );
    printf("---   ---   --------\n" );
    for ( int i = 0; i < 7; i++ ){
      printf(" %d    ", i );
      printf(" %c     ", frame[i].symbol );
      for ( int j = 0; j < 6; j++ ) printf("%c", frame[i].content[j] );
      printf("\n");
    }
  }

  void work(){
    init();

    if ( recursive( 0 ) ){
      printResult();
    } else {
      printf("No solution possible\n");
    }

    printf("************************************\n");
  }

  bool read(){
    char ch;
    
    for ( int i = 0; i < 7; i++ ){
      Piece p = Piece( symbolTable[ i ] ) ;
      for ( int j = 0; j < 6; j++ ){
	if ( !( cin >> ch ) ) return false;
	p.content[j] = ch;
      }
      pieces[i][0] = p;
    }
    
    createRotatedPieces();

    cin >> ch;
    assert( ch == '*' );
    return true;
  }

};

main(){
  TheProgrammersHex TPH;
  while ( TPH.read() ){
    TPH.work();
  }
}
 
// @end_of_source_code


