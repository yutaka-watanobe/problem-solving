// @JUDGE_ID:  17051CA  10024  C++
// @begin_of_source_code
/* パズル */
/* 与えられたグリッドが Cube を生成できるか否かを判定する問題 */
/* 実際に転がした 。*/

#include<stdio.h>
#include<iostream>
#include<string>
#define RIGHT 0
#define BACK 1
#define LEFT 2
#define FRONT 3

class Cube{
 public: 
  int top, bottom, left, right, front, back;
  bool visited[6];
  
  void check(){
    visited[bottom] = true;
  }

  bool isCube(){
    int sum = 0;
    for(int i=0; i<6; i++) {if(visited[i])sum++;}
    return (sum==6);
  }

  Cube(){
    top = 0;
    bottom = 1;
    left = 2;
    right = 3;
    front = 4;
    back = 5;
    for(int i=0; i<6; i++) visited[i] = false;
  }

  void moveFront(){
    int tmp = bottom;
    bottom = front;
    front = top;
    top = back;
    back = tmp;
  }

  void moveBack(){
    int tmp = bottom;
    bottom = back;
    back = top;
    top = front;
    front = tmp;
  }

  void moveLeft(){
    int tmp = left;
    left = top;
    top = right;
    right = bottom;
    bottom = tmp;
  }

  void moveRight(){
    int tmp = right;
    right = top;
    top = left;
    left = bottom;
    bottom = tmp;
  }

};

int G[6+2][6+2];
bool U[6+2][6+2];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
Cube cube;

int read(){
  int k;
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      U[i][j] = false;
      G[i][j] = 0;
    }
  }
  for(int i=1; i<=6; i++){
    for(int j=1; j<=6; j++){
      cin >> G[i][j];
    }
  }
}

void rec(int i, int j){

  cube.check();

  U[i][j] = true;

  int ni, nj;
  for(int d=0; d<4; d++){
    ni = i + dx[d];
    nj = j + dy[d];
    if(!U[ni][nj] && G[ni][nj]==1){
      if(d==RIGHT) cube.moveRight();
      else if(d==LEFT) cube.moveLeft();
      else if(d==BACK) cube.moveBack();
      else if(d==FRONT) cube.moveFront();
      rec(ni, nj);
      /* back track */
      if(d==RIGHT) cube.moveLeft();
      else if(d==LEFT) cube.moveRight();
      else if(d==BACK) cube.moveFront();
      else if(d==FRONT) cube.moveBack();
    }
  }

}

void work(){
  int si, sj;
  for(int i=1; i<=6; i++){
    for(int j=1; j<=6; j++){
      if(G[i][j]==1){
	si = i; sj = j;
	goto start;
      }
    }
  }

 start:;
  cube = Cube();

  rec(si, sj);
  
  if(cube.isCube()) cout << "correct" << endl;
  else cout << "incorrect" << endl;
  
}

main(){
  int testCase;
  cin >> testCase;
  for(int i=0; i<testCase; i++){
    read();
    work();
  }
}
// @end_of_source_code



