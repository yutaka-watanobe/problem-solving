// 11519:Logo 2:1.5:Simulation in Geom
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#include<cassert>

using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)
#define PI acos(-1)

void compute(){
  int n; cin >> n;
  double x = 0, y = 0;
  int degree = 0;
  string com;
  int val;
  rep(i, n){
    cin >> com  >> val;
    if ( com == "fd" || com == "bk"){
      if ( com == "bk" ) val *= -1;
      x += val*cos(degree*PI/180.0);
      y += val*sin(degree*PI/180.0);
    } else if ( com == "lt" ){
      degree = (degree + val)%360;
    } else if ( com == "rt" ){
      degree = (degree + 360 - (val%360))%360;
    }
  }
  double dist = sqrt(x*x+y*y);
  
  int disti = (int)(dist+0.5);
  cout << disti << endl;
}

main(){
  int t; cin >> t;
  rep(i, t) compute();
}
