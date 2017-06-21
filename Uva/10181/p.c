// @JUDGE_ID:  17051CA  10181  C++
// @begin_of_source_code
/* Iterative Deepening - 15 Puzzle Problem */
#include<stdio.h>
#include<iostream>
#include<cmath>
#include<stl.h>
#include<string>
#include<map>
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

struct Puzzle{
  unsigned short content[16];
};

class PuzzleProblem{
 public:
  Puzzle initialState, state;
  int POS[16][2];
  int initialSpace, space, initialMD;
  int MIN; /* depth */

  int cost;
  int path[ 100 ];

  PuzzleProblem(){
    POS[1][0] = 0; POS[1][1] = 0;
    POS[2][0] = 0; POS[2][1] = 1;
    POS[3][0] = 0; POS[3][1] = 2;
    POS[4][0] = 0; POS[4][1] = 3;
    POS[5][0] = 1; POS[5][1] = 0;
    POS[6][0] = 1; POS[6][1] = 1;
    POS[7][0] = 1; POS[7][1] = 2;
    POS[8][0] = 1; POS[8][1] = 3;
    POS[9][0] = 2; POS[9][1] = 0;
    POS[10][0] = 2; POS[10][1] = 1;
    POS[11][0] = 2; POS[11][1] = 2;
    POS[12][0] = 2; POS[12][1] = 3;
    POS[13][0] = 3; POS[13][1] = 0;
    POS[14][0] = 3; POS[14][1] = 1;
    POS[15][0] = 3; POS[15][1] = 2;
  }

  int getMD( int pos, int number ){
    return abs( POS[number][0] - pos/4 ) + abs( POS[number][1] - pos%4 );
  }

  /* get manhattan distance */
  int getAllMD( Puzzle pz ){
    int sum = 0;
    for ( int i = 0; i < 16; i++ ){
      if ( pz.content[i] == 0 ) continue;
      sum += getMD( i, pz.content[i] );
    }
    return sum;
  }

  bool isSolved(){
    if ( state.content[0] == 1 && state.content[1] == 2 && state.content[2] == 3 && state.content[3] == 4 &&
	 state.content[4] == 5 && state.content[5] == 6 && state.content[6] == 7 && state.content[7] == 8 &&
	 state.content[8] == 9 && state.content[9] == 10 && state.content[10] == 11 && state.content[11] == 12 &&
	 state.content[12] == 13 && state.content[13] == 14 && state.content[14] == 15 && state.content[15] == 0 ){
      return true;
    }
    return false;
  }

  char getDirection( int r ){
    switch( r ){
    case 0:
      return 'R'; break;
    case 1:
      return 'U'; break;
    case 2:
      return 'L'; break;
    case 3:
      return 'D'; break;
    }
  }
  
  bool equalState( Puzzle p1, Puzzle p2 ){
    for ( int i = 0; i < 16; i++ ){
      if ( p1.content[i] != p2.content[i] ) return false;
    }
    return true;
  }

  bool iterative_deepening( int N, int M, Puzzle before ){

    if ( isSolved() ){
      cost = N;
      return true;;
    }

    if ( N + M > MIN ) return false;

    int px, py, tx, ty;

    px = space / 4;
    py = space % 4;

    Puzzle tmpState;
    int tmpSpace, number;
    int manhattan_distance;

    for ( int r = 0; r < 4; r++ ){
      tx = px + dx[r];
      ty = py + dy[r];
      if ( 0 <= tx && 0 <= ty && tx < 4 && ty < 4 ){
	tmpState = state;
	tmpSpace = space;
	space = tx*4 + ty;
	number = state.content[space];
	manhattan_distance = M;
	manhattan_distance -= getMD( space, number);
	state.content[px*4+py] = state.content[space];
	state.content[space] = 0;
	manhattan_distance += getMD(px*4+py, number );

	if ( !equalState( before, state ) ){
	  if ( iterative_deepening( N + 1, manhattan_distance, tmpState ) ){
	    path[ N ] = r;
	    return true;
	  }
	}

	state = tmpState;
	space = tmpSpace;
      }
    }
    
    return false;
  }

  bool solubility(){
    /* １から１５までとスペースがあるか？ */
    int cnt[16]; /* 0 - > x */
    fill ( cnt, cnt + 16, 0 );
    for ( int i = 0; i < 16; i++ ){
      int ch = initialState.content[i];
      cnt[ ch ]++;
    }
    for ( int i = 0; i < 9; i++ ){
      if ( cnt[i] != 1 ) return false;
    }

    /* 奇順列 か 偶順列か */
    int sum = 0;
    for ( int i = 0; i < 16; i++ ){
      if ( initialState.content[i] == 0 ) continue;
      int num = initialState.content[i] ;
      for ( int j = i+1; j < 16; j++ ){
	if ( initialState.content[j] == 0 ) continue;
	
	if ( num >  initialState.content[j]  ) sum++;
      }
    }
    
    sum += ( initialSpace / 4 + 1 );
    if ( sum % 2 == 0 ) return true;
    else return false;

  }

  void work(){
    bool solved;

    if ( !solubility() ){
      cout << "This puzzle is not solvable." << endl;
      return;
    }

    initialMD = getAllMD( initialState );
    int limit = 45;
    solved = false;
    MIN = initialMD;

    while ( 1 ){
      state = initialState;
      space = initialSpace;
      Puzzle before;

      solved = iterative_deepening( 0, initialMD, before );
      if ( solved ) break;
      MIN += 2;
      if ( MIN > limit ) break;
    }

    if ( solved ){
      for ( int i = 0; i < cost; i++ ){
	cout << getDirection( path[i] );
      }
      cout << endl;
    } else {
      cout << "This puzzle is not solvable." << endl;
    }
  }

  void read(){
    int num;
    for ( int i = 0; i < 16; i++ ){
      cin >> num;
      if ( num == 0 ) initialSpace = i;
      initialState.content[i] = num;
    }
  }

};

main(){
  int tcase;
  cin >> tcase;
  PuzzleProblem PP = PuzzleProblem();
  for ( int i = 0; i < tcase; i++ ){
    PP.read();
    PP.work();
  }
}

// @end_of_source_code


