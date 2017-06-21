// @JUDGE_ID:  17051CA  2282  C++
// @begin_of_source_code
/* Simple encode - decode Simulation */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<stl.h>

map<char, string> T_C; /* map Text to Code */
map<string, char> C_T; /* map Code to Text */

void init(){
  T_C[ 'A' ] = ".-";
  T_C[ 'B' ] = "-...";
  T_C[ 'C' ] = "-.-.";
  T_C[ 'D' ] = "-..";
  T_C[ 'E' ] = ".";
  T_C[ 'F' ] = "..-.";
  T_C[ 'G' ] = "--.";
  T_C[ 'H' ] = "....";
  T_C[ 'I' ] = "..";
  T_C[ 'J' ] = ".---";
  T_C[ 'K' ] = "-.-";
  T_C[ 'L' ] = ".-..";
  T_C[ 'M' ] = "--";
  T_C[ 'N' ] = "-.";
  T_C[ 'O' ] = "---";
  T_C[ 'P' ] = ".--.";
  T_C[ 'Q' ] = "--.-";
  T_C[ 'R' ] = ".-.";
  T_C[ 'S' ] = "...";
  T_C[ 'T' ] = "-";
  T_C[ 'U' ] = "..-";
  T_C[ 'V' ] = "...-";
  T_C[ 'W' ] = ".--";
  T_C[ 'X' ] = "-..-";
  T_C[ 'Y' ] = "-.--";
  T_C[ 'Z' ] = "--..";
  T_C[ '_' ] = "..--";
  T_C[ ',' ] = ".-.-";
  T_C[ '.' ] = "---.";
  T_C[ '?' ] = "----";
  map<char, string>::iterator pos;
  for ( pos = T_C.begin(); pos != T_C.end(); pos++ ){
    C_T[ (*pos).second ] = (*pos).first;
  }
}

void work(){
  string message;
  cin >> message;

  vector<int> L;
  string code;

  for ( int i = 0; i < message.size(); i++ ){
    char ch = message[i];
    L.push_back( T_C[ ch ].size() );
    code += T_C[ ch ];
  }
  reverse( L.begin(), L.end() );

  int pos = 0;
  for ( int i = 0; i < L.size(); i++ ){
    int len = L[i];
    string current = "";
    for ( int l = 0; l < len; l++ ){
      current += code[ pos ];
      pos++;
    }
    cout << C_T[ current ];
  }
  cout << endl;
}

main(){
  init();
  int t;
  cin >> t;
  for ( int i = 1; i <= t; i++ ){
    cout << i << ": ";
    work();
  }
}
// @end_of_source_code
