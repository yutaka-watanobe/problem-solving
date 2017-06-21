// @JUDGE_ID:  17051CA  2732  C++
// @begin_of_source_code
/* Simplest */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

class CDTitles{
 public:
  vector<string> T;

  void work(){
    int size = T.size();
    for ( int i = 0; i < size * 2 + 1; i++ ) printf("-");
    printf("\n");
    for ( int i = 0; i < 36; i++ ){
      printf("|");
      for ( int j = 0; j < T.size(); j++ ){
	printf("%c|", T[j][i]);
      }
      printf("\n");
    }
    for ( int i = 0; i < size * 2 + 1; i++ ) printf("-");
    printf("\n");
  }

  void read(){
    string line;
    while ( 1 ) {
      getline( cin, line );
      if ( line == "#" ) return;
      line.resize( 36, ' ' );
      T.push_back( line );
    }
  }
};

main(){
  CDTitles CT;
  CT.read();
  CT.work();
}

// @end_of_source_code


