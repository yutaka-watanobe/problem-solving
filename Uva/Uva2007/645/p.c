// @JUDGE_ID:  17051CA  645  C++
// @begin_of_source_code
/* Simulation of Directory Structure */
/* Use vector as a Stack */
/* use cin.unget() !! */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<stl.h>

class Directory{
 public:
  string name;
  set<string> fileList;
  set<string>::iterator pos;
  int level;

  Directory(){}
  Directory( string name, int level ):name(name), level(level){}

  void printFileList(){
    for ( pos = fileList.begin(); pos != fileList.end(); pos++ ){
      printPrefix();
      cout << *pos << endl;
    }
  }
  
  void printPrefix(){
    for ( int i = 0; i < level; i++ ){
      cout << "|     ";
    }
  }
};

void work(){
  vector<Directory> stack;

  stack.push_back( Directory( "ROOT", 0 ) );
  
  string line;
  
  cout << "ROOT" << endl;
  while ( 1 ){
    cin >> line;

    if ( line == "*" ) {
      Directory current = stack.back();
      current.printFileList();
      return;
    }

    if ( line[0] == 'd'){

      stack.push_back( Directory( line, stack.size() ) );

      Directory current = stack.back();
      current.printPrefix(); 
      cout << current.name << endl;

    } else if ( line[0] == 'f' ){
      stack.back().fileList.insert( line );
    } else if ( line == "]" ){
      Directory current = stack.back();
      current.printFileList();
      stack.pop_back();
    }

  }

}

main(){
  for ( int i = 1; ; i++ ){
    char ch;
    cin >> ch; cin.unget();
    if ( ch == '#' ) break;
    cout << "DATA SET " << i << ":" << endl;
    work();
    cout << endl;
  }
}
// @end_of_source_code
