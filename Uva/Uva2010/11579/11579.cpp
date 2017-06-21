// 11579:Triangle Trouble:1.5:Sort, Math
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<cmath>
#include<cassert>

using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)
#define MAX 10000

double getArea(double a, double b, double c){
  double s = (a + b + c)/2;
  //return sqrt(s*(s-a)*(s-b)*(s-c));
  return sqrt(s)*sqrt(s-a)*sqrt(s-b)*sqrt(s-c);
}

double compute(){
  double T[MAX];
  int n; cin >> n;
  rep(i, n) cin >> T[i];
  sort( T, T  + n );
  reverse(T, T + n);
  double maxv = 0;

  for ( int i = 0; i < n-2; i++ ){
    if ( T[i] < T[i+1] + T[i+2] ) maxv = max(maxv, getArea(T[i], T[i+1], T[i+2]));
  }
  return maxv;
}

main(){
  int t; cin >> t;
  rep(i, t) printf("%.2lf\n", compute());
}
