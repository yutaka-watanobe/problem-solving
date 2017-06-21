// @JUDGE_ID:  17051CA  10302  C++
// @begin_of_source_code
#include<stdio.h>
#include<math.h>
#include<iostream.h>

typedef long long llong;

int read();
void work();

llong n;

int read(){
  cin >> n;
  if( cin.eof() ) return 0;
  else return 1;
}

void work(){
  cout <<  ( n*n*(n+1)*(n+1) )/4 << endl; 
}

main(){
 while(read()){
    work();
  }
}
// @end_of_source_code
