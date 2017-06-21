#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++)
static const int MAX = 30;
int H, W, N;
char G[MAX][MAX], T[MAX][MAX];

bool isSolved(){
  rep(i, H) rep(j, W) if ( T[i][j] != '.' ) return false;
  return true;
}

bool remove(){
  bool rem = false;
  bool R[MAX][MAX];
  rep(i, H) rep(j, W) R[i][j] = false;
  rep(i, H){
    int j = 0;
    int cnt = 1;
    while( j < W ){
      int s = j;
      while( j+1 < W && T[i][j] == T[i][j+1] ){ j++; cnt++;}
      if ( cnt >= N ){
	rem = true;
	for ( int k = s; k < s+cnt; k++ ) R[i][k] = true;
      }
      j++; cnt = 1;
    }
  }

  rep(j, W){
    int i = 0;
    int cnt = 1;
    while( i < H ){
      int s = i;
      while( i+1 < H && T[i][j] == T[i+1][j] ){ i++; cnt++;}
      if ( cnt >= N ){
	rem = true;
	for ( int k = s; k < s+cnt; k++ ) R[k][j] = true;
      }
      i++; cnt = 1;
    }
  }
  rep(i, H) rep(j, W) if ( R[i][j] ) T[i][j] = '.';

  return rem;
}

bool down(){
  int m = 0;
  while(1){
    bool moved = false;
    for ( int i = H-1; i >= 1; i-- ){
      rep(j, W){
	if ( T[i][j] == '.' && T[i-1][j] != '.' ){
	  moved = true;
	  m++;
	  swap(T[i][j], T[i-1][j]);
	}
      }
    }
    if ( !moved) break;
  }
  return m > 0;
}

bool solve(){
  down();
  while(1){
    if (!remove()) break;
    if (!down()) break;
  }
  return isSolved();
}

main(){
  cin >> H >> W >> N;
  rep(i, H) rep(j, W ) cin >> G[i][j];
  bool suc = false;
  rep(i, H) rep(j, W-1 ) {
    rep(a, H) rep(b, W ) T[a][b] = G[a][b];
    swap(T[i][j], T[i][j+1]);
    if ( solve() ){
      suc = true;
      break;
    }
  }
  cout << (suc?"YES":"NO") << endl;
}
