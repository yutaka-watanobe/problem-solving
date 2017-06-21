// 11360:Having Fun with Matrices:1.0:Matrix Simulation
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
#define MAX 50

void transpose(int G[MAX][MAX], int n){
  int T[MAX][MAX];
  rep(i, n) rep(j, n) T[i][j] = G[i][j];
  rep(i, n) rep(j, n) {
    G[j][i] = T[i][j];
  }
}

void inc(int G[MAX][MAX], int n ){
  rep(i, n) rep(j, n){
    G[i][j] = (G[i][j] + 1)%10;
  }
}

void dec(int G[MAX][MAX], int n ){
  rep(i, n) rep(j, n){
    G[i][j]--;
    if ( G[i][j] == -1 ) G[i][j] = 9;
  }
}

void row(int G[MAX][MAX], int n, int a, int b){
  int T[MAX];
  rep(i, n) T[i] = G[a][i];
  rep(i, n) G[a][i] = G[b][i];
  rep(i, n) G[b][i] = T[i];
}

void col(int G[MAX][MAX], int n, int a, int b){
  int T[MAX];
  rep(i, n) T[i] = G[i][a];
  rep(i, n) G[i][a] = G[i][b];
  rep(i, n) G[i][b] = T[i];
}

void simulate(){
  int n, m; cin >> n;
  int G[MAX][MAX];
  char ch;
  string com;
  int a, b;
  rep(i, n) rep(j, n){
    cin >> ch; G[i][j] = ch-'0';
  }
  cin >> m;
  rep(i, m){
    cin >> com;
    if ( com == "transpose" ) transpose(G, n);
    else if ( com == "inc" ) inc(G, n);
    else if ( com == "dec" ) dec(G, n);
    else if ( com == "row" ){
      cin >> a >> b; row(G, n, a-1, b-1);
    } else if ( com == "col" ){
      cin >> a >> b; col(G, n, a-1, b-1);
    }
  }
  rep(i, n){
    rep(j, n) cout << G[i][j];
    cout << endl;
  }
}

main(){
  int t; cin >> t;
  rep(i, t){
    cout << "Case #" << i+1 << endl;
    simulate();
    cout << endl;
  }
}

