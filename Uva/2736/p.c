// @JUDGE_ID:  17051CA  2736  C++
// @begin_of_source_code
/* String Search */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
#define MAX 1001

char M[26] = {'2', '2', '2',
	      '3', '3', '3',
	      '4', '4', '4',
	      '5', '5', '5',
	      '6', '6', '6',
	      '7', '7', '7', '7',
	      '8', '8', '8',
	      '9', '9', '9', '9'};

class MobilePhone{
 public:
  string W[ MAX ];
  char digit[ 100 ];
  int nword;
  int ndigit;
  bool first;

  void call( string number ){
    if ( first ) {
      first = false;
    } else {
      printf(" ");
    }

    vector<string> candidate;

    for ( int i = 0; i < nword; i++ ){
      string word = W[i];
      if ( word.size() != number.size() ) continue;

      for ( int j = 0; j < number.size(); j++ ){
	if ( M[ word[j] - 'a' ] != number[j] ) goto next;
      }
      
      candidate.push_back( word );
    next:;
    }

    if ( candidate.size() == 0 ){
      for ( int i = 0; i < number.size(); i++ ) printf("*");
    } else if ( candidate.size() == 1 ){
      printf("%s", candidate[0].c_str() );
    } else {
      printf("(");
      for ( int i = 0; i < candidate.size(); i++ ){
	if ( i ) printf("|");
	string str = candidate[i];
	printf("%s", str.c_str() );
      }
      printf(")");
    }
  }

  void work(){

    char ch;
    string number = "";


    while ( 1 ){
      first = true;
      while ( 1 ){
	scanf("%c", &ch);
	if ( ch == '#' ) {
	  scanf("%c", &ch );
	  goto next;
	}
	if ( ch == '\n' ) {
	  if ( number.size() ){
	    call ( number );
	    number = "";
	  }
	  break;
	}
	if ( ch == '0' ){
	  if ( number.size() ){
	    call( number );
	    number = "";
	  }
	} else {
	  number += ch;
	}
      }
      printf("\n");
    }
  next:;

  }

  bool read(){
    nword = 0;
    string line;
    while ( 1 ){
      getline( cin, line );
      if ( line == "#" ) break;
      W[ nword++ ] = line;
    }
  next:;
    if ( nword ) return true;
    else return false;
  }

};

main(){
  MobilePhone MP;
  for ( int i = 1; MP.read(); i++ ){
    printf("SET %d\n", i );
    MP.work();
  }
}
// @end_of_source_code


