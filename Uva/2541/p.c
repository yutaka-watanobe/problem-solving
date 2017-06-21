// @JUDGE_ID:  17051CA  2541  C++
// @begin_of_source_code
/* Simulation of Rubik's Cube */
#include<stdio.h>
#include<iostream>
#include<set>
#include<string>
#define TOP 0
#define LEFT 1
#define FRONT 2
#define RIGHT 3
#define BACK 4
#define BOTTOM 5

class RubikCubeSolver{
 public:
  char cube[6][9];

  bool validate(){
    set<char> colors;
    for ( int k = 0; k < 6; k++ ){
      char ch = cube[k][0];
      for ( int i = 0; i < 9; i++ ){
	if ( cube[k][i] != ch ) return false;
      }
      colors.insert( ch );
    }
    if ( colors.size() == 6 ) return true;
    else return false;
  }

  void rotateLeft( int face ){
    char tmp[3];
    /* face */
    tmp[0] = cube[face][0]; tmp[1] = cube[face][1]; tmp[2] = cube[face][2];
    cube[face][0] = cube[face][2]; cube[face][1] = cube[face][5]; cube[face][2] = cube[face][8];
    cube[face][2] = cube[face][8]; cube[face][5] = cube[face][7]; cube[face][8] = cube[face][6];
    cube[face][8] = cube[face][6]; cube[face][7] = cube[face][3]; cube[face][6] = tmp[0];
    cube[face][6] = tmp[0]; cube[face][3] = tmp[1]; cube[face][0] = tmp[2];

    if ( face == TOP ){

      tmp[2] = cube[BACK][2];   
      tmp[1] = cube[BACK][1];   
      tmp[0] = cube[BACK][0];   
      cube[BACK][2] = cube[RIGHT][2];
      cube[BACK][1] = cube[RIGHT][1];
      cube[BACK][0] = cube[RIGHT][0];
      cube[RIGHT][2] = cube[FRONT][2];
      cube[RIGHT][1] = cube[FRONT][1];
      cube[RIGHT][0] = cube[FRONT][0];
      cube[FRONT][2] = cube[LEFT][2];
      cube[FRONT][1] = cube[LEFT][1];
      cube[FRONT][0] = cube[LEFT][0];
      cube[LEFT][2] = tmp[2];
      cube[LEFT][1] = tmp[1];
      cube[LEFT][0] = tmp[0];

    } else if ( face == LEFT ){

      tmp[0] = cube[TOP][0];
      tmp[1] = cube[TOP][3];
      tmp[2] = cube[TOP][6];
      cube[TOP][0] = cube[FRONT][0];
      cube[TOP][3] = cube[FRONT][3];
      cube[TOP][6] = cube[FRONT][6];
      cube[FRONT][0] = cube[BOTTOM][0];
      cube[FRONT][3] = cube[BOTTOM][3];
      cube[FRONT][6] = cube[BOTTOM][6];
      cube[BOTTOM][0] = cube[BACK][8];
      cube[BOTTOM][3] = cube[BACK][5];
      cube[BOTTOM][6] = cube[BACK][2];
      cube[BACK][8] = tmp[0];
      cube[BACK][5] = tmp[1];
      cube[BACK][2] = tmp[2];

    } else if ( face == FRONT ){
      
      tmp[0] = cube[TOP][6];
      tmp[1] = cube[TOP][7];
      tmp[2] = cube[TOP][8];
      cube[TOP][6] = cube[RIGHT][0];
      cube[TOP][7] = cube[RIGHT][3];
      cube[TOP][8] = cube[RIGHT][6];
      cube[RIGHT][0] = cube[BOTTOM][2];
      cube[RIGHT][3] = cube[BOTTOM][1];
      cube[RIGHT][6] = cube[BOTTOM][0];
      cube[BOTTOM][2] = cube[LEFT][8];
      cube[BOTTOM][1] = cube[LEFT][5];
      cube[BOTTOM][0] = cube[LEFT][2];
      cube[LEFT][8] = tmp[0];
      cube[LEFT][5] = tmp[1];
      cube[LEFT][2] = tmp[2];

    } else if ( face == RIGHT ){

      tmp[0] = cube[TOP][8];
      tmp[1] = cube[TOP][5];
      tmp[2] = cube[TOP][2];
      cube[TOP][8] = cube[BACK][0];
      cube[TOP][5] = cube[BACK][3];
      cube[TOP][2] = cube[BACK][6];
      cube[BACK][0] = cube[BOTTOM][8];
      cube[BACK][3] = cube[BOTTOM][5];
      cube[BACK][6] = cube[BOTTOM][2];
      cube[BOTTOM][8] = cube[FRONT][8];
      cube[BOTTOM][5] = cube[FRONT][5];
      cube[BOTTOM][2] = cube[FRONT][2];
      cube[FRONT][8] = tmp[0];
      cube[FRONT][5] = tmp[1];
      cube[FRONT][2] = tmp[2];

    } else if ( face == BACK ){
      
      tmp[0] = cube[TOP][2];
      tmp[1] = cube[TOP][1];
      tmp[2] = cube[TOP][0];
      cube[TOP][2] = cube[LEFT][0];
      cube[TOP][1] = cube[LEFT][3];
      cube[TOP][0] = cube[LEFT][6];
      cube[LEFT][0] = cube[BOTTOM][6];
      cube[LEFT][3] = cube[BOTTOM][7];
      cube[LEFT][6] = cube[BOTTOM][8];
      cube[BOTTOM][6] = cube[RIGHT][8];
      cube[BOTTOM][7] = cube[RIGHT][5];
      cube[BOTTOM][8] = cube[RIGHT][2];
      cube[RIGHT][8] = tmp[0];
      cube[RIGHT][5] = tmp[1];
      cube[RIGHT][2] = tmp[2];

    } else if ( face == BOTTOM ){

      tmp[0] = cube[FRONT][6];
      tmp[1] = cube[FRONT][7];
      tmp[2] = cube[FRONT][8];
      cube[FRONT][6] = cube[RIGHT][6];
      cube[FRONT][7] = cube[RIGHT][7];
      cube[FRONT][8] = cube[RIGHT][8];
      cube[RIGHT][6] = cube[BACK][6];
      cube[RIGHT][7] = cube[BACK][7];
      cube[RIGHT][8] = cube[BACK][8];
      cube[BACK][6] = cube[LEFT][6];
      cube[BACK][7] = cube[LEFT][7];
      cube[BACK][8] = cube[LEFT][8];
      cube[LEFT][6] = tmp[0];
      cube[LEFT][7] = tmp[1];
      cube[LEFT][8] = tmp[2];

    }
    
  }

