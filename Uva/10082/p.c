// @JUDGE_ID:  17051CA  10082  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<map>

string line;
map<char, char> m;

int read(){
  getline(cin, line);
  if(cin.eof()) return 0;
  return 1;
}

void work(){
  char c;
  for(int i=0; i<line.size(); i++){
    c = line[i];
    if(c==' ') cout << " ";
    else{
      cout << m[c];
    }
  }
  cout << endl;
}

main(){
  m['`'] = '`'; 
  m['1'] = '`';
  m['2'] = '1';
  m['3'] = '2';
  m['4'] = '3';
  m['5'] = '4';
  m['6'] = '5';
  m['7'] = '6';
  m['8'] = '7';
  m['9'] = '8';
  m['0'] = '9';
  m['-'] = '0';
  m['='] = '-';
  m['Q'] = 'Q';
  m['W'] = 'Q';
  m['E'] = 'W';
  m['R'] = 'E';
  m['T'] = 'R';
  m['Y'] = 'T';
  m['U'] = 'Y';
  m['I'] = 'U';
  m['O'] = 'I';
  m['P'] = 'O';
  m['['] = 'P';
  m[']'] = '[';
  m['\\'] = ']';
  m['A'] = 'A';
  m['S'] = 'A';
  m['D'] = 'S';
  m['F'] = 'D';
  m['G'] = 'F';
  m['H'] = 'G';
  m['J'] = 'H';
  m['K'] = 'J';
  m['L'] = 'K';
  m[';'] = 'L';
  m['\''] = ';';
  m['Z'] = 'Z';
  m['X'] = 'Z';
  m['C'] = 'X';
  m['V'] = 'C';
  m['B'] = 'V';
  m['N'] = 'B';
  m['M'] = 'N';
  m[','] = 'M';
  m['.'] = ',';
  m['/'] = '.';

  while(read()){
    work();
  }
}
// @end_of_source_code
