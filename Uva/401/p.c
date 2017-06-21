// @JUDGE_ID:  17051CA  401  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#include<map>

string str;
map<char,char> rev;

int read(){
  cin >> str;
  if(cin.eof()) return 0;
  return 1;
}

void work(){
  bool isP = false;
  bool isR = true;

  string revS = str;
  reverse(revS.begin(), revS.end());

  if(revS==str) isP = true;

  int l, r;
  if(str.size()%2==0){ /* even */
    r = str.size()-1;
    for(l=0; l<str.size()/2; l++){
      char cl = str[l];
      char cr = str[r];
      if(!(rev[cl]==cr && rev[cr]==cl)){
	isR = false;
	goto next;
      }
      r--;
    }
  }else{ /* odd */
    char c = str[str.size()/2];
    if(rev[c]!=c){
      isR = false;
      goto next;
    }
    r = str.size()-1;
    for(l=0; l<str.size()/2; l++){
      char cl = str[l];
      char cr = str[r];
      if(!(rev[cl]==cr && rev[cr]==cl)){
	isR = false;
	goto next;
      }
      r--;
    }
  }

 next:;

  if(!isP && !isR){
    cout << str << " -- is not a palindrome." << endl;
  }else if(isP && !isR){
    cout << str << " -- is a regular palindrome." << endl;
  }else if(!isP && isR){
    cout << str << " -- is a mirrored string." << endl;
  }else if(isP && isR){
    cout << str << " -- is a mirrored palindrome." << endl;
  }

  cout << endl;
}

main(){
  rev['A'] = 'A';
  rev['B'] = ' ';
  rev['C'] = ' ';
  rev['D'] = ' ';
  rev['E'] = '3';
  rev['F'] = ' ';
  rev['G'] = ' ';
  rev['H'] = 'H';
  rev['I'] = 'I';
  rev['J'] = 'L';
  rev['K'] = ' ';
  rev['L'] = 'J';
  rev['M'] = 'M';
  rev['N'] = ' ';
  rev['O'] = 'O';
  rev['P'] = ' ';
  rev['Q'] = ' ';
  rev['R'] = ' ';
  rev['S'] = '2';
  rev['T'] = 'T';
  rev['U'] = 'U';
  rev['V'] = 'V';
  rev['W'] = 'W';
  rev['X'] = 'X';
  rev['Y'] = 'Y';
  rev['Z'] = '5';
  rev['1'] = '1';
  rev['2'] = 'S';
  rev['3'] = 'E';
  rev['4'] = ' ';
  rev['5'] = 'Z';
  rev['6'] = ' ';
  rev['7'] = ' ';
  rev['8'] = '8';
  rev['9'] = ' ';

  while(read()){
    work();
  }

}
// @end_of_source_code
