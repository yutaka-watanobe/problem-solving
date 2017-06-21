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

#define MAX (1<<10)

bool G[MAX][MAX], T[MAX][MAX];

bool isCube(int k, int &n){
  n = 0;
  for ( int i = 1; i <= 1024; i*=2, n++ )
    if ( k == i ) return true;
  return false;
}

int getID(map<int, int> &ID, int x, int &nnode){
  if ( ID.find(x) == ID.end() ){
    ID[x] = nnode++;
  }
  return ID[x];
}

void compute( int K, int M){
  int n, s, t;
  if ( !isCube(K, n) ){
    cout << "NO" << endl; return;
  }

  rep(i, K) rep(j, K) T[i][j] = G[i][j] = false;

  rep(u, K){
    rep(j, n){
      int v = (u ^ (1<<j));
      T[u][v] = 1;
    }
  }

  map<int, int> ID;
  int nnode = 0;

  rep(i, M){
    cin >> s >> t;
    s = getID(ID, s, nnode);
    t = getID(ID, t, nnode);
    cout << s << "-" << t << endl;
    G[s][t] = G[t][s] = 1;
  }

  rep(i, K) rep(j, K) if ( G[i][j] != T[i][j] ){
    cout << "NO" << endl; return;
  }
  cout << "YES" << endl;

  

  
グラフ 同型 判定

}

main(){
  int K, M;
  while( cin >> K >> M && K && M ){
    compute(K, M);
  }
}
