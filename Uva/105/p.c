// @JUDGE_ID:  17051CA  105  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<vector>
#define MAX 10002
void init();
int read();
void work();

int L, H, R, last;
unsigned int g[MAX];

void init(){
  for(int i=0; i<MAX; i++) g[i] = 0;
  last = 0;
}

int read(){
  cin >> L >> H >> R;
  if( cin.eof() ) return 0;
  else return 1;
}

void addBuilding(){
  for(int i=L; i<R; i++){
    if( g[i] < H ) g[i] = H;
  }
  if( R > last ) last = R;
}

void work(){
  /*
  for(int i=0; i<=last; i++){
    cout << g[i] << " ";
  }
  cout << endl;
  */
  int h = 0;
  bool isfirst = true;
  for(int i=0; i<=last; i++){
    if( g[i] != h ){
      h = g[i];
      if(isfirst) {
	cout << i << " " << g[i]; 
	isfirst = false;
      }else{
	cout << " " << i << " " << g[i]; 
      }
    }
  }
  cout << endl;
}

main(){
  init();
  while( read() ){
    addBuilding();
  }
  work();
}
// @end_of_source_code
