#include<cstdio>
#include<cmath>
using namespace std;
main(){
  double a, b, s, m, n;
  while(1){
    scanf("%lf %lf %lf %lf %lf", &a, &b, &s, &m, &n);
    if ( a == 0 && b == 0 ) break;
    printf("%.2lf %.2lf\n", atan((b*n)/(a*m))*(180/acos(-1)), sqrt(b*n*b*n+a*m*a*m)/s);
  }
}
