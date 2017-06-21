// 11362:Phone List:1.5:Sort
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
#define MAX 10000

bool valid(string source, string target ){
  if ( target.size() < source.size() ) return true;
  rep(i, source.size() ) if ( source[i] != target[i] ) return true;
  return false;
}

void compute(){
  int n;
  string N[MAX+1];
  cin >> n;
  rep(i, n) { cin >> N[i]; }
  sort(N, N + n );

  N[n] = "X";

  string target, source;
  rep(i, n){
    if ( !valid(N[i], N[i+1] ) ){
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}

main(){
  int t; cin >> t;
  rep(i, t) compute();
}
