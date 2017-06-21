#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

main(){
  int n;

  while( cin >> n && n != -1){
    double x = 1.0, y = 0.0, r = 1.0, th = 0;
    for ( int i = 1; i < n; i++ ){
      double r2 = sqrt(r*r+1);
      th += acos((r2*r2+r*r-1)/(2*r2*r));
      r = r2;
      x = r*cos(th);
      y = r*sin(th);
    }
    cout << x << endl << y << endl;
  }
}
