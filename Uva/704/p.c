// @JUDGE_ID:  17051CA  704  C++
// @begin_of_source_code
/* Puzzle */
/* 0.436 sec */
#include<stdio.h>
#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
typedef long long llong;

llong p[12] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000LL,
	     1000000000LL, 10000000000LL, 100000000000LL};

class Path{
 public:
  char path[8];
  int size;
  Path(){ size = 0;}
  
  void push_back( char ch ){
    path[size++] = ch;
  }

  int getCost(){ return size; }
};

class State{
 public:
  char left[12];
  char right[12];
  Path path;
  
  State(){}
  
  llong getLeft(){
    llong sum = 0;
    for ( int i = 0; i < 12; i++ ){
      sum += left[i] * p[i];
    }
    return sum;
  }

  llong getRight(){
    llong sum = 0;
    for ( int i = 0; i < 12; i++ ){
      sum += right[i] * p[i];
    }
    return sum;
  }

  int getCost(){
    return path.getCost();
  }

  void move( char ch ){
    path.push_back( ch );
  }

  void validateRight(){
    right[9] = left[9];
    right[10] = left[10];
    right[11] = left[11];
  }

  void validateLeft(){
    left[9] = right[9];
    left[10] = right[10];
    left[11] = right[11];
  }

  void rotate( int i ){
    if ( i == 1 ) rotate1();
    else if ( i == 2 ) rotate2();
    else if ( i == 3 ) rotate3();
    else if ( i == 4 ) rotate4();
  }

  void rotate1(){
    int tmp1 = left[0];
    int tmp2 = left[1];

    left[0] = left[10];
    left[10] = left[8];
    left[8] = left[6];
    left[6] = left[4];
    left[4] = left[2];
    left[2] = tmp1;

    left[1] = left[11];
    left[11] = left[9];
    left[9] = left[7];
    left[7] = left[5];
    left[5] = left[3];
    left[3] = tmp2;

    validateRight();
    move('1');
  }

  void rotate2(){
    int tmp1 = right[0];
    int tmp2 = right[1];

    right[0] = right[2];
    right[2] = right[4];
    right[4] = right[6];
    right[6] = right[8];
    right[8] = right[10];
    right[10] = tmp1;

    right[1] = right[3];
    right[3] = right[5];
    right[5] = right[7];
    right[7] = right[9];
    right[9] = right[11];
    right[11] = tmp2;
    
    validateLeft();
    move('2');
  }

  void rotate3(){
    int tmp1 = left[10];
    int tmp2 = left[11];
    left[10] = left[0];
    left[0] = left[2];
    left[2] = left[4];
    left[4] = left[6];
    left[6] = left[8];
    left[8] = tmp1;

    left[11] = left[1];
    left[1] = left[3];
    left[3] = left[5];
    left[5] = left[7];
    left[7] = left[9];
    left[9] = tmp2;

    validateRight();
    move('3');
  }

  void rotate4(){
    int tmp1 = right[0];
    int tmp2 = right[1];
    right[0] = right[10];
    right[10] = right[8];
    right[8] = right[6];
    right[6] = right[4];
    right[4] = right[2];
    right[2] = tmp1;

    right[1] = right[11];
    right[11] = right[9];
    right[9] = right[7];
    right[7] = right[5];
    right[5] = right[3];
    right[3] = tmp2;
    
    validateLeft();
    move('4');
  }

};

class ColorHush{
 public:
  State initial, goal;
  
  ColorHush(){
    goal = State();
    goal.left[0] = 0; goal.left[1] = 3; goal.left[2] = 4; goal.left[3] = 3;
    goal.left[4] = 0; goal.left[5] = 5; goal.left[6] = 6; goal.left[7] = 5;
    goal.left[8] = 0; goal.left[9] = 1; goal.left[10] = 2; goal.left[11] = 1;
    
    goal.right[0] = 0; goal.right[1] = 7; goal.right[2] = 8; goal.right[3] = 7;
    goal.right[4] = 0; goal.right[5] = 9; goal.right[6] = 1; goal.right[7] = 9;
    goal.right[8] = 0; goal.right[9] = 1; goal.right[10] = 2; goal.right[11] = 1;
  }

