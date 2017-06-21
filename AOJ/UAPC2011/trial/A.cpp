#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

main(){
  double x1, x2, y1, y2, z1, z2;
  int n;
  cin >> n;
  for ( int i = 0; i < n; i++ ){
    cin >> x1 >> y1 >> z1;
    cin >> x2 >> y2 >> z2;

    double d = sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));

    printf("%.8lf\n", d);
  }
}
