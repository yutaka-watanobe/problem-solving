// @JUDGE_ID:  17051CA  2731  C++
// @begin_of_source_code
/* Simplest */
#include<stdio.h>
#include<iostream>
#include<string>
#include<map>

map<char, int> M;

class WacmianNumber{
 public:
  string line;
  
  void work(){
    int p = 1;
    int sum = 0;
    for ( int i = line.size() - 1; i >= 0; i-- ){
      sum += M[ line[i] ] * p;
      p *= 6;
    }
    cout << sum << endl;
  }

  bool read(){
    cin >> line;
    if ( line == "#" ) return false;
    return true;
  }
};

void init(){
  M['%'] = 0;
  M[')'] = 1;
  M['~'] = 2;
  M['@'] = 3;
  M['?'] = 4;
  M['\\'] = 5;
  M['$'] = -1;
}

main(){
  init();
  WacmianNumber WN;
  while ( WN.read() ){
    WN.work();
  }
}
// @end_of_source_code


