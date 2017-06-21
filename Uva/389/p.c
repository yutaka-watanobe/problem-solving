// @JUDGE_ID:  17051CA  389  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>

typedef unsigned long long ullong;

string line;
int org, conv;

int read(){
  cin >> line >> org >> conv;
  if(cin.eof()) return 0;
  return 1;
}

int getNum(char c){
  if('0' <= c && c <=  '9' ) return c - '0';
  else if(c=='A') return 10;
  else if(c=='B') return 11;
  else if(c=='C') return 12;
  else if(c=='D') return 13;
  else if(c=='E') return 14;
  else if(c=='F') return 15;
  else if(c=='G') return 16;
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
      str +=  getCharX((int)a);
    }
    t = r;
  }
  if(str.size()==0) str = "0";
  return str;
}

void work(){
  string str;
  str = convertBase(convert10(line));
  if( str.size()>7 ) str = "  ERROR";
  else if(str.size()<7){
    while(str.size()<7) str = " " + str;
  }
  cout << str << endl;
  
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
