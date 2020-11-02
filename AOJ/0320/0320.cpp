#include<iostream>
using namespace std;
char G[1000][1000];
int N;

int next(int i){ return ((N - i - 1) + N) % N; }

bool getState(int i, int j){
  return  G[i][j] == G[i][next(j)] &&
    G[i][j] == G[next(i)][j] &&
    G[i][j] == G[next(i)][next(j)];
}

int getInit(){
  int dcnt = 0;
  for ( int i = 0; i < N / 2; i++ )
    for ( int j = 0; j < N / 2; j++ )
      if (!getState(i, j)) dcnt++;
  return dcnt;
}

int main(){
  int C, dcnt, ans = 0;
  cin >> C >> N;
  for ( int i = 0; i < N; i++ )
    for ( int j = 0; j < N; j++ )  cin >> G[i][j];
  
  dcnt = getInit();
  if (dcnt == 0 ) ans++;
  for ( int i = 0; i < C-1; i++ ){
    int k, r, c; cin >> k;
    for ( int j = 0; j < k; j++ ){
      cin >> r >> c; r--; c--;
      bool pre = getState(r, c);
      G[r][c] = G[r][c]=='1' ? '0' : '1';
      bool post = getState(r, c);
      if ( !pre && post ) dcnt--;
      else if ( pre && !post ) dcnt++;
    }
    if ( dcnt == 0 ) ans++;
  }
  
  cout << ans << endl;
  return 0;
}
