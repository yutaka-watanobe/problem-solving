// @JUDGE_ID:  17051CA  2360  C++
// @begin_of_source_code
/* Simulation ( Challenge ) */
/* 0.070 sec    64 */
#include<stdio.h>
#include<iostream>
#include<cassert>
#include<algorithm>
#include<cmath>
#define BLOCK -1
#define SPACE 0
#define DEBRY 100 /* 1-99 is for robot index */

using namespace std;

int dx[9] = { -1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy[9] = {  -1, 0, 1, -1, 0, 1, -1, 0, 1};

class Robot{
 public:
  int x, y;
  bool active;

  Robot(){}
  Robot( int x, int y ): x(x), y(y){ active = true; }

  int getNextDirection( int &px, int &py ){
    if ( x > px && y < py ) return 2;
    else if ( x > px && y > py ) return 0;
    else if ( x < px && y > py ) return 6;
    else if ( x < px && y < py ) return 8;
    else if ( x == px ){
      if ( y < py ) return 5;
      else if ( y > py ) return 3;
    } else if ( y == py ){
      if ( x < px ) return 7;
      else if ( x > px ) return 1;
    }
    assert( false );
  }

  int getDistance( int &px, int &py ){
    return abs( px - x ) + abs( py - y );
  }

};

class Teleport{
 public:
  int x, y;
  bool used;

  Teleport(){}
  Teleport( int x, int y ): x(x), y(y){ used = false; };
};

class State{
 public:
  int px, py; /* player's position */
  int trobot; /* total robot */
  int nrobot; /* remaing robot */
  bool killed;
  Robot R[51];
  int B[35][35];
  int minimum_distance;

  State(){}
  State( int trobot ): trobot(trobot){
    for ( int i = 0; i < 35; i++ ){
      for ( int j = 0; j < 35; j++ ){
	/* banpei */
	if ( i == 0 || i == 1 || i == 33 || i == 34 ||
	     j == 0 || j == 1 || j == 33 || j == 34 ) B[i][j] = BLOCK;
	else B[i][j] = SPACE;
      }
    }
    px = 16; py = 16;
    nrobot = trobot;
    killed = false;
  }

  void move( int &nx, int &ny ){
    px = nx; py = ny;
  }

  void push( int &nx, int &ny, int &nnx, int &nny ){
    px = nx; py = ny;
    B[nx][ny] = SPACE;
    B[nnx][nny] = DEBRY;
  }
  
  void crush( int &nx, int &ny, int &nnx, int &nny ){
    int index = B[nnx][nny];
    R[index].active = false;
    push( nx, ny, nnx, nny );
    nrobot--;
  }

  void moveRobots(){
    /* init */
    for ( int i = 1; i <= trobot; i++ ){
      if ( !R[i].active ) continue;
      B[R[i].x][R[i].y] = SPACE;
    }

    int next_direction;
    int nx, ny;
    
    for ( int i = 1; i <= trobot; i++ ){
      if ( !R[i].active ) continue;
      next_direction = R[i].getNextDirection( px, py );
      nx = R[i].x + dx[next_direction];
      ny = R[i].y + dy[next_direction];

      if ( nx == px && ny == py ) killed = true;

      if ( B[nx][ny] == DEBRY ){
	R[i].active = false;
	nrobot--;
      } else if ( B[nx][ny] != SPACE ){
	int target = B[nx][ny];
	R[i].active = false;
	R[target].active = false;
	nrobot -= 2;
	B[nx][ny] = DEBRY;
      } else {
	B[nx][ny] = i;
	R[i].x = nx;
	R[i].y = ny;
      }
    }
    minimum_distance = INT_MAX;

    for ( int i = 1; i <= trobot; i++ ){
      if ( !R[i].active ) continue;
      minimum_distance = min( minimum_distance, R[i].getDistance( px, py ) );
    }
  }

  int getDebry(){
    int sum = 0;
    for ( int i = 2; i <= 32; i++ ){
      for ( int j = 2; j <= 32; j++ ){
	if ( B[i][j] == DEBRY ) sum++;
      }
    }
    return sum;
  }

};

class RobotsSimulation{
 public:
  State initial_state;
  Teleport T[50];

  int tteleport;
  
  void work(){
    State  state;
    State current_state;
    State next_state = initial_state;
    int cursor = 0;

    int nx, ny, nnx, nny;

    while ( 1 ){
      current_state = next_state;

      if ( current_state.nrobot == 0 ){
	printf("Won game after making %d moves.\n", cursor );
	printf("Final position: (%d,%d)\n", current_state.px - 1, current_state.py - 1 );
	printf("Number of cells with debris: %d\n", current_state.getDebry() );
	return;
      }

      /* move */
      int remaining = INT_MAX;
      int maximum_distance = 0;

      for ( int r = 0; r < 9; r++ ){
	state = current_state;
	
	nx = state.px + dx[r];
	ny = state.py + dy[r];

	if ( state.B[nx][ny] == SPACE ){
	  state.move( nx, ny );
	} else if ( state.B[nx][ny] == DEBRY ){
	  nnx = nx + dx[r];
	  nny = ny + dy[r];
	  if ( state.B[nnx][nny] == SPACE ) state.push( nx, ny, nnx, nny );
	  else if ( state.B[nnx][nny] != DEBRY && state.B[nnx][nny] != BLOCK ) state.crush( nx, ny, nnx, nny );
	} else continue;

	state.moveRobots();

	if ( state.killed ) continue;

	if ( remaining == state.nrobot ){
	  if ( maximum_distance < state.minimum_distance ){
	    exchange( next_state, remaining, maximum_distance,
		      state, state.nrobot, state.minimum_distance );
	  }
	} else if ( remaining > state.nrobot ){
	  exchange( next_state, remaining, maximum_distance,
		    state, state.nrobot, state.minimum_distance );
	}
      }
      
      if ( remaining != INT_MAX ) goto next;
      
      /* teleport */
      for ( int i = 0; i < tteleport; i++ ){
	if ( T[i].used ) continue;
	state = current_state;
	
	if ( isSafe( state, T[i].x, T[i].y ) ){
	  T[i].used = true;
	  state.move( T[i].x, T[i].y );
	  state.moveRobots();
	  printf("Move %d: teleport to (%d,%d)\n", cursor+1, T[i].x-1, T[i].y-1 );
	  next_state = state;
	  goto next;
	}
      }
      
      /* lose */
      state = current_state;
      state.moveRobots();
      assert( state.killed );
      printf("Lost game after making %d moves.\n", cursor+1);
      printf("Final position: (%d,%d)\n", state.px-1, state.py-1 );
      printf("Number of cells with debris: %d\n", state.getDebry() );
      printf("Number of robots remaining: %d\n", state.nrobot );
      return;

    next:;
      cursor++;
    }

  }

  bool isSafe( State &state, int px, int py ){
    if ( state.B[px][py] != SPACE ) return false;
    int nx, ny;
    for ( int r = 1; r < 9; r++ ){
      nx = px + dx[r];
      ny = py + dy[r];
      int s = state.B[nx][ny];
      if ( s != BLOCK && s != SPACE && s != DEBRY ) return false;
    }
    return true;
  }

  void exchange( State &nstate, int &remaining, int &maximum_distance,
		 State state, int nrobot, int minimum_distance ){
    nstate = state;
    remaining = nrobot;
    maximum_distance = minimum_distance;
  }

  bool read(){
    int x, y, trobot;

    scanf("%d %d", &trobot, &tteleport);
    if ( trobot == 0 && tteleport == 0 ) return false;

    initial_state = State( trobot );

    for ( int i = 1; i <= trobot; i++ ){
      scanf("%d %d", &x, &y );
      initial_state.R[i] = Robot( x+1, y+1 );
      initial_state.B[x+1][y+1] = i;
    }

    for ( int i = 0; i < tteleport; i++ ){
      scanf("%d %d", &x, &y );
      T[i] = Teleport( x+1, y+1 );
    }
    
    return true;
  }

};

main(){
  RobotsSimulation RS;
  for ( int i = 1; RS.read(); i++ ){
    if ( i > 1 ) printf("\n");
    printf("Case %d:\n", i );
    RS.work();
  }
}

// @end_of_source_code


