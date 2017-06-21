// @JUDGE_ID:  17051CA  758  C++
// @begin_of_source_code
/* Simulation - ¤×¤è¤×¤è */
#include<stdio.h>
#include<iostream>
#include<vector>

class TheSameGame{
 public:
  vector<vector<char> > input;
  vector<vector<char> > currentGrid;
  int used[15][10];
  int counter;
  int current;
  int total;
  int n;

  TheSameGame(){
    input.resize( 15 );
    for ( int i = 0; i < 15; i++ ) input[i].resize( 10, ' ');
  }

  void dfs( int i, int j, char ball ){
    counter++;
    used[i][j] = current;

    int dx, dy;

    dx = i + 1;
    dy = j;
    if ( 0 <= dx && 0 <= dy && dx < currentGrid.size() && dy < currentGrid[dx].size() ){
      if ( used[dx][dy] != current && currentGrid[dx][dy] == ball  ) dfs( dx, dy, ball );
    }

    dx = i;
    dy = j + 1;
    if ( 0 <= dx && 0 <= dy && dx < currentGrid.size() && dy < currentGrid[dx].size() ){
      if ( used[dx][dy] != current && currentGrid[dx][dy] == ball  ) dfs( dx, dy, ball  );
    }

    dx = i - 1;
    dy = j;
    if ( 0 <= dx && 0 <= dy && dx < currentGrid.size() && dy < currentGrid[dx].size() ){
      if ( used[dx][dy] != current && currentGrid[dx][dy] == ball  ) dfs( dx, dy, ball  );
    }

    dx = i;
    dy = j - 1;
    if ( 0 <= dx && 0 <= dy && dx < currentGrid.size() && dy < currentGrid[dx].size() ){
      if ( used[dx][dy] != current && currentGrid[dx][dy] == ball  ) dfs( dx, dy, ball  );
    }

  }

  void fillDfs( int i, int j, char ball ){
    currentGrid[i][j] = ' ';

    int dx, dy;

    dx = i + 1;
    dy = j;
    if ( 0 <= dx && 0 <= dy && dx < currentGrid.size() && dy < currentGrid[dx].size() ){
      if ( currentGrid[dx][dy] == ball  ) fillDfs( dx, dy, ball );
    }

    dx = i;
    dy = j + 1;
    if ( 0 <= dx && 0 <= dy && dx < currentGrid.size() && dy < currentGrid[dx].size() ){
      if ( currentGrid[dx][dy] == ball  ) fillDfs( dx, dy, ball  );
    }

    dx = i - 1;
    dy = j;
    if ( 0 <= dx && 0 <= dy && dx < currentGrid.size() && dy < currentGrid[dx].size() ){
      if ( currentGrid[dx][dy] == ball  ) fillDfs( dx, dy, ball  );
    }

    dx = i;
    dy = j - 1;
    if ( 0 <= dx && 0 <= dy && dx < currentGrid.size() && dy < currentGrid[dx].size() ){
      if ( currentGrid[dx][dy] == ball  ) fillDfs( dx, dy, ball  );
    }

  }

  bool move(){

    int mx, my;
    char mball;
    int max_removed;

    max_removed = 1;
    
    /* select max removed ball */
    for ( int i = 0; i < currentGrid.size(); i++ ){
      for ( int j = 0; j < currentGrid[i].size(); j++ ){
	if ( used[i][j] != current ){
	  counter = 0;
	  dfs( i, j, currentGrid[i][j] );

	  if ( max_removed < counter ){
	    mx = i; my = j;
	    max_removed = counter;
	  }
	}
      }
    }

    if ( max_removed == 1 ) return false;

    mball = currentGrid[mx][my];

    fillDfs( mx, my, mball );


    /* remove */
    for ( int i = 0; i < currentGrid.size(); i++ ){
      for ( int j = 0; j < currentGrid[i].size(); j++ ){
	if ( currentGrid[i][j] == ' ' ){
	  currentGrid[i].erase( currentGrid[i].begin() + j );
	  j--;
	}
      }
    }

    for ( int i = 0; i < currentGrid.size(); i++ ){
      if ( currentGrid[i].size() == 0 ){
	currentGrid.erase( currentGrid.begin() + i );
	i--;
      }
    }

    int point = ( max_removed - 2 )*( max_removed - 2 );

    printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n",
	   current, my+1, mx+1, max_removed, mball, point );

    total += point;
    
    if ( currentGrid.size() == 0 ) {
      total += 1000;
      return false;
    }

    return true;
  }
  
  void init(){
    for ( int i = 0; i < 15; i++ ){
      for ( int j = 0; j < 10; j++ ) used[i][j] = 0;
    }
  }

  void work(){
    init();
    current = 1;
    total = 0;
    while ( 1 ){
      if ( !move() ) break;
      current++;
    }

    int remain = 0;
    for ( int i = 0; i < currentGrid.size(); i++ ){
      remain += currentGrid[i].size();
    }

    printf("Final score: %d, with %d balls remaining.\n", total, remain );
  }

  void read(){
    cin >> n;
    for ( int game = 0; game < n; game++ ){
      if ( game ) printf("\n" );
      printf("Game %d:\n\n", game + 1 );
      currentGrid = input;

      for ( int j = 9; j >=0; j-- ){
	for ( int i = 0; i < 15; i++ ){
	  cin >>  currentGrid[i][j];
	}
      }

      work();

    }
  }

};

main(){
  TheSameGame SG = TheSameGame();
  int tcase;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    if ( i ) printf("\n");
    SG.read();
  }
}

// @end_of_source_code