  void work(){
    Path start_path, goal_path;
    int cost = bfs(start_path, goal_path);

    if ( cost == 0 ) printf("PUZZLE ALREADY SOLVED\n");
    else if ( cost == -1 ) printf("NO SOLUTION WAS FOUND IN 16 STEPS\n");
    else {
      for ( int i = 0; i < start_path.getCost(); i++ ) printf("%c", start_path.path[i] );
      for ( int i = goal_path.getCost() - 1; i >= 0; i-- ){
	switch( goal_path.path[i] ){
	case '1': printf("3"); break;
	case '2': printf("4"); break;
	case '3': printf("1"); break;
	case '4': printf("2"); break;
	}
      }
      printf("\n");
    }
  }

  int bfs( Path &start_path, Path &goal_path ){
    queue<State> qS, qG;
    map<pair<llong, llong>, bool> visitedS;
    map<pair<llong, llong>, bool> visitedG;

    map<pair<llong, llong>, Path> S; /* path 保存用 */
    map<pair<llong, llong>, Path> G; /* path 保存用 */

    State current, next;
    pair<llong, llong> next_value;

    visitedS[ make_pair( initial.getLeft(), initial.getRight() ) ] = true;
    visitedG[ make_pair( goal.getLeft(), goal.getRight() ) ] = true;

    S[ make_pair( initial.getLeft(), initial.getRight() ) ] = initial.path;
    G[ make_pair( goal.getLeft(), goal.getRight() ) ] = goal.path;

    qS.push( initial );
    qG.push( goal );

    while ( !qS.empty() && !qG.empty() ){

      current = qS.front(); qS.pop();

      if ( visitedG[ make_pair(current.getLeft(), current.getRight() ) ] ){
	Path target = G[ make_pair(current.getLeft(), current.getRight()) ];
	start_path = current.path;
	goal_path = target;
	return current.getCost() + target.getCost();
      }

      for ( int rotate = 1; rotate <= 4; rotate++ ){
	next = current;
	next.rotate( rotate );
	next_value = make_pair( next.getLeft(), next.getRight() );
	if ( !visitedS[ next_value ] ){
	  visitedS[ next_value] = true;
	  S[ next_value ] = next.path;
	  if ( next.getCost() <= 8 ) qS.push( next );
	}
      }

      current = qG.front(); qG.pop();

      if ( visitedS[ make_pair(current.getLeft(), current.getRight() ) ] ){
	Path target = S[ make_pair(current.getLeft(), current.getRight()) ];
	start_path = target;
	goal_path = current.path;
	return current.getCost() + target.getCost();
      }

      for ( int rotate = 1; rotate <= 4; rotate++ ){
	next = current;
	next.rotate( rotate );
	next_value = make_pair( next.getLeft(), next.getRight() );
	if ( !visitedG[ next_value ] ){
	  visitedG[ next_value ] = true;
	  G[ next_value ] = next.path;
	  if ( next.getCost() <= 8 ) qG.push( next );
	}
      }
    }

    return -1;
  }

  void read(){

    initial = State();
    int value;
    for ( int i = 0; i < 12; i++ ){
      scanf("%d", &value );
      if ( value == 10 ) value = 1;
      initial.left[i] = (char)value;
    }

    for ( int i = 0; i < 12; i++ ){
      scanf("%d", &value );
      if ( value == 10 ) value = 1;
      initial.right[i] = (char)value;
    }
  }
  
};

main(){
  ColorHush CH;
  int tcase;
  scanf("%d", &tcase );
  for ( int i = 0; i < tcase; i++ ){
    CH.read();
    CH.work();
  }
}


// @end_of_source_code


