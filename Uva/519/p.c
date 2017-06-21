// @JUDGE_ID:  17051CA  519  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<stl.h>
#define MAX 36
#define TYPE_CORNER 0
#define TYPE_LONG 1
#define TYPE_SHORT 2
#define TYPE_IN 3
#define TYPE_LONG_TERMINAL 4
#define TYPE_LONG_LINE 5
#define TYPE_SHORT_TERMINAL 6
#define TYPE_SHORT_LINE 7
#define TYPE_BLOCK 8
#define HORIZONTAL 0
#define VERTICAL 1

class Piece{
 public:
  int type;
  char top, right, bottom, left;

  Piece(){}
  Piece( char top, char right, char bottom, char left):
    top(top), right(right), bottom(bottom), left(left){
    setType();
  }
  
  void setType(){
    if ( left == 'F' && top != 'F' && right != 'F' && bottom != 'F' ||
	 right == 'F' && top != 'F' && left != 'F' && bottom != 'F' ) {
      type = TYPE_LONG;
    } else if ( top == 'F' && right != 'F' && bottom != 'F' && left != 'F' ||
		top != 'F' && right != 'F' && bottom == 'F' && left != 'F' ){
      type = TYPE_SHORT;
    } else if ( top == 'F' && right == 'F' && bottom != 'F' && left != 'F' ||
		top != 'F' && right == 'F' && bottom == 'F' && left != 'F' ||
		top != 'F' && right != 'F' && bottom == 'F' && left == 'F' ||
		top == 'F' && right != 'F' && bottom != 'F' && left == 'F' ){
      type = TYPE_CORNER;
    } else if ( top != 'F' && right != 'F' && bottom != 'F' && left != 'F' ){
      type = TYPE_IN;
    } else if ( top != 'F' && right == 'F' && bottom == 'F' && left == 'F' ||
		top == 'F' && right == 'F' && bottom != 'F' && left == 'F' ){
      type = TYPE_LONG_TERMINAL;
    } else if ( top != 'F' && right == 'F' && bottom != 'F' && left == 'F' ){
      type = TYPE_LONG_LINE;
    } else if ( top == 'F' && right == 'F' && bottom == 'F' && left != 'F' ||
		top == 'F' && right != 'F' && bottom == 'F' && left == 'F' ){
      type = TYPE_SHORT_TERMINAL;
    } else if ( top == 'F' && right != 'F' && bottom == 'F' && left != 'F' ){
      type = TYPE_SHORT_LINE;
    } else if ( top == 'F' && right == 'F' && bottom == 'F' && left == 'F' ){
      type = TYPE_BLOCK;
    } else{
      cout << top << right<< bottom << left << endl;
      assert( false );
    }
  }

  void rotate(){
    char tmp = top;
    top = left;
    left = bottom;
    bottom = right;
    right = tmp;
  }

  void rotate2(){
    rotate(); rotate();
  }

};

bool check( char ch1, char ch2 ){
  if ( ch1 == 'O' && ch2 == 'I' || ch1 == 'I' && ch2 == 'O' ) return true;
  return false;
}

int row, column;
int nLong, nShort, nCorner, nIn;
int nLongTerminal, nLongLine, nShortLine, nShortTerminal, nBlock;

Piece longP[ MAX ][ 2 ], shortP[ MAX ][ 2 ], cornerP[ MAX ][ 2 ], inP[ MAX ][ 2 ];
bool longU[ MAX ], shortU[ MAX ], cornerU[ MAX ], inU[ MAX ];
Piece longTerminalP[ MAX ][ 2 ], longLineP[ MAX ][ 2 ], shortTerminalP[ MAX ][ 2 ], shortLineP[ MAX ][ 2 ];
bool longTerminalU[ MAX ], longLineU[ MAX ], shortTerminalU[ MAX ], shortLineU[ MAX ];
Piece blockP[ MAX ];
bool blockU[ MAX ];

vector<vector<Piece> > Frame;

