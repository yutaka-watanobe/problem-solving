// @JUDGE_ID:  17051CA  548  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<stl.h>

void split ( vector<int> &d, const string &s, char c=' ' ) {
  string t = "";
  d.clear();

  for ( int i = 0; i < s.size(); i++ ){    
    if ( s[i] == c ){
      if ( t != "" ){ d.push_back( atoi(t.c_str()) ); t = ""; }
    }
    else t += s[i];
  }
  if ( t.size() ) d.push_back( atoi(t.c_str()) );
}

class Tree{
 public:
  vector<long> inorderT;
  vector<long> postorderT;
  int min_cost;
  int min_leaf;

  void recursive( int inLower, int inUpper, int posLower, int posUpper, int value ){
    int rootIndex = postorderT[ posUpper ];
    
    

  }

  void work(){
    int upper = inorderT.size() - 1;
    int lower = 0;
    min_cost = INT_MAX;
    recursive( lower, upper, lower, upper );
  }

  bool read(){
    inorderT.clear();
    postorderT.clear();
    string line;
    getline( cin, line );
    if ( cin.eof() ) returnfalse;
    split( inorderT, line );
    getline( cin, line );
    split( postorderT, line );
    return true;
  }
};

main(){
  Tree T;
  while ( T.read() ){
    T.work();
  }
}

// @end_of_source_code


