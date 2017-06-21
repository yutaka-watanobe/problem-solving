// 11703:sqrt log sin:0.5:Writing
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
#define MAX 1000001
#define M 1000000
main(){
  int T[MAX];
  T[0] = 1;
  for ( int i = 1; i <= MAX; i++ ){
    T[i] = ((T[(int)(i-sqrt(i))] + T[(int)(log(i))])%M + T[(int)((i*sin(i)*sin(i)))])%M;
  }
  int n;
  while(1){
    cin >> n;
    if ( n < 0 ) break;
    cout << T[n] << endl;
  }
}
