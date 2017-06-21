// @JUDGE_ID:  17051CA  387  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stl.h>
#include<string>

typedef vector<vector<char> > Frame;

class Piece{
 public:
  int row, column;
  char content[4][4];

  Piece(){}
  Piece( int row, int column ): row(row), column(column){}
};

int npiece;
int npixel;
Piece pieceList[6];
bool used[6];

Frame currentFrame;

void printResult(){
  for ( int i = 0; i < 4; i++ ){
    for ( int j = 0; j < 4; j++ ){
      printf("%c", currentFrame[i][j] );
    }
    printf("\n");
  }
}

bool tryAdd( Piece p ){

  Frame candidateFrame = currentFrame;
  int px, py;
  int row = p.row;
  int column = p.column;

  for ( int i = 0; i < 4; i++ ){
    for ( int j = 0; j < 4; j++ ){

      for ( int x = 0; x < row; x++ ){
	for ( int y = 0; y < column; y++ ){
	  px = i + x;
	  py = j + y;
	  if ( !( 0 <= px && 0 <= py && px < 4 && py < 4 ) ) goto next;
	  if ( p.content[x][y] != ' ' && candidateFrame[px][py] != ' ' ) goto next;
	  if ( p.content[x][y] != ' ' && candidateFrame[px][py] == ' ' ){
	    candidateFrame[px][py] = p.content[x][y];
	  }
	}
      }

      currentFrame = candidateFrame;
      return true;
    next:;
      candidateFrame = currentFrame;
    }
  }
  return false;
}


bool rec( int index ){

  if ( index == npiece ) {
    for ( int i = 0; i < 4; i++ ){
      for ( int j = 0; j < 4; j++ ) {
	if ( currentFrame[i][j] == ' ' ) return false;
      }
    }
    return true;
  }

  Frame tempFrame = currentFrame;

  for ( int i = 0; i < npiece; i++ ){
    if ( used[i]  ) continue;

    if ( tryAdd( pieceList[ i ] ) ){
      used[i] = 1;
      if ( rec( index + 1 ) ) return true;
      used[i] = 0;
      currentFrame = tempFrame;
    }
  }

  return false;
}

void work(){
  bool able;
  if ( npixel != 16 ){
    able = false;
  } else {
    able = rec( 0 );
  }

  if ( !able ){
    cout << "No solution possible" << endl;
  } else {
    printResult();
  }
}

void init(){
  npixel = 0;
  currentFrame.clear();
  currentFrame.resize( 4 );
  for ( int i = 0; i < 4; i++ ) currentFrame[i].resize( 4, ' ' );

  fill ( used, used + 6 , false );
}

bool read(){
  cin >> npiece;
  if ( npiece == 0 ) return false;
  assert( npiece <= 5 );

  init();

  int row, column;
  char ch;

  for ( int i = 1; i <= npiece; i++ ){
    scanf( "%d %d", &row, &column );
    Piece piece = Piece( row, column );

    for ( int x = 0; x < row; x++ ){
      for ( int y = 0; y < column; y++ ){
	cin >> ch;
	if ( ch == '0' ) piece.content[x][y] = ' ';
	else { piece.content[x][y] = i + '0'; npixel++; }
      }
    }
    pieceList[i-1] = piece;
  }

  return true;
}

main(){
  for ( int i = 0; read(); i++ ){
    if ( i ) printf("\n");
    work();
  }
}
// @end_of_source_code


