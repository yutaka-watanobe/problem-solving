// 10991:Region:1.0:Math Geometry
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>

using namespace std;

#define PI acos(-1)
#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)

main(){
  int tcase; cin >> tcase;
  double R1, R2, R3, a, b, c, s, T, A, B, C, O1, O2, O3, G;
  rep(t, tcase){
    cin >> R1 >> R2 >> R3;
    a = R2 + R3;
    b = R1 + R3;
    c = R1 + R2;
    s = (a + b + c)/2.0;
    T = sqrt(s*(s-a)*(s-b)*(s-c));
    A = acos((c*c+b*b-a*a)/(2*c*b));
    B = acos((c*c+a*a-b*b)/(2*c*a));
    C = acos((a*a+b*b-c*c)/(2*a*b));

    O1 = R1*R1*A/2;
    O2 = R2*R2*B/2;
    O3 = R3*R3*C/2;
    G = T - (O1+O2+O3);
    printf("%.6lf\n", G);

  }
}
