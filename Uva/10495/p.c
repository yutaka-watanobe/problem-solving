// @JUDGE_ID:  17051CA  10495  C++
// @begin_of_source_code
/* Geometory */
/* 一周した場合に注意 */
#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
#define PI 3.14159265358979323846

double r, h, d1, A1, d2, A2;

int read(){
  cin >> r >> h >> d1 >> A1 >> d2 >> A2;
  if(cin.eof()) return 0;
  return 1;
}

double getDist(double x1, double y1, double x2, double y2){
  return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}

void work(){

  if(A1 > A2 ){
    if(A1 - A2 > 180 ) A1 = 360 - A1;
  }else if(A2 > A1){
    if(A2 - A1 > 180 ) A2 = 360 - A2;
  }

  double l = sqrt(h*h+r*r);
  double L = 2*PI*r;
  double a = L/(2*PI*l) * 360; /* deg */

  double deg1, deg2, deg3;

  deg1 = a/360 * A1;
  deg2 = a/360 * A2;

  double x1, y1, x2, y2;

  x1 = d1*cos(PI/180*deg1);
  y1 = d1*sin(PI/180*deg1);

  x2 = d2*cos(PI/180*deg2);
  y2 = d2*sin(PI/180*deg2);

  printf("%.2f\n", getDist(x1, y1, x2, y2) );
  
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
