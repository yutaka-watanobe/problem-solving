// @JUDGE_ID:  17051CA  320  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>

void init();
void work();

bool bitMap[32][32];

int pi, pj;

void init(){
  for(int i=0; i<32; i++){
    for(int j=0; j<32; j++){
      bitMap[i][j] = false;
    }
  }
}

void work(){
  string command;
  cin >> pj >> pi;
  cin >> command;

  char c;
  for(int i=0; i<command.size()-1; i++){
    c = command[i];
    if(c=='E'){bitMap[pi-1][pj] = true; pj++;}
    if(c=='S'){bitMap[pi-1][pj-1] = true; pi--;}
    if(c=='N'){bitMap[pi][pj] = true; pi++;}
    if(c=='W'){bitMap[pi][pj-1] = true; pj--;}
  }

  for(int i=31; i>=0; i--){
    for(int j=0; j<32; j++){
      if( bitMap[i][j] ) cout << "X";
      else cout << ".";
    }
    cout << endl;
  }
}

main(){
  int n;
  cin >> n;
  for(int i=1; i<=n; i++){
    cout << "Bitmap #" << i << endl;
    init();
    work();
    cout << endl;
  }
}
// @end_of_source_code

