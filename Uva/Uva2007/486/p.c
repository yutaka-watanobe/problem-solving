// @JUDGE_ID:  17051CA  486  C++
// @begin_of_source_code
/* Parse */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#define END INT_MAX

void split(vector<string> &d, const string &s, char c=' '){
  string t = "";

  for(int i=0; i<s.size(); i++){    
    if(s[i]==c){
      if(t!=""){ d.push_back(t); t = ""; }
    }
    else t += s[i];
  }
  if(t.size()) d.push_back(t);
}

vector<string> S;
vector<int> T; 
int pos;

map<string, int> M; /* string - > int value */

int read(){
  string line;
  getline( cin, line );
  if ( line.size() == 0 || cin.eof() ) return 0;
  
  S.clear();
  split( S, line );

  T.clear();
  for ( int i = 0; i < S.size(); i++ ){
    T.push_back( M[ S[i] ] );
  }

  return 1;
}

int getCoefficient(){
  int c = T[ pos ];
  pos++;

  if ( T[ pos ] == 100 ){
    pos++;
    c *= 100;
  }
  
  while ( T[ pos ] < 100 ){
    c += T[ pos ];
    pos++;
  }

  return c;
}

int parse(){
  int coefficient = getCoefficient();
  int value;
  if ( T[ pos ] != END ) value = T[ pos ];
  else value = 1;

  pos++;

  return coefficient * value;
}

void work(){
  pos = 0;

  int sign = 1;
  
  if ( T[0] == -1 ){
    sign = -1;
    pos++;
  }

  int ans = 0;

  /* num + num + ... + ( hundred || thousand || million ) */
  T.push_back( 0 );
  T.push_back( END );

  while ( pos < T.size() ){
    ans += parse();
  }
  
  ans *= sign;

  cout << ans << endl;
}

void init(){
  M[ "negative" ] = -1;
  M[ "zero" ] = 0;
  M[ "one" ] = 1;
  M[ "two" ] = 2;
  M[ "three" ] = 3;
  M[ "four" ] = 4;
  M[ "five" ] = 5;
  M[ "six" ] = 6;
  M[ "seven" ] = 7;
  M[ "eight" ] = 8;
  M[ "nine" ] = 9 ;
  M[ "ten" ] = 10;
  M[ "eleven" ] = 11;
  M[ "twelve" ] = 12;
  M[ "thirteen" ] = 13 ;
  M[ "fourteen" ] = 14;
  M[ "fifteen" ] = 15;
  M[ "sixteen" ] = 16;
  M[ "seventeen" ] = 17;
  M[ "eighteen" ] = 18;
  M[ "nineteen" ] = 19;
  M[ "twenty" ] = 20;
  M[ "thirty" ] = 30;
  M[ "forty" ] = 40;
  M[ "fifty" ] = 50;
  M[ "sixty" ] = 60;
  M[ "seventy" ] = 70;
  M[ "eighty" ] = 80;
  M[ "ninety" ] = 90;
  M[ "hundred" ] = 100;
  M[ "thousand" ] = 1000;
  M[ "million" ] = 1000000;
}

main(){
  init();
  while ( read() ){
    work();
  }
}
// @end_of_source_code
