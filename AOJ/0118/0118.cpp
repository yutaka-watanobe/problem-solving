#include<iostream>
using namespace std;

#define MAX 100

char G[MAX+2][MAX+2];
int H, W;
bool V[MAX+2][MAX+2];

void dfs( int i, int j , char ch){
  V[i][j] = true;
  int di[4] = {0, -1, 0, 1};
  int dj[4] = {1, 0, -1, 0};
  int ni, nj;
  for ( int r = 0; r < 4; r++ ){
    ni = i + di[r];
    nj = j + dj[r];
    if ( !V[ni][nj] && G[ni][nj] == ch ) dfs(ni, nj, ch);
  }
}
main(){
  while(1){
    cin >> H >> W;
    if ( H == 0 && W== 0 ) break;
    for ( int i = 0; i < H + 2; i++ )
      for ( int j = 0; j < W + 2; j++ ) G[i][j] = '.';

    for ( int i = 1; i <= H; i++ )
      for ( int j = 1; j <= W; j++ ) cin >> G[i][j];

    for ( int i = 1; i <= H; i++ )
      for ( int j = 1; j <= W; j++ ) V[i][j] = false;

    int cnt = 0;

    for ( int i = 1; i <= H; i++ ){
      for ( int j = 1; j <= W; j++ ){
	if ( !V[i][j] ){
	  cnt++;
	  dfs(i, j, G[i][j] );
	}
      }
    }
    cout << cnt << endl;
    
  }
}
