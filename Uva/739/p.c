// @JUDGE_ID:  17051CA  739  C++
// @begin_of_source_code
/* Simulation */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>

map<char, int> M;
string line;

bool isNever(char c){
  if ( c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y' || c == 'W' ) return true;
  else return false;
}

void init(){
  M['B'] = 1;
  M['P'] = 1;
  M['F'] = 1;
  M['V'] = 1;
  M['C'] = 2;
  M['S'] = 2;
  M['K'] = 2;  
  M['G'] = 2;
  M['J'] = 2;
  M['Q'] = 2;
  M['X'] = 2;
  M['Z'] = 2;
  M['D'] = 3;
  M['T'] = 3;
  M['L'] = 4;
  M['M'] = 5;
  M['N'] = 5;
  M['R'] = 6;
}

void work(){
  vector<int> v;

  char pre = line[0];

  for ( int i = 1; i < line.size(); i++ ){
    if ( M[ line[i]] != M[ pre ] && !isNever(line[i] )){
      if ( M[ line[i] ] > 0 ) v.push_back( M[ line[i] ] );
    }
    if ( v.size() == 3 ) break;
    pre = line[i];
  }

  while ( v.size() < 3 ) v.push_back( 0 );

  string out = "";
  for ( int i = 0; i < 9; i++ ) out += " ";
  out += line;
  while ( out.size() < 34 ) out += " ";
  cout << out << line[0];
  for ( int i = 0; i < 3; i++ ) cout << v[i];
  cout << endl;
}

main(){
  init();
  cout << "         NAME                     SOUNDEX CODE" << endl;
  while ( cin >> line ){
    work();
  }
  cout << "                   END OF OUTPUT" << endl;
}
// @end_of_source_code
