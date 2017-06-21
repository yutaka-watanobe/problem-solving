// @JUDGE_ID:  17051CA  155  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>

int K, px, py;

int sum;

int read(){
  cin >> K >> px >> py;
  if(K==0 && px==0 && py==0) return 0;
  return 1;
}

bool isContain(int x, int y, int hw){
  int x1 = x-hw;
  int x2 = x+hw;
  int y1 = y-hw;
  int y2 = y+hw;
  if(x1 <= px && px <= x2 && y1 <= py && py <= y2) return true;
  return false;
}

void createSquare(int x, int y, int k){
  if(isContain(x, y, k)) sum++;
  if(k>1){
    createSquare(x-k, y-k, k/2);
    createSquare(x+k, y-k, k/2);
    createSquare(x-k, y+k, k/2);
    createSquare(x+k, y+k, k/2);
  }
}

void work(){
  sum = 0;
  createSquare(1024, 1024, K);
  printf("%3d\n", sum);
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
