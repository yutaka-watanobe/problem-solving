// @JUDGE_ID:  17051CA  10226  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#include<set>
#include<map>

class Tree{
 public:
  string name;
  int count;
  Tree( string name ): name(name){
    count = 1;
  }
};

void work(){
  string line;
  set<string> T;
  map<string, int> M;
  int sum = 0;
  while ( 1 ) {
    getline ( cin, line );
    if ( line == "" ) break;
    if ( binary_search( T.begin(), T.end(), line ) ){
      M[ line ]++;
    }else{
      T.insert( line );
      M[ line ]++;
    }
    sum++;
  }

  set<string>::iterator pos;
  for ( pos = T.begin(); pos != T.end(); pos++ ){
    cout << *pos << " ";
    printf("%.4f\n", 100.0 * M[ *pos ] / sum );
  }

}

main(){
  string line;
  int t;
  getline( cin, line );
  t = atoi( line.c_str() );
  getline( cin, line );
  for ( int i = 0; i < t; i++ ){
    if ( i ) cout << endl;
    work();
  }
}
// @end_of_source_code
