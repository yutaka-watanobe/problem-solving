// @JUDGE_ID:  17051CA  10221  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>

#define PI 3.141592653589793238462643

double s, a;
string str;

int read(){
  cin >> s >> a >> str;
  if(cin.eof()) return 0;
  return 1;
}

void work(){
  double rad, rad2, r;

  if(str=="deg"){
    rad = (PI/180)*a;
  }else{
    rad = (PI/10800)*a;
  }

  r = 6440 + s;

  if(rad<=PI) printf("%.6f", r*rad);
  else printf("%.6f", (2*PI-rad)*r);

  cout << " ";

  printf("%.6f", sqrt(2*r*r - 2*r*r*cos(rad)));
  cout << endl;
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
