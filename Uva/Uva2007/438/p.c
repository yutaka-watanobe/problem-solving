// @JUDGE_ID:  17051CA  438  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>

double a, b, c;
double PI = 3.141592653589793;

int read(){
  double x1, x2, x3, y1, y2, y3;

  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  if(cin.eof()) return 0;

  a = sqrt( (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1) );
  b = sqrt( (x2-x3)*(x2-x3)+(y2-y3)*(y2-y3) );
  c = sqrt( (x3-x1)*(x3-x1)+(y3-y1)*(y3-y1) );

  return 1;
}

void work(){
  double s = (a+b+c)/2;
  double R = (a*b*c)/(4*(sqrt(s*(s-a)*(s-b)*(s-c))));
  printf("%.2f\n", 2*R*PI);
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
