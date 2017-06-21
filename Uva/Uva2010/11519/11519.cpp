
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
#define EPS 1e-8

double simulate(vector<pair<string, string> > &comList, int type, int guess){
  int n = comList.size();
  double x = 0, y = 0;
  int degree = 0;
  string com;
  int val;
  rep(i, n){

    if ( comList[i].second == "?" ){
      if ( type == 0 ) {
	val = 0;
	com = comList[i].first;
	continue;
      } else {
	com = comList[i].first;
	val = guess;
      }
    } else {
      com = comList[i].first;
      val = atoi(comList[i].second.c_str());
    }

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
  return dist;
  //  int disti = (int)(dist+0.5);
  //  return disti;
}

void compute(){
  string s1, s2;
  vector<pair<string, string> > com;
  int n; cin >> n;
  int type = 0; // 0: walk 1: rotate

  rep(i, n){
    cin >> s1 >> s2;
    if ( s2 == "?" ){
      if ( s1 == "fd" || s1 == "bk" ) type = 0;
      else type = 1;
    }
    com.push_back(make_pair(s1, s2));

  }

  if ( type == 0 ){
    cout << simulate(com, 0, -1) << endl;
  } else {
    rep(i, 360){
      double d = simulate(com, 1, i);
      if ( d < EPS ){
	cout << i << endl;
	return;
      }
    }
    // assert(false);
    cout << endl;
  }

}

main(){
  int t; cin >> t;
  rep(i, t) compute();
}
