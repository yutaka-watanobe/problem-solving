// @JUDGE_ID:  17051CA  10235  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>

bool is_prime(int k){
  if(k<2) return false;
  else if(k==2) return true;
  if(k%2 == 0) return false;
  for(int i=3; i*i <= k; i+=2) if(k%i==0) return false;
  return true;
}

string str;

int read(){
  str = "";
  getline(cin, str);

  if(str.size()>0) return 1;
  return 0;
}

void work(){
  bool P, R;
  string tmp = str;
  P = R = false;
  int x, y;
  x = atoi(tmp.c_str());
  P = is_prime(x);
  reverse(tmp.begin(), tmp.end());
  y = atoi(tmp.c_str());
  R = is_prime(y);

  if(!P) cout << str << " is not prime." << endl;
  else if(P && R && x!=y) cout << str << " is emirp." << endl;
  else cout << str << " is prime." << endl;

}

main(){
  while(read()) work();
}
// @end_of_source_code
