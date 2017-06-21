// 11588:Image Coding:1.0:Writing
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
#define MAX 50
int compute(){
  int H, W, M, N, C[26];
  char G[MAX][MAX];

  rep(i, 26) C[i] = 0;

  cin >> H >> W >> M >> N;

  rep(i, H) rep(j, W){
    cin >> G[i][j];
    C[G[i][j]-'A']++;
  }

  int maxv = 0;
  rep(i, 26) maxv = max(maxv, C[i]);

  

  int size = 0;
  rep(i, H) rep(j, W){
    if ( C[G[i][j]-'A'] == maxv ) size += M;
    else size += N;
  }
  
  return size;
}

main(){
  int t; cin >> t;
  rep(i, t){
    cout << "Case " << i+1 << ": " << compute() << endl;
  }
}
