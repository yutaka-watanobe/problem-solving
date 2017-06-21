// @JUDGE_ID:  17051CA  10134  C++
// @begin_of_source_code
/* Simulation ( Simple ) */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

class Robot{
 public:
  int storage;
  int fish_count;
  int last_COD_count;
  int last_fish_count;
  int bait_time;

  Robot(){
    storage = 0;
    fish_count = 0;
    last_COD_count = last_fish_count = 0;
    bait_time = 0;
  }

  void getFish(){
    fish_count++; storage--;
    last_COD_count = last_fish_count = 0;
  }

  bool canFish(){
    return ( last_COD_count >= 7 && last_fish_count >= 3 );
  }

};

Robot robot;

void lunch(){
  robot.last_COD_count++;
}

void fish(){

  if ( robot.storage == 0 ) {
    lunch(); return;
  }

  /* biginner's luch */
  if ( robot.fish_count == 0 ){
    robot.getFish();
    return;
  }

  robot.last_COD_count++;
  robot.last_fish_count++;

  if ( robot.canFish() ){
    robot.getFish();
    return;
  }
}

void bait(){
  if ( robot.storage == 3 ){
    lunch(); return;
  }
  
  if ( robot.bait_time == 0 ){
    robot.bait_time++;
    robot.last_COD_count++;
  }else if ( robot.bait_time == 1 ){
    robot.storage++;
    robot.bait_time = 0;
    robot.last_COD_count++;
  }

}

void COD( string instruction ){
  if ( instruction == "fish" ) fish();
  else if ( instruction == "bait" ) bait();
  else if ( instruction == "lunch" ) lunch();
}

void work(){
  string line;
  robot = Robot();

  while ( 1 ){
    getline( cin, line );
    if ( line == "" || cin.eof() ) break;
    COD( line );
  }
  cout << robot.fish_count << endl;
}

main(){
  string line;
  getline( cin, line );
  int t = atoi( line.c_str() );
  getline( cin, line );
  for ( int i = 0; i < t; i++ ){
    if ( i ) cout << endl;
    work();
  }

}
// @end_of_source_code

