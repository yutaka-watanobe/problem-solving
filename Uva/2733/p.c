// @JUDGE_ID:  17051CA  2733  C++
// @begin_of_source_code
/* Simple Encode */
#include<stdio.h>
#include<iostream>
#include<string>

string lower = "abcdefghijklmnopqrstuvwxyz";
string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string digit = "0123456789";

class CaesarCipher{
 public:
  int shift;
  string line;

  char convert( char ch ) {
    int move = shift;
    int index;
    int pos;

    if ( isalpha( ch ) ){
      if ( islower( ch ) ){
	index = ch - 'a';
	if ( move >= 0 ){
	  pos = ( index + move ) % 26;
	} else {
	  move = -move;
	  pos = index - ( move % 26 );
	  if ( pos < 0 ) pos = 26 + pos;
	}
	return lower[ pos ];
      } else {
	index = ch - 'A';
	if ( move >= 0 ){
	  pos = ( index + move ) % 26;
	} else {
	  move = -move;
	  pos = index - ( move % 26 );
	  if ( pos < 0 ) pos = 26 + pos;
	}
	return upper[ pos ];
      }
    } else if ( isdigit( ch ) ){
      index = ch - '0';
      if ( move >= 0 ){
	pos = ( index + move ) % 10;
      } else {
	move = -move;
	pos = index - ( move % 10 );
	if ( pos < 0 ) pos = 10 + pos;
      }
      return digit[ pos ];
    } else {
      return ch;
    }
  }

  void work(){
    for ( int i = 0; i < line.size(); i++ ){
      printf("%c", convert( line[i] ) );
    }
    printf("\n");
  }
  
  bool read(){
    char ch;

    cin >> ch;
    cin.unget();

    if ( ch == '#' ) return false;

    cin >> shift;
    cin >> ch;
    getline( cin, line );
    return true;
  }

};

main(){
  CaesarCipher CC;
  while ( CC.read() ){
    CC.work();
  }
}

// @end_of_source_code