void initialize( int direction ){
  if ( direction == HORIZONTAL ){
    for ( int i = 0; i < nLong; i++ ) longP[ i ][ 0 ].rotate();
    for ( int i = 0; i < nShort; i++ ) shortP[ i ][ 0 ].rotate();
    for ( int i = 0; i < nCorner; i++ ) cornerP[ i ][ 0 ].rotate();
    for ( int i = 0; i < nIn; i++ ) inP[ i ][ 0 ].rotate();
    for ( int i = 0; i < nLongTerminal; i++ ) longTerminalP[ i ][ 0 ].rotate();
    for ( int i = 0; i < nLongLine; i++ ) longLine[ i ][ 0 ].rotate();
    for ( int i = 0; i < nShortTerminal; i++ ) shortTerminalP[ i ][ 0 ].rotate();
    for ( int i = 0; i < nShortLine; i++ ) shortLine[ i ][ 0 ].rotate();
    for ( int i = 0; i < nBlock; i++ ) blockP[ i ][ 0 ].rotate();
  }
  for ( int i = 0; i < nLong; i++ ) { lognP[ i ][ 1 ] = longP[ i ][ 0 ]; longP[ i ][ 1 ].rotate2(); }
  for ( int i = 0; i < nShort; i++ ) { shortP[ i ][ 1 ] = shortP[ i ][ 0 ]; shortP[ i ][ 1 ].rotate2(); }
  for ( int i = 0; i < nCorner; i++ ) { cornerP[ i ][ 1 ] = cornerP[ i ][ 0 ]; cornerP[ i ][ 1 ].rotate2(); }
  for ( int i = 0; i < nIn; i++ ) { inP[ i ][ 1 ] = inP[ i ][ 0 ]; inP[ i ][ 1 ].rotate2(); }
  for ( int i = 0; i < nLongTerminal; i++ ) { longTerminalP[ i ][ 1 ] = longTerminalP[ i ][ 0 ]; longTerminal[ i ][ 1 ].rotate2(); }
  for ( int i = 0; i < nLongLine; i++ ) { longLineP[ i ][ 1 ] = longLineP[ i ][ 0 ]; longLineP[ i ][ 1 ].rotate2(); }
  for ( int i = 0; i < nShortTerminal; i++ ) { shortTerminalP[ i ][ 1 ] = shortTerminal[ i ][ 0 ]; shortTerminal[ i ][ 1 ].rotate2(); }
  for ( int i = 0; i < nShortLine; i++ ) { shortLineP[ i ][ 1 ] = shortLineP[ i ][ 0 ]; shortLineP[ i ][ 1 ].rotate2(); }

  fill ( longU, longU + nLong, false );
  fill ( shortU, shortU + nShort, flase );
  fill ( cornerU, cornerU + nCorner, false );
  fill ( inU, inU + nIn, false );
  fill ( longTerminalU, longTerminalU + nLongTerminal, false );
  fill ( longLineU, longLineU + nLongLine, false );
  fill ( shortTerminalU, shortTerminalU + nShortTerminal, false );
  fill ( shortLineU, shortLineU + nShortLine, false );
  fill ( blockU, blockU + nBlock, false );
}


bool recLinePuzzleH( int pos ){
  
  if ( pos == 0 ){
    if ( longTerminalP[0][0].left == 'F' ){
      Frame[0][0] = longTerminalP[0][0];
      recLinePuzzleH( pos + 1 );
    } else if ( longTerminalP[0][1].left == 'F' ){
      Frame[0][0] = longTerminalP[0][1];
      recLinePuzzleH( pos + 1 );
    }
  } else if ( pos == column -1 ){
    if ( check( longTerminalP[1][0].left, Frame[0][pos-1].right ) ||
	 check( longTerminalP[1][1].left, Frame[0][pos-1].right ) ){
      return true;
    }
  } else {
    for ( int p = 0; p < nLongLine; p++ ){
      if ( longLineU[ p ] ) continue;
      
      if ( check( Frame[0][pos-1].right, longLineP[ p ][0].left ) ) {
	longLineU[ p ] = true;
	Frame[0][pos] = longLineP[ p ][0];
	if ( recLinePuzzleH( pos + 1 ) ) return true;
	longLineU[ p ] = false;
      }
      if ( check( Frame[0][pos-1].right, longLineP[ p ][1].left ) ){
	longLineU[ p ] = true;
	Frame[0][pos] = longLineP[ p ][1];
	if ( recLinePuzzleH( pos + 1 ) ) return true;
	longLineU[ p ] = false;
      }
    }
   
  }
  return false;
}


