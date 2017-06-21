// @JUDGE_ID:  17051CA  657  C++
// @begin_of_source_code
/* DFS + DFS */
/* 50 * 50 = 2500 */
/* be careful for stack overflow */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
typedef vector<vector<char> > Grid;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int row, column;
Grid G;
vector<vector<int> > U;

Grid current;

void dfs( Grid &grid, int i, int j, char target1, char target2 ){
  current[i][j] = grid[i][j];
  int nx, ny;
  for ( int r = 0; r < 4; r++ ){
    nx = i + dx[r];
    ny = j + dy[r];
    if ( 0 <= nx && 0 <= ny && nx < row && ny < column ){
      if ( !U[nx][ny] && ( grid[nx][ny] == target1 || grid[nx][ny] == target2 )  ){
	U[nx][ny] = 1;
	dfs( grid, nx, ny, target1, target2 );
      }
    }
  }
}

void resize( Grid &grid ){
  grid.resize( row , vector<char>( column, '.' ) );
}

int searchDot( Grid grid ){
  U.clear();
  U.resize( row, vector<int>(column, 0 )  );

  int count = 0;

  for ( int i = 0; i < row; i++ ){
    for ( int j = 0; j < column; j++ ){
      if ( grid[i][j] == 'X' && !U[i][j] ){
	U[i][j] = 1;
	dfs( grid, i, j, 'X', 'X' );
	count++;
      }
    }
  }

  assert( 1 <= count && count <= 6 );

  return count;
}

void work(){

  U.clear();
  U.resize( row, vector<int>(column, 0 )  );
  
  vector<Grid > diceList;

  for ( int i = 0; i < row; i++ ){
    for ( int j = 0; j < column; j++ ){
      if ( G[i][j] != '.' && !U[i][j] ){
	current.clear();
	resize( current );
	U[i][j] = 1;
	dfs( G, i, j, '*', 'X' );
	diceList.push_back( current );
      }
    }
  }

  vector<int> dotList;

  for ( int k = 0; k < diceList.size(); k++ ){
    dotList.push_back( searchDot( diceList[k] ) );
  }

  sort( dotList.begin(), dotList.end() );

  for ( int i = 0;i < dotList.size(); i++ ){
    cout << dotList[i] << " ";
  }
  cout << endl;
}

int read(){
  G.clear();
  cin >> column >> row;
  if ( column == 0 && row == 0 ) return false;

  G.resize( row );
  for ( int i = 0; i < row; i++ ){
    G[i].resize( column );
    for ( int j = 0; j < column; j++ ){
      cin >> G[i][j];
    }
  }

  return true;
}

main(){
  for ( int i = 1; read(); i++ ){
    cout << "Throw " << i << endl;
    work();
    cout << endl;
  }
}
// @end_of_source_code
