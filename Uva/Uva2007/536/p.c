// @JUDGE_ID:  17051CA  536  C++
// @begin_of_source_code
/* Tree Recovery */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

/* graph */
vector<vector<int> > G;
int root_pos;

string preord, inord, postord;

bool read(){
  if ( !( cin >> preord >> inord ) ) return false;
  return true;
}

void rec( string str ){

  char ch = preord[ root_pos ];

  /* find root */
  int index = str.find( preord[ root_pos ] );

  string left, right;

  left = str.substr( 0, index );
  right = str.substr( index + 1, str.size() - index - 1);

  if ( left.size() ){
    root_pos++;
    rec( left );
  }

  if ( right.size() ){
    root_pos++;
    rec( right );
  }

  postord += ch;
}

void makeGraph(){
  root_pos = 0;
  postord = "";

  rec( inord );

  cout << postord << endl;
}

void work(){
  makeGraph();
}

main(){
  while ( read() ){
    work();
  }
}
// @end_of_source_code
