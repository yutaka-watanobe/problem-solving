// @JUDGE_ID:  17051CA  379  C++
// @begin_of_source_code
/* Grid Game Simulation */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#define WALL -1
#define HOLE 0
#define PEG 1
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int G[7][7]; /* grid */
int M[7][7]; /* value map */

bool notBoard( int i, int j ){
  if ( i == 0 || i == 1 || i == 5 || i == 6 ){
    if ( j == 0 || j == 1 || j == 5 || j == 6 ) return true;
  }
  if ( ! ( 0 <= i && 0 <= j && i < 7 && j < 7 ) ) return true;
  return false;
}

int getTarget( pair<int, int> &target_point ){
  int target = -1;

  for ( int i = 0; i < 7; i++ ){
    for ( int j = 0; j < 7; j++ ){
      if ( notBoard( i, j ) || G[i][j] != HOLE ) continue;
      int x1, y1, x2, y2;
      for ( int r = 0; r < 4; r++ ){
	x1 = i + dx[r];
	y1 = j + dy[r];
	x2 = i + dx[r]*2;
	y2 = j + dy[r]*2;
	if ( ! (notBoard( x1, y1 ) || notBoard( x2, y2 ) ) ){
	  if ( G[x1][y1] == PEG && G[x2][y2] == PEG ){
	    if ( M[i][j] > target ) {
	      target = M[i][j];
	      target_point = make_pair( i, j );
	    }
	  }
	}
      }
    }
  }

  return target;
}

void movePeg( pair<int, int> target_point ){
  int source = -1;
  pair<int, int> source_point;
  pair<int, int> remove_point;

  int tx = target_point.first;
  int ty = target_point.second;
  
  int x1, y1, x2, y2;
  for ( int r = 0; r < 4; r++ ){
    x1 = tx + dx[r];
    y1 = ty + dy[r];
    x2 = tx + dx[r] * 2;
    y2 = ty + dy[r] * 2;
    if ( !( notBoard( x1, y1 ) || notBoard( x2, y2 ) ) ){
      if ( G[x1][y1] == PEG && G[x2][y2] == PEG ){
	if ( M[x2][y2] > source ){
	  source = M[x2][y2];
	  source_point = make_pair( x2, y2 );
	  remove_point = make_pair( x1, y1 );
	}
      }
    }
  }
  assert ( source != -1 );

  G[ source_point.first ][ source_point.second ] = HOLE;
  G[ remove_point.first ][ remove_point.second ] = HOLE;
  G[ target_point.first ][ target_point.second ] = PEG;
}

void work(){
  
  int target;
  pair<int, int> target_point;
  while ( 1 ){
    target = getTarget( target_point );
    if ( target == -1 ) break;
    movePeg( target_point );
  }

  int sum = 0;
  for ( int i = 0; i < 7; i++ ){
    for ( int j = 0; j < 7; j++ ){
      if ( G[i][j] == PEG ) sum += M[i][j];
    }
  }

  cout << sum << endl;
}

int read(){
  vector<int> In( 34, 0 );

  int v;
  while ( 1 ){
    cin >> v;
    if ( v == 0 ) break;
    In[ v ] = 1;
  }

  for ( int i = 0; i < 7; i++ ){
    for ( int j = 0; j < 7; j++ ){
      G[i][j] = WALL;
    }
  }
  
  int currsor = 1;
  for ( int i = 0; i < 7; i++ ){
    for ( int j = 0; j < 7; j++ ){
      if ( notBoard( i, j ) ) continue;
      if ( In[ currsor ] ) G[i][j] = PEG;
      else G[i][j] = HOLE;
      currsor++;
    }
  }
}

void createValueMap(){
  int curssor = 1;
  for ( int i = 0; i < 7; i++ ){
    for ( int j = 0; j < 7; j++ ){
      if ( notBoard( i, j ) ) M[i][j] = 0;
      else {
	M[i][j] = curssor;
	curssor++;
      }
    }
  }
}

main(){
  int tcase;
  cin >> tcase;
  createValueMap();
  cout << "HI Q OUTPUT" << endl;
  for ( int i = 0; i < tcase; i++ ){
    read();
    work();
  }
  cout << "END OF OUTPUT" << endl;
  
}
// @end_of_source_code
