// @JUDGE_ID:  17051CA  895  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>

class Word{
 public:
  int content[26];

  Word(){
    for ( int i = 0; i < 26; i++ ) content[i] = 0;
  }
};

bool compute( Word source, Word target ){

  for ( int i = 0; i < 26; i++ ){
    if ( source.content[i] == 0 ) continue;
    if ( source.content[i] > target.content[i] ) return false;
  }
  return true;
}

main(){
  Word W[1001];
  int nword = 0;

  string line;
  while ( 1 ){
    getline( cin, line );
    if ( line == "#" ) break;
    Word word;
    for ( int s = 0; s < line.size(); s++ ){
      word.content[ line[s] - 'a' ]++;
    }
    W[nword++] = word;
  }

  while ( 1 ){
    getline ( cin, line );
    if ( line == "#" ) break;
    Word target;
    for ( int s = 0; s < line.size(); s++ ){
      if ( line[s] == ' ' )continue;
      target.content[ line[s] - 'a' ]++;
    }
    int cnt = 0;
    for ( int i = 0; i < nword; i++ ){
      if ( compute( W[i], target ) ) cnt++;
    }
    printf("%d\n", cnt );
  }

}

// @end_of_source_code
