// 10566:Crossed Ladders:2.5:Bisection Method
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>

using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)
#define EPS 0.00000001

double compute(double x, double y, double c ){
  double a, b, d, cc;
  double l = EPS;
  double r = min(x, y)-EPS;
  
  while(1){
    d = (l + r )/2.0;
    a = sqrt(x*x-d*d);
    b = sqrt(y*y-d*d);
    cc = a*b/(a+b);

    if ( fabs(cc - c) < EPS ) return d;
    if ( cc < c ) r = d;
    else l = d;
  }
}


main(){
  double x, y, c;
  while( cin >> x >> y >> c ) printf("%.3lf\n", compute(x, y, c));
}
