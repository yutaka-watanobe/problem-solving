#include<iostream>
#include<cstdio>
using namespace std;

main(){
  int a, t, r;
  cin >> a >> t >> r;
  double elapse = (1.0 * t / a) * r; // 経過時間
  printf("%.8lf\n", elapse);
}
