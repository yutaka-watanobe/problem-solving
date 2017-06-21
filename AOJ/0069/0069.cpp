/** 
 * simulation
 */
#include<iostream>
using namespace std;
static const int MAX = 50;
#define rep(i, n) for ( int i = 0; i < n; i++ )

char G[MAX][MAX];
int n, m, d, t;

bool solved(){
  int T[MAX];
  rep(i, n) T[i] = 0;
  T[m-1] = 1;
  rep(i, d){
    rep(j, n-1){
      if ( G[i][j] == '1' ) swap(T[j], T[j+1]);
    }
  }
  int p = -1;
  rep(i, n) if ( T[i] ) p = i;
  return p == t-1;
}

void compute(){
  if ( solved() ){
    cout << 0 << endl; return;
  }
  rep(i, d) rep(j, n-1){
    if ( G[i][j] == '1' ) continue;
    if ( j > 0 && G[i][j-1] == '1' ) continue;
    if ( j < n-1 && G[i][j+1] == '1' ) continue;
    G[i][j] = '1';
    if ( solved() ){
      cout << i+1 << " " << j+1 << endl;
      return;
    }
    G[i][j] = '0';
  }
  cout << 1 << endl;
}

main(){
  while(1){
    cin >> n;
    if ( n == 0 ) break;
    cin >> m >> t >> d;
    rep(i, d) rep(j, n-1) cin >> G[i][j];
    compute();
  }
}
