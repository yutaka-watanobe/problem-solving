// 11715:Car:0.5:Writing Physics
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>

using namespace std;

#define rep(i, n) for ( int i = 0; i < (int)n; i++)

main(){
  int type;
  double u, v, t, s, a;
  int tcase = 1;
  while( cin >> type && type ){
    cout << "Case " << tcase << ": ";
    if ( type == 1 ){
      cin >> u >> v >> t;
      a = (v-u)/t;
      s = u*t + a*t*t/2;
      printf("%.3lf %.3lf", s, a);
    } else if ( type == 2 ){
      cin >> u >> v >> a;
      t = (v-u)/a;
      s = u*t + a*t*t/2;
      printf("%.3lf %.3lf", s, t);
    } else if ( type == 3 ){
      cin >> u >> a >> s;
      v = sqrt(u*u+2*a*s);
      t = (v-u)/a;
      printf("%.3lf %.3lf", v, t);
    } else if ( type == 4 ){
      cin >> v >> a >> s;
      u = sqrt(v*v-2*a*s);
      t = (v-u)/a;
      printf("%.3lf %.3lf", u, t);
    }
    cout << endl;
    tcase++;
  }
}
