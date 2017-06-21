// @JUDGE_ID:  17051CA  391  C++
// @begin_of_source_code
/* Parser - HTML Mark-up */
#include<stdio.h>
#include<iostream>
#include<string>
#define MAX 10000
#define ON 1
#define OFF 0

class MarkUP{
 public:
  char text[ MAX ];
  int size;
  bool markUp;

  void work(){
    size = strlen( text );
    markUp = ON;
    
    int cursor = 0;

    while ( 1 ){
      if ( cursor >= size ) break;

      char ch = text[ cursor++ ];
      char next;

      if ( markUp ){
	if ( ch == '\\' ){
	  next = text[cursor++];
	  if ( next == 'i' || next == 'b' ){

	  } else if ( next == 's' ){
	    while ( isdigit( text[cursor] ) || text[cursor] == '.' ){
	      cursor++;
	    }
	  } else if ( next == '*' ){
	    markUp = OFF;
	  } else {
	    printf("%c", next );
	  }
	} else {
	  printf("%c", ch );
	}
      } else {
	if ( ch == '*' ){
	  if ( text[cursor - 2] == '\\' ){
	    markUp = ON;
	  } else {
	    printf("%c", ch );
	  }
	} else if ( ch == '\\' ){
	  if ( text[cursor] != '*' ){
	    printf("%c", ch );
	  }
	} else {
	  printf("%c", ch );
	}
      }
    }
    
  }

  void read(){
    int cursor = 0;
    char ch;
    while ( scanf("%c", &ch ) != EOF ){
      text[ cursor++ ] = ch;
    }
    if ( text[cursor-1] == '\\' ){
      cout << "aa" << endl;
      text[cursor] = '\\';
    }
  }

};

main(){
  MarkUP MU;
  MU.read();
  MU.work();
}
// @end_of_source_code


