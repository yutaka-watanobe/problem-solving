// @JUDGE_ID:  17051CA  10085  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
#include<vector>
typedef unsigned short ushort;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

struct Puzzle{
  ushort content[9];
};

class TheMostDistantState{
 public:
  Puzzle initialState;
  Puzzle finalState;
  int isx, isy;
  int max_distance;
  vector<int> finalPath;

  bool equalState( Puzzle &p1, Puzzle &p2 ){
    for ( int i = 0; i < 9; i++ ){
      if ( p1.content[i] != p2.content[i] ) return false;
    }
    return true;
  }

  bool contain( vector<Puzzle> pl, Puzzle p ){
    for ( int i = pl.size() - 1; i >= 0; i-- ){
      if ( equalState( pl[i], p)  ) return true;
    }
    return false;
  }

  void recursive( Puzzle state, int sx, int sy, vector<Puzzle> used, vector<int> path ){

    /* printPuzzle( state );*/

    used.push_back( state );

    int tx, ty;
    Puzzle next;
    vector<Puzzle> nextUsed;
    vector<int> nextPath;

    bool hasNext = false;

    for ( int r = 0; r < 4; r++ ){
      tx = sx + dx[r];
      ty = sy + dy[r];
      if ( 0 <= tx && 0 <= ty && tx < 3 && ty < 3 ){
	next = state;
	nextUsed = used;

	next.content[sx*3 + sy] = state.content[tx*3+ty];
	next.content[tx*3+ty] = 0;

	if ( !contain( nextUsed, next ) ) {
	  nextPath = path;
	  path.push_back( r );
	  hasNext = true;
	  recursive( next, tx, ty, nextUsed, nextPath );
	}
      }
    }
    
    if ( !hasNext ){
      if ( max_distance < path.size() ){
	finalState = state;
	max_distance = path.size();
	finalPath = path;
	cout << max_distance << endl;
      }
    }
    


  }

  void printPuzzle( Puzzle &p ){
    for ( int i = 0; i < 9; i++ ){
      cout << p.content[i];
      if ( (i + 1) % 3 == 0 ) cout << endl;
      else cout << " ";
    }
    cout << endl;
  }

  void work(){
    max_distance = 0;
    vector<Puzzle> used;
    recursive( initialState, isx, isy, used, vector<int>() );

    printPuzzle( finalState );
  }

  
  void read(){
    ushort ch;
    for ( int i = 0; i < 9; i++ ){
      cin >> ch;
      if ( ch == 0 ) {
	  isx = i/3; isy = i%3;
      }
      initialState.content[i] = ch;
    }
  }
  
};

main(){
  TheMostDistantState TMDS;
  int tcase;
  cin >> tcase;
  for ( int i = 1; i <= tcase; i++ ){
    cout << "Puzzle # " << i << endl;
    TMDS.read();
    TMDS.work();
    cout << endl;
  }
}

// @end_of_source_code


