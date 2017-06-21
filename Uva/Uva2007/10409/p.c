// @JUDGE_ID:  17051CA  10409  C++
// @begin_of_source_code
/* Simulation Dies */
#include<stdio.h>
#include<string>
#include<iostream>

class Die{
 public:
  int north, west, east, south, top, bottom;
  
  Die(){
    top = 1;
    north = 2;
    west = 3;
    east = 4;
    south = 5;
    bottom = 6;
  }

  void moveNorth(){
    int tmp = top;
    top = south;
    south = bottom;
    bottom = north;
    north = tmp;
  }

  void moveSouth(){
    int tmp = top;
    top = north;
    north = bottom;
    bottom = south;
    south = tmp;
  }

  void moveEast(){
    int tmp = top;
    top  = west;
    west = bottom;
    bottom = east;
    east = tmp;
  }

  void moveWest(){
    int tmp = top;
    top = east;
    east = bottom;
    bottom = west;
    west = tmp;
  }

};

int n;

int read(){
  cin >> n;
  if(n==0) return 0;
  return 1;
}

void work(){
  Die die = Die();
  string line;
  for(int i=0; i<n; i++){
    cin >> line;
    if(line=="east"){
      die.moveEast();
    }else if(line=="west"){
      die.moveWest();
    }else if(line=="north"){
      die.moveNorth();
    }else if(line=="south"){
      die.moveSouth();
    }
  }

  cout << die.top << endl;
}

int main(){
  while(read()){
    work();
  }
  return 0;
}
// @end_of_source_code
