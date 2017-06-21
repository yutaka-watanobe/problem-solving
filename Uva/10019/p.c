// @JUDGE_ID:  17051CA  10019  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>

/** Hexadecimal string --> unsigned long */
unsigned long axtoul(const string &s){
  unsigned long x;
  sscanf(s.c_str(), "%x", &x);

  return x;
}

int getCount( int a ){
  int next;
  int sum = 0;
  while( 1 ){
    if(a%2 == 1) sum++;
    next = a/2;
    a = next;
    if(next==0 ) break;
  }
  return sum;
}

void work(){
  string line;
  cin >> line;
  int dec, hex;

  dec = atoi(line.c_str());
  sscanf(line.c_str(), "%x", &hex);

  cout << getCount(dec) << " " << getCount(hex) << endl;

}

main(){
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    work();
  }
}
// @end_of_source_code
