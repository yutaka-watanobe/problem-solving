// @JUDGE_ID:  17051CA  10649  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>

class DangerPoint{
 public:
  double D, x;

  bool read(){
    cin >> D >> x;
    if ( D == 0 && x == 0 ) return false;
    return true;
  }

  void work(){
    double ans;
    double R = D/2.0;
    bool valid = true;

    ans = sqrt(2*R*R - x*x);

    if ( D < 0 || x < 0 ) valid = false;
    if ( D*sqrt(2.0)/2 < x ) valid = false;

    if ( !valid ) cout << "INCORRECT INFORMATION !!!" << endl;
    else printf("%.6lf\n", ans);

  }

};

main(){
  DangerPoint DP;

  while ( DP.read() ){
    DP.work();
  }
}

// @end_of_source_code


