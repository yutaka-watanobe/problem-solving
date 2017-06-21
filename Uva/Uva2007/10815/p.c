// Set, string
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<set>


main(){
  char ch;
  string str = "";
  set<string> S;
  
  while ( scanf("%c", &ch) != EOF ){
    if ( isalpha( ch ) ){
      ch = tolower( ch );
      str += ch;
    } else {
      if ( str.size() ){
	S.insert( str );
	str = "";
      }
    }
  }
  if ( str.size() ) S.insert( str );

  set<string>::iterator pos;
  for ( pos = S.begin(); pos != S.end(); pos++ ) {
    printf("%s\n", (*pos).c_str());
  }
  
}
