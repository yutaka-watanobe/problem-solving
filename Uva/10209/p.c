// @JUDGE_ID:  17051CA  10209  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>

#define PI 3.14159265358979323846

double a;
double T, P, A;

int read(){
  cin >> a;
  return (cin.eof() ? false : true);
}

void work(){
  double striped, dotted, checked;
  A = a*a;
  checked = A*T;
  dotted = A*P - 2*checked;
  striped = A - 4*(dotted+checked);

  printf("%.3f %.3f %.3f\n", striped, dotted*4, checked*4);
}

main(){
  T = 1 - sqrt(3)/4.0 - PI/6;
  P = 1 - PI/4;
  while(read()) work();
}
// @end_of_source_code
