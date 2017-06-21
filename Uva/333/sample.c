#include <stdio.h>
#include <stl.h>
#include <string>

void trim(string &s){
  int l, r;

  l = s.find_first_not_of(' ');
  r = s.find_last_not_of(' ');

  if(l<0 || s.size()<=l) s = "";
  else s = s.substr(l, r-l+1);
}

string str, isbn;

int read();
int work();

main(){
  while(read()){
    if(work()){
      cout << str << " is correct." << endl;
    }
    else {
      cout << str << " is incorrect." << endl;
    }
  }
}

int work(){
  int num[10];
  int sum[10];

  if(isbn.size()!=10) return 0;

  for(int i=0; i<isbn.size()-1; i++){
    if(isbn[i]=='X') return 0;
  }

  for(int i=0; i<isbn.size();i++){
    if(isbn[i]=='X') num[i] = 10;
    else num[i] = isbn[i]-'0';
    sum[i] = 0;
  }

  sum[0] = num[0];
  for(int i=1; i<10; i++){
    sum[i] = sum[i-1]+num[i];
  }
  
  int n = accumulate(sum, sum+10, 0);

  return !(n%11);
}

int read(){
  string s;

  getline(cin, s);
  if(cin.eof()) return 0;

  trim(s);
  str = s;
  isbn = "";

  isbn = "";
  for(int i=0; i<s.size(); i++){
    if(isdigit(s[i]) || s[i]=='X'){
      isbn += s[i];
    }
    else if(s[i]!='-'){
      isbn = "";
      break;
    }
  }

  return 1;
}
