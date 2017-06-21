// @JUDGE_ID:  17051CA  579  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>

double short_hand, long_hand;
int h, m;

int read(){
  char c;
  cin >> h >> c >> m;
  if(h==0 && m==0) return 0;
  return 1;
}

void work(){
  long_hand = (double)m;
  short_hand = h*5.0 + 5.0*m/60;

  /*  cout << long_hand << "  " << short_hand << endl;*/

 
  double sub;
  double tmp_max = max(long_hand, short_hand);
  double tmp_min = min(long_hand, short_hand);
  sub = min( tmp_max - tmp_min, 60 - tmp_max + tmp_min);

  double d = 360 * sub/60;
  printf("%.3f\n", d);
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
