#include<stdio.h>
#include<iostream>

#define ROW 13
#define COL 100

bool grid[ROW][COL];

int k;

void init(){
  for(int i=0; i<ROW; i++){
    for(int j=0; j<COL; j++){
      grid[i][j] = false;
    }
  }
}

int read(){
  cin >> k;
  if(cin.eof()) return 0;
  return 1;
}

void work(){
  int i, j;

  while(read()){
    if(k>=10000){
      k -= 10000;
      k += 900;
      i = k/100 - 1;
      j = k%100;
    }else{
      i = k/100 - 1;
      j = k%100;
    }
    grid[i][j] = true;
  }


  for(int i=0; i<ROW; i++){
    for(int j=0; j<COL; j++){
      if(grid[i][j]) cout << "#";
      else cout <<".";
    }
    cout << endl;
  }
}

main(){
  init();
  work();
}

