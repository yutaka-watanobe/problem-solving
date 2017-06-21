// @JUDGE_ID:  17051CA  339  C++
// @begin_of_source_code
/* Grid Simulation --> ¤×¤è¤×¤è */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
#define VISITED -1

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

class SameGame{
 public:
  int row, column;
  vector<vector<int> > board;

  bool removable( int x, int y ){
    if (!( 0 <= x && 0 <= y && x < board.size() && y < board[x].size() ) ) return false;

    int number = board[x][y];

    int nx, ny;
    
    for ( int r = 0; r < 4; r++ ){
      nx = x + dx[r];
      ny = y + dy[r];
      if ( 0 <= nx && 0 <= ny && nx < board.size() && ny < board[nx].size() )
	if ( board[nx][ny] == number ) return true;
    }

    return false;

  }

  void dfs( int x, int y, int number){
    board[x][y] = VISITED;

    int nx, ny;
    for ( int r = 0; r < 4; r++ ){
      nx = x + dx[r];
      ny = y + dy[r];
      if ( 0 <= nx && 0 <= ny && nx < board.size() && ny < board[nx].size() ){
	if ( board[nx][ny] == number ) dfs( nx, ny, number );
      }
    }

  }
  
  void removeEmpty(){
    for ( int i = 0; i < board.size(); i++ ){
      for ( int j = 0; j < board[i].size(); j++ ){
	if ( board[i][j] == VISITED ){
	  board[i].erase( board[i].begin() + j );
	  j--;
	}
      }
    }

    for ( int i = 0; i < board.size(); i++ ){
      if ( board[i].size() == 0 ){
	board.erase( board.begin() + i );
	i--;
      }
    }
  }

  void select( int x, int y ){
    if ( !removable( x, y ) ) return ;
    dfs( x, y, board[x][y] );
    removeEmpty();
  }
 
  void printBoard(){
    vector<vector<char> > outBoard;
    outBoard.resize( row );
    for ( int i = 0; i < row; i++ ) outBoard[i].resize( column, ' ' );

    for ( int i = 0; i < board.size(); i++ ){
      for ( int j = 0; j < board[i].size(); j++ ){
	outBoard[j][i] = board[i][j] + '0';
      }
    }

    for ( int i = row - 1; i >= 0; i-- ){
      cout << "   ";
      for ( int j = 0; j < column; j++ ){
	cout << " " << outBoard[i][j];
      }
      cout << endl;
    }
  }

  void work(){
    int x, y;

    while ( 1 ){
      cin >> y >> x;
      if ( x == 0 && y == 0 ) break;
      select( x - 1, y - 1 ); /* zero base */
    }

    if ( board.size() == 0 ){
      cout << "    Game Won" << endl;
    } else {
      printBoard();
    }
  }

  bool read(){

    cin >> row >> column;
    if ( row == 0 || column == 0 ) return false;

    board.clear();
    board.resize( column );
    for ( int i = 0; i < column; i++ ) board[i].resize( row );

    for ( int i = 0; i < row; i++ ){
      for ( int j = 0; j < column; j++ ){
	cin >> board[j][i];
      }
    }

    return true;
  }
};

main(){
  SameGame game;
  for ( int i = 1; game.read(); i++ ){
    cout << "Grid " << i << "." << endl;
    game.work();
    cout << endl;
  }
}

// @end_of_source_code


