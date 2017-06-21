#include <cmath>

using namespace std;

double bisection(double a, double b, double (f*)(double)){
  double c = (a+b) / 2.0;
  while(fabs(b-a) > EPS){
    if(f(a)*f(c) < 0)
      b = c;
    else if(f(b)*f(c) < 0)
      a = c;
    c = (a+b) / 2.0;
  }
  return c;
}

//*********************************************************
// simpson law
double numericalIntegration(double a, double b,
                            double (f*)(double), double dx){
  double s, t, m;
  s = t = m = 0;
  for(double x = a + dx; x <= b; x += dx){
    t += dx * (f(x-dx) + f(x)) / 2.0;
    m += dx * f((2 * x  - dx) / 2.0);
  }
  s = (t + 2.0 * m) / 3.0;

  return s;
}


// 関数 f(x) が単調連続で変曲点がなく、f'(x) が
// 数値的に求められるときに利用できる
//
// 任意の点 (X0, f(X0)) において、その接線と x 軸との交点
// を (X1, 0) とする。
// |f(X(n+1)) - f(Xn)| < ε になるまで計算し続ける
double newton(double cur,
              double (f*)(double), double (df*)(double)){
  double prev;
  do{
    prev = cur;
    cur  = prev - f(prev)/df(prev);
  }while(fabs(f(cur)-f(prev)) >= EPS);

  return cur;
}
