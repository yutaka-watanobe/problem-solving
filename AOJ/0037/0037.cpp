#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++)
#define N 5
int main(){
  bool G[N][N][4];
  char ch;
  rep(i, N) rep(j, N) rep(k, 4) G[i][j][k] = false;
  rep(i, 2*N-1){
    if (i%2){
      rep(j, N) {
	cin >> ch;
	if (ch == '1') G[(i+1)/2-1][j][3] = G[(i+1)/2][j][1] = true;
      }
    } else {
      rep(j, N-1) {
	cin >> ch;
	if (ch == '1') G[i/2][j][0] = G[i/2][j+1][2] = true;
      }
    }
  }
  
  string D = "RULD";
  int di[4] = {0, -1, 0, 1};
  int dj[4] = {1, 0, -1, 0};
  int pi = 0, pj = 0, dir = 0;
  
  while(1){
    if ( G[pi][pj][(dir+1)%4] ){
      dir = (dir+1)%4;
      pi += di[dir];
      pj += dj[dir];
      cout << D[dir];
    } else if ( G[pi][pj][dir] ){
      pi += di[dir];
      pj += dj[dir];
      cout << D[dir];
    } else dir = (dir+3)%4;
    if ( pi == 0 && pj == 0 ) break;
  }
  cout << endl;
}