  void work(){
    string face, direction;
    while ( 1 ){
      cin >> face;
      if ( face == "END" ) break;
      cin >> direction;
      
      if ( direction == "left" ) rotateLeft( getFace( face ) );
      else {
	int f = getFace( face );
	rotateLeft( f );
	rotateLeft( f );
	rotateLeft( f );
      }
    }
    if ( validate() ) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

  int getFace( string face ){
    if ( face == "top" ) return TOP;
    else if ( face == "front" ) return FRONT;
    else if ( face == "left" ) return LEFT;
    else if ( face == "right" ) return RIGHT;
    else if ( face == "back" ) return BACK;
    else if ( face == "bottom" ) return BOTTOM;
  }

  void readCube(){
    for ( int j = 0; j < 9; j++ ) cin >> cube[TOP][j];
    for ( int i = 0; i < 3; i++ ){
      for ( int k = 1; k <= 4; k++ ){
	for ( int j = 0; j < 3; j++ ) cin >> cube[k][i*3+j];
      }
    }
    for ( int j = 0; j < 9; j++ ) cin >> cube[BOTTOM][j];
  }

  bool read(){
    string line;
    cin >> line;
    if ( line == "ENDOFINPUT" ) return false;
    readCube();
    return true;
  }
};

main(){
  RubikCubeSolver solver;

  while ( solver.read() ){
    solver.work();
  }
}

// @end_of_source_code


