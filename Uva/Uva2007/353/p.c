// @JUDGE_ID:  17051CA  353  C++
// @begin_of_source_code
/* String */
#include<stdio.h>
#include<iostream>
#include<string>
#include<set>

class PeskyPalindrome{
 public:
  string line;
  set<string> S;

  bool isPalindrome( string str ){
    int start = 0;
    int end = str.size() - 1;
    int size = str.size();

    for ( start = 0; start < size / 2; start++, end-- ){
      if ( str[start] != str[end] ) return false;
    }
    return true;
  }

  void work(){
    int size = line.size();
    S.clear();

    for ( int len = 1; len <= size; len++ ){
      for ( int j = 0; j <= size - len; j++ ){
	string sub = line.substr( j, len );
	if ( isPalindrome( sub ) ) S.insert( sub );
      }
    }

    printf("The string '%s' contains %d palindromes.\n",
	   line.c_str(), S.size() );
  }

  bool read(){
    if ( !( cin >> line ) ) return false;
    return true;
  }

};

main(){
  PeskyPalindrome PP;
  while ( PP.read() ){
    PP.work();
  }
}
// @end_of_source_code


