// @JUDGE_ID:  17051CA  732  C++
// @begin_of_source_code
/* Stack operation */
/* 5.512 sec */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<stl.h>

string firstLine, secondLine;

void rec( int pos1, int pos2, vector<char> cstack, string path ){

  vector<char> tstack;
  string tpath;

  if ( pos2 >= secondLine.size() ){
    for ( int i = 0; i < path.size(); i++ ){
      if ( i ) cout << " ";
      printf("%c", path[i] );
    }
    printf("\n");
    return ;
  }
  
  /* push */
  if ( pos1 < firstLine.size() ){
    tstack = cstack;
    tpath = path;
    tstack.push_back( firstLine[ pos1 ] );
    tpath += 'i';
    rec( pos1 + 1, pos2, tstack, tpath );
  }

  /* pop */
  if ( cstack.size() && secondLine[ pos2 ] == cstack.back() ){
    tstack = cstack;
    tpath = path;
    tstack.pop_back();
    tpath += 'o';
    rec( pos1, pos2 + 1, tstack, tpath );
  }
}

void parse(){
  cout << "[" << endl;
  
  vector<char> cstack;
  string path = "i";
  cstack.push_back( firstLine[0] );
  
  rec( 1, 0,  cstack, path );
  
  cout << "]" << endl;
}

void work(){
  parse();
}

bool read(){
 if ( !(  cin >> firstLine ) ) return false;
 cin >> secondLine;
 return true;
}

main(){
  while ( read() ){
    work();
  }
}

// @end_of_source_code


