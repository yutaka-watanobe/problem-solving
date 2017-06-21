// @JUDGE_ID:  17051CA  492  C++
// @begin_of_source_code
#include<stdio.h>
#include<string>

main(){

  string str = "";
  string tmp = "";
  char c, sc;
  while( 1 ){
    if (scanf("%c", &c) == EOF) return 0;
    if( c==' ' || c == '\n' ){
      if( str != ""){
	sc = str[0];
	if( sc == 'a' || sc == 'i' || sc == 'u' || sc == 'e' || sc == 'o' || sc == 'A' || sc == 'I' || sc == 'U' || sc == 'E' || sc == 'O'){
	  if( str[ str.length() - 1] == '.'){
	    str.insert( str.length()-1, "ay");
	  }else{
	    str.append("ay");
	  }
	}else{
	   if( str[ str.length() - 1] == '.'){
	     tmp = "";
	     tmp = tmp + str[0] + "ay";
	     str.erase(0, 1);
	     str.insert( str.length()-1, tmp);
	   }else{
	     tmp = str[0];
	     str.erase(0, 1);
	     str = str + tmp;
	     str.append("ay");
	   }
	}
      }
      cout << str;
      printf("%c", c);
      str = "";
    }else{
      str = str + c;
    }

  }
  return 0;
}
// @end_of_source_code
