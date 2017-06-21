// @JUDGE_ID:  17051CA  190  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>

double xa, ya, xb, yb, xc, yc;

int read(){
  cin >> xa >> ya >> xb >> yb >> xc >> yc;
  if(cin.eof()) return 0;
  return 1;
}

char getSign(double d){
  if(d>=0) return '+';
  else return '-';
}

void work(){
  double x1, y1, x2, y2, a1, a2, b1, b2, h, k, r, c, d, e;
  x1 = (xb+xc)/2; y1 = (yb+yc)/2;
  x2 = (xa+xb)/2; y2 = (ya+yb)/2;
  a1 = -1*(xc-xb)/(yc-yb);
  a2 = -1*(xb-xa)/(yb-ya);
  b1 = y1 - a1*x1;
  b2 = y2 - a2*x2;
  h = (b2-b1)/(a1-a2);
  k = ( a1*(b2-b1) + b1*(a1-a2) )/(a1-a2);
  r = sqrt( (xc-h)*(xc-h) + (yc-k)*(yc-k) );

  c = -2*h;
  d = -2*k;
  e = h*h + k*k - r*r;

  cout << "(x " << getSign(-h) << " ";
  if(h>=0) printf("%.3f", h);
  else  printf("%.3f", -h);
  cout << ")^2 + (y " << getSign(-k) << " ";
  if(k>=0) printf("%.3f", k);
  else  printf("%.3f", -k);
  cout << ")^2 = ";
  printf("%.3f", r);
  cout << "^2" << endl;

  cout << "x^2 + y^2 " << getSign(c) << " ";
  if(c>=0) printf("%.3f", c);
  else  printf("%.3f", -c);
  cout << "x " << getSign(d) << " ";
  if(d>=0) printf("%.3f", d);
  else  printf("%.3f", -d);
  cout << "y " << getSign(e) << " ";
  if(e>=0) printf("%.3f", e);
  else  printf("%.3f", -e);
  cout << " = 0" << endl;

}

main(){
  while(read()){
    work();
    cout << endl;
  }
}
// @end_of_source_code