bool recLinePuzzleV( int pos ){

}

bool checkLinePuzzle( int direction ){
  initialize( direction );

  Frame.clear();
  Frame.resize( 1 );
  Frame[0].resize( col );

  if ( dierction == HORIZONTAL ) return recLinePuzzleH( 0 );
  if ( dierction == VERTICAL ) return recLinePuzzleV( 0 );
}

bool checkPuzzle( int direction ){
  initialize( direction );
  return false;
}



bool validate(){
  if ( row == 1 && column == 1 ){
    return ( nBlock == 1 );
  } else if ( row == 1 && column > 1 ){
    if ( nLongTerminal == 2 && nLongLine == column - 2 ){
      return checkLinePuzzle( HORIZONTAL );
    } else if ( nShortTerminal == 2 && nShortLine == column - 2 ){
      return checkLinePuzzle( VERTICAL );
    }
    return false;
  } else if ( row == column ){
    if ( nCorner == 4 && nLong == nShort && nLong == ( column - 2 ) * 2 ){
      return checkPuzzle( HORIZONTAL );
    }
    return false;
  } else if ( row > 1 && column > 1 ){
    if ( nCorner == 4 && nLong == ( column - 2 ) * 2 && nShort == ( row - 2 ) * 2 ){
      return checkPuzzle( HORIZONTAL );
    }
    if ( nCorner == 4 && nShort == ( column - 2 ) * 2 && nLong == ( row - 2 ) * 2 ){
      return checkPuzzle( VERTICAL );
    }
    return false;
  } else {
    assert ( false );
  }
}

void work(){
  bool able = validate();
  if ( able ) cout << "YES" << endl;
  else cout << "NO" << endl;
}

void init(){
  nLong = nShort = nCorner = nIn = 0;
  nLongTerminal = nLongLine = nShortLine = nShortTerminal = nBlock = 0;
}

bool read(){
  int R, C;
  cin >> R >> C;
  if ( R == 0 && C == 0 ) return false;
  row = min( R, C );
  column = max( R, C );

  init();

  Piece piece;
  char t, r, b, l;
  for ( int i = 0; i < row * column; i++ ){
    cin >> t >> r >> b >> l;
    piece = Piece( t, r, b, l );
    int type = piece.type;

    if ( type == TYPE_LONG ) longP[ nLong++ ] = piece;
    else if ( type == TYPE_SHORT ) shortP[ nShort++ ] = piece;
    else if ( type == TYPE_CORNER ) cornerP[ nCorner++ ]  = piece;
    else if ( type == TYPE_IN ) inP[ nIn++ ] = piece;
    else if ( type == TYPE_LONG_TERMINAL ) longTerminalP[ nLongTerminal++ ] = piece;
    else if ( type == TYPE_LONG_LINE ) longLineP[ nLongLine++ ] = piece;
    else if ( type == TYPE_SHORT_TERMINAL ) shortTerminalP[ nShortTerminal++ ] = piece;
    else if ( type == TYPE_SHORT_LINE ) shortLineP[ nShortLine++ ] = piece;
    else if ( type == TYPE_BLOCK ) blockP [ nBlock++ ] = piece;
  }

  return true;
}

main(){
  while ( read() ){
    work();
  }
}
// @end_of_source_code


