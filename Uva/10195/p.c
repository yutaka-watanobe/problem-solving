// @JUDGE_ID:  17051CA  10195  C++
// @begin_of_source_code
/* 幾何学 */
/* 三角形を作れない場合を考慮しなければならない */
#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>

long double a, b, c;

int read(){
  cin >> a >> b >> c;
  if(cin.eof()) return 0;
  return 1;
}

void work(){
  double m = max(max(a, b), c);

  long double s, r;
  s = (a + b + c)/2;
  r = (long double)sqrt(s*(s-a)*(s-b)*(s-c))/s;
  if(m >= a + b + c - m) r = 0;
  cout << "The radius of the round table is: " ;
  printf("%.3Lf\n", r);
}

main(){
  while(read()) work();
}
// @end_of_source_code
