// 11292:The Dragon of Loowater:1.5:Sort + Greedy
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#include<cassert>
#include<climits>
using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)

#define MAX 20000

int compute(int n, int m){
  int H[MAX], S[MAX];
  rep(i, n) cin >> H[i];
  rep(i, m) cin >> S[i];
  sort(H, H + n);
  sort(S, S + m);
  
  S[m++] = INT_MAX;

  int cost = 0;
  int curs = 0, curh = 0;
  
  for ( curh = 0; curh < n; curh++ ){
    while( H[curh] > S[curs] ) curs++;
    if ( curs == m-1 ) return -1;
    cost += S[curs];
    curs++;
  }
  return cost;

}

main(){
  int n, m;
  while( cin >> n >> m && n && m ){
    int cost = compute(n, m);
    if ( cost < 0 ) cout << "Loowater is doomed!" << endl;
    else cout << cost << endl;
  }
}
