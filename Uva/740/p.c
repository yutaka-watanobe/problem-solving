// @JUDGE_ID:  17051CA  740  C++
// @begin_of_source_code
/* Simulation ( Level 1 ) */
#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
#define DOWN 0
#define UP 1

string down, up;
string line;

void init(){
  getline( cin, down );
  getline( cin, up );
}

int read(){
  getline ( cin, line );
  if ( cin.eof() ) return 0;
  return 1;
}

void work(){
  int mode = DOWN;
  int p = 16;
  int v = 0;
  line.insert(line.begin(), ' ');

  for ( int i = 1; i < line.size(); i++ ){
    if ( line[i] == '1' ) v += p;
    if ( i % 5 == 0 ){
      if ( v == 27 ) mode = DOWN;
      else if ( v == 31 ) mode = UP;
      else{
	if ( mode == DOWN ) cout << down[v];
	else if ( mode == UP ) cout << up[v];
      }
      p = 16;
      v = 0;
    }else{
      p = p/2;
    }
  }
  cout << endl;
}

main(){
  init();
  while ( read() ) {
    work();
  }
}
// @end_of_source_code
