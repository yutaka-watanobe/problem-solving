#include<iostream>
#include<algorithm>
#include<cfloat>
using namespace std;

main(){
  double minv = FLT_MAX;
  double maxv = FLT_MIN;

  double x;
  while( cin >> x ){
    minv = min(minv, x );
    maxv = max(maxv, x );
  }

  printf("%.1lf\n", maxv - minv );
}
