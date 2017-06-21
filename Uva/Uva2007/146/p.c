// @JUDGE_ID:  17051CA  146  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>

int read();
void work();

string line;

int read(){
  cin >> line;
  if( line.size()==1 ){
    if(line[0]=='#') return 0;
  }
  return 1;
}

void work(){
  if( next_permutation(line.begin(), line.end()) ){
    cout << line << endl;
  }else{
    cout << "No Successor" << endl;
  }
}

main(){
  while( read() ){
    work();
  }
}
// @end_of_source_code
