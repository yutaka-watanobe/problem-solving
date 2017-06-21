// @JUDGE_ID:  17051CA  10620  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#define MAX 1000

class Chessboard{
 public:
  int S, px, py, dx, dy;

  bool search(){
    int W = 2*S;
    int x, y;
    int sx, sy;
    int step = 0;
    sx = px%W;
    sy = py%W;
    while ( 1 ){
      x = px%W;
      y = py%W;

      if ( 0 < x && x < S && S < y && y < W ||
	   S < x && x < W && 0 < y && y < S ) {
	
	printf("After %d jumps the flea lands at (%d, %d).\n", step, px, py );
	return true;
      }
      if (x == sx && y == sy && step) return false;
      px += dx;
      py += dy;
      step++;
    }
  }


  void work(){
    if ( !search() ) printf("The flea cannot escape from black squares.\n");
  }

  bool read(){
    scanf("%d %d %d %d %d", &S, &px, &py, &dx, &dy );
    if ( S == 0 && px == 0 && py == 0 && dx == 0 && dy == 0 ) return false;
    return true;
  }
};

main(){
  Chessboard C;
  while ( C.read() ) C.work();
}

// @end_of_source_code


