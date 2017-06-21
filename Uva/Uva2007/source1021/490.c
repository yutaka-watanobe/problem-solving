// @JUDGE_ID:  17051CA  490  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#include<stdlib.h>

void work();
void init();

char grid[200][200];

void init(){
  for(int i=0; i<200; i++){
    for(int j=0; j<200; j++){
      grid[i][j] = ' ';
    }
  }
}

void work(){
  string line;
  int h, w;
  h = w = 0;
  init();
  while(1){
    getline(cin, line);
    if(cin.eof()) break;
    int s = line.size();
    w = max(w, s);
    for(int j=0; j<line.size(); j++){
      grid[h][j] = line[j];
    }
    h++;
  }
  /*
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      cout << grid[i][j];
    }
    cout << endl;
  }
  */
  for(int j=0; j<w; j++){
    for(int i=h-1; i>=0; i--){
      cout << grid[i][j];
    }
    cout << endl;
  }
}

main(){
  work();
}
// @end_of_source_code
