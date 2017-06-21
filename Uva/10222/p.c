// @JUDGE_ID:  17051CA  10222  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<map>

void tolower(string &s){
  for(int i=0; i<s.size(); i++) 
    s[i] = tolower(s[i]);
}

string str;
map<char, char> m;

void work(){
  getline(cin,  str);

  tolower(str);

  for(int i=0; i<str.size(); i++){
    cout << m[str[i]];
  }
  cout << endl;
}

main(){
  m[' '] = ' ';
  m['a'] = ' ';
  m['b'] = 'c';
  m['c'] = 'z';
  m['d'] = 'a';
  m['e'] = 'q';
  m['f'] = 's';
  m['g'] = 'd';
  m['h'] = 'f';
  m['i'] = 'y';
  m['j'] = 'g';
  m['k'] = 'h';
  m['l'] = 'j';
  m['m'] = 'b';
  m['n'] = 'v';
  m['o'] = 'u';
  m['p'] = 'i';
  m['q'] = 'q';
  m['r'] = 'w';
  m['s'] = ' ';
  m['t'] = 'e';
  m['u'] = 't';
  m['v'] = 'x';
  m['w'] = ' ';
  m['x'] = ' ';
  m['y'] = 'r';
  m['z'] = ' ';
  m['['] = 'o';
  m[']'] = 'p';
  m[';'] = 'k';
  m['\''] = 'l';
  m[','] = 'n';
  m['.'] = 'm';
  m['/'] = ',';
  work();
}
// @end_of_source_code
