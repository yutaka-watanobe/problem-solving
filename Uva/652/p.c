// @JUDGE_ID:  17051CA  652  C++
// @begin_of_source_code
/* Iterative Deepening - 8 Puzzle Problem */
#include<stdio.h>
#include<iostream>
#include<cmath>
#include<stl.h>
#include<string>

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

struct Puzzle{
  char content[9];
};

class Eight{
 public:
  Puzzle initialState, state;

  int POS[9][2];
  int initialSpace, space, initialMD;
  int MIN; /* depth */

  int cost;
  int path[ 100 ];

  Eight(){
    POS[1][0] = 0; POS[1][1] = 0;
    POS[2][0] = 0; POS[2][1] = 1;
    POS[3][0] = 0; POS[3][1] = 2;
    POS[4][0] = 1; POS[4][1] = 0;
    POS[5][0] = 1; POS[5][1] = 1;
    POS[6][0] = 1; POS[6][1] = 2;
    POS[7][0] = 2; POS[7][1] = 0;
    POS[8][0] = 2; POS[8][1] = 1;
  }

  int getMD( int pos, int number ){
    return abs( POS[number][0] - pos/3 ) + abs( POS[number][1] - pos%3 );
  }

  /* get manhattan distance */
  int getAllMD( Puzzle pz ){
    int sum = 0;
    for ( int i = 0; i < 9; i++ ){
      if ( pz.content[i] == 'x' ) continue;
      sum += getMD( i, pz.content[i] - '0' );
    }
    return sum;
  }

  bool isSolved(){
    if ( state.content[0] == '1' && state.content[1] == '2' && state.content[2] == '3' &&
	 state.content[3] == '4' && state.content[4] == '5' && state.content[5] == '6' &&
	 state.content[6] == '7' && state.content[7] == '8' && state.content[8] == 'x'){
      return true;
    }
    return false;
  }

  char getDirection( int r ){
    switch( r ){
    case 0:
      return 'r'; break;
    case 1:
      return 'u'; break;
    case 2:
      return 'l'; break;
    case 3:
      return 'd'; break;
    }
  }

  bool equalState( Puzzle p1, Puzzle p2 ){
    for ( int i = 0; i < 9; i++ ){
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

    px = space / 3;
    py = space % 3;

    Puzzle tmpState;
    int tmpSpace, number;
    int manhattan_distance;

    for ( int r = 0; r < 4; r++ ){
      tx = px + dx[r];
      ty = py + dy[r];
      if ( 0 <= tx && 0 <= ty && tx < 3 && ty < 3 ){
	tmpState = state;
	tmpSpace = space;
	space = tx*3 + ty;
	number = state.content[space] - '0';
	manhattan_distance = M;
	manhattan_distance -= getMD( space, number);
	state.content[px*3+py] = state.content[space];
	state.content[space] = 'x';
	manhattan_distance += getMD(px*3+py, number );

	if ( !equalState( state, before )  ) {
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
    /* １から８までとスペースがあるか？ */
    int cnt[9]; /* 0 - > x */
    fill ( cnt, cnt + 9, 0 );
    for ( int i = 0; i < 9; i++ ){
      char ch = initialState.content[i];
      if ( ch == 'x' ) cnt[0]++;
      else cnt[ ch - '0' ]++;
    }
    for ( int i = 0; i < 9; i++ ){
      if ( cnt[i] != 1 ) return false;
    }

    /* 奇順列 か 偶順列か */
    int sum = 0;
    for ( int i = 0; i < 9; i++ ){
      if ( initialState.content[i] == 'x' ) continue;
      int num = initialState.content[i] - '0';
      for ( int j = i+1; j < 9; j++ ){
	if ( initialState.content[j] == 'x' ) continue;
	
	if ( num > ( initialState.content[j] - '0' ) ) sum++;
      }
    }

    if ( sum % 2 == 0 ) return true;
    else return false;

  }

  void work(){
    bool solved;

    if ( !solubility() ){
      cout << "unsolvable" << endl;
      return;
    }

    initialMD = getAllMD( initialState );
    int limit = 100;
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
      assert( false );
    }
  }

  void read(){
    char ch;
    for ( int i = 0; i < 9; i++ ){
      cin >> ch;
      if ( ch == 'x' ) initialSpace = i;
      initialState.content[i] = ch;
    }
  }

};

main(){
  int tcase;
  cin >> tcase;
  Eight E = Eight();
  for ( int i = 0; i < tcase; i++ ){
    if ( i ) cout << endl;
    E.read();
    E.work();
  }
}

// @end_of_source_code


