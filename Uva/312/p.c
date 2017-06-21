// @JUDGE_ID:  17051CA  312  C++
// @begin_of_source_code
/* Grid */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#define MAX 27
#define NOTHING 0
#define SPACE 1
#define BLOCK 2
#define NUMBERED 3
#define WHITE '0'
#define BLACK '1'
#define EDGE '2'

class Cell{
 public:
  int state;
  int number;

  Cell(){}
  Cell( int state, int number ): state( state ), number(number){}

};

int row, column;
char M[ MAX + 2 ][ MAX + 2 ];
Cell C[ MAX + 2 ][ MAX + 2 ];
char G[ MAX * 3 + 1 ][ MAX * 5 + 1 ];
int rightMost[ MAX * 3 + 1 ];

void createCell(){
  int number = 1;

  for ( int i = 1; i <= row; i++ ){
    for ( int j = 1; j <= column; j++ ){
      if ( M[i][j] == WHITE ){
	if ( M[i+1][j] == WHITE && M[i-1][j] != WHITE ||
	     M[i][j-1] != WHITE && M[i][j+1] == WHITE ){
	  C[i][j] = Cell( NUMBERED, number++ );
	} else {
	  C[i][j] = Cell( SPACE, -1 );
	}
      } else if ( M[i][j] == BLACK ){
	C[i][j] = Cell( BLOCK, -1 );
      } else if ( M[i][j] == EDGE ){
	C[i][j] = Cell( NOTHING, -1 );
      } else{
	assert ( false );
      }
    }
  }
}

void printResult(){

  for ( int i = 0; i < row*3 + 1; i++ ){
    rightMost[ i ] = 0;
    for ( int j = column*5; j >= 0; j-- ){
      if ( G[i][j] != ' ' ){
	rightMost[ i ] = j + 1;
	goto next;
      }
    }
  next:;
  }


  for ( int i = 0; i < row*3 + 1; i++ ){
    for ( int j = 0; j < rightMost[i]; j++ ){
      cout << G[i][j];
    }
    cout << endl;
  }
}

string getStringNumber( int x ){
  char a[20];
  sprintf(a, "%d", x);
  string str = string(a);
  while ( str.size() < 3 ) str = '0' + str;
  return str;
}

void drawFrame( int x, int y ){
  for ( int i = x; i < x + 4; i++ ){
    G[i][y] = '+';
    G[i][y+5] = '+';
  }
  for ( int j = y; j < y + 6; j++ ){
    G[x][j] = '+';
    G[x+3][j] = '+';
  }
}

void createGrid(){
  for ( int i = 0; i < row*3+1; i++ ){
    for ( int j = 0; j < column*5+1; j++ ) G[i][j] = ' ';
  }

  int pi, pj;
  for ( int i = 1; i <= row; i++ ){
    for ( int j = 1; j <= column; j++ ){
      pi = (i-1)*3; pj = (j-1)*5;
      if ( C[i][j].state == BLOCK ){
	drawFrame( pi, pj );
	G[pi+1][pj+1] = G[pi+1][pj+2] = G[pi+1][pj+3] = G[pi+1][pj+4] = '+';
	G[pi+2][pj+1] = G[pi+2][pj+2] = G[pi+2][pj+3] = G[pi+2][pj+4] = '+';
      } else if ( C[i][j].state == SPACE ){
	drawFrame( pi, pj );
      } else if ( C[i][j].state == NUMBERED ){
	drawFrame( pi, pj );
	string ns = getStringNumber( C[i][j].number );
	G[pi+1][pj+1] = ns[0];
	G[pi+1][pj+2] = ns[1];
	G[pi+1][pj+3] = ns[2];
      }
    }
  }



}

void dfs( int i, int j ){

  M[i][j] = EDGE;
  
  if ( M[i+1][j] == BLACK ) dfs( i+1, j );
  if ( M[i-1][j] == BLACK ) dfs( i-1, j );
  if ( M[i][j-1] == BLACK ) dfs( i, j-1 );
  if ( M[i][j+1] == BLACK ) dfs( i, j+1 );
}

void createEdge(){

  for ( int i = 1; i <= row; i++ ){
    if ( M[i][1] == BLACK ) dfs( i, 1 );
    if ( M[i][column] == BLACK ) dfs( i, column );
  }

  for ( int j = 1; j <= column; j++ ){
    if ( M[1][j] == BLACK ) dfs( 1, j );
    if ( M[row][j] == BLACK ) dfs( row, j );
  }

}

void work(){
  createEdge();
  createCell();
  createGrid();
  printResult();
}

bool read(){
  cin >> row >> column;
  if ( row == 0 && column == 0 ) return false;
  for ( int i = 0; i < row + 2; i++ ){
    for ( int j = 0; j < column + 2; j++ ){
      if ( i == 0 || j == 0 || i == row + 1 || j == column + 1 ){
	M[i][j] = ' ';
      } else {
	cin >> M[i][j];
      } 
    }
  }
  return true;
}

main(){
  while ( read() ){
    work();
    cout << endl;
  }
}

// @end_of_source_code


