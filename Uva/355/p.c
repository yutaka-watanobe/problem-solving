// @JUDGE_ID:  17051CA  355  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>

typedef unsigned long long ullong;

string line;
int org, conv;

int read(){
  cin >> org >> conv >> line;
  if(cin.eof()) return 0;
  return 1;
}

int getNum(char c){
  long long k = 10000;
  if(c=='A') k = 10;
  else if(c=='B') k = 11;
  else if(c=='C') k = 12;
  else if(c=='D') k = 13;
  else if(c=='E') k = 14;
  else if(c=='F') k = 15;
  else if(c=='G') k = 16;
  else if('0' <= c && c <=  '9' ) k = c - '0';

  return k;
}

ullong convert10(string str){
  ullong b = 0;
  ullong sum = 0;
  for(int i=str.size()-1; i>=0; i--){
    sum += getNum(str[i]) * (ullong)pow(org, b);
    b++;
  }
  return sum;
}

bool check(string str){
  for(int i=0; i<str.size(); i++){
    if(getNum(str[i]) > org-1) return false;
  }
  return true;
}

char getCharX(int x){
  if( 0 <= x && x <= 9 ) return x + '0';
  else if(x==10) return 'A';
  else if(x==11) return 'B';
  else if(x==12) return 'C';
  else if(x==13) return 'D';
  else if(x==14) return 'E';
  else if(x==15) return 'F';
  else if(x==16) return 'G';
}

string convertBase(ullong x){
  int b = 0;
  string str = "";
  while(1){
    if(x < (ullong)pow(conv, b)) break;
    b++;
    if(b>100)break;
  }
  
  ullong a, p, t, r;
  t = x;
  for(int i=b; i>=0; i--){
    p = (ullong)pow(conv, i);
    a = t/p;
    r = t%p;
    if(a==0){
      if(str.size()>0) str += '0';
    }else{
      char c = getCharX((int)a);
      str += c;
    }
    t = r;
  }
  if(str.size()==0) str = "0";
  return str;
}

void work(){
  if(!check(line)){
    cout << line << " is an illegal base " << org << " number" << endl;
  }else{
    if(conv==10){
      cout << line << " base " << org << " = " << convert10(line) << " base " << conv << endl;
    }else{
      cout << line << " base " << org << " = " << convertBase(convert10(line)) << " base " << conv << endl;
    }
  }
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
