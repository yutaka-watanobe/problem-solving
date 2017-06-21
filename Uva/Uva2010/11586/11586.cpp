// 11586:Train Tracks:1.0:Count
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#include<cassert>
#include<sstream>
using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)

void compute(){
  string line;
  getline(cin, line);
  stringstream sin(line);
  string con;
  int n = 0;
  int f = 0, m = 0;
  while( sin >> con ){
    n++;
    rep(i, 2){
      if ( con[i] == 'F' ) f++;
      else m++;
    }
  } 

  if ( n == 1 || f != m ) cout << "NO LOOP" << endl;
  else cout << "LOOP" << endl;
}

main(){
  int t; cin>> t;
  string line; getline(cin, line);
  rep(i, t) compute();
}
