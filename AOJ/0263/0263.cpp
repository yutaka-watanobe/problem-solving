#include<iostream>
#include<algorithm>
#define REP(i, b, e) for ( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)
using namespace std;
static const int NMAX = 32; // can be more
static const int MMAX = 32; 
int A[NMAX+1], T[MMAX], dp[2][1<<16], ST[MMAX][1<<16];

int getScore(int v){
    int sum = 0;
    rep(i, 16) if ( v & (1<<i)) sum++;
    return sum;
}

int main(){
  int N, M, b;
  int tcase = 0;
  while(1){
      cin >> N >> M;
      if ( N == 0 && M == 0 ) break;
      tcase++;
      rep(i, N+1) A[i] = 0;
      REP(i, 1, N+1) rep(j, 16){
	  cin >> b;      
	  if ( b ) A[i] += (1<<j);
      }
      rep(i, M) T[i] = 0;
      rep(i, M) rep(j, 16){
	  cin >> b;
	  if ( b ) T[i] += (1<<j);
      }

      rep(j, (1<<16)) dp[0][j] = dp[1][j] = -1;
      rep(i, M) rep(j, (1<<16)) ST[i][j] = getScore( T[i] & j );
      dp[0][0] = 0;
      
      rep(i, N) rep(j, (1<<16) ){
	  if ( dp[i%2][j] < 0 ) continue;
	  int nx = (j | A[i+1]);
	  dp[(i+1)%2][nx] = max(dp[(i+1)%2][nx], dp[i%2][j]);
	  rep(k, M){
	      int tx = (nx - (nx & T[k]));
	      dp[(i+1)%2][tx] = max(dp[(i+1)%2][tx], dp[i%2][j] + ST[k][nx]);
	  }
      }
      
      int maxv = 0;
      rep(j, (1<<16)) maxv = max(maxv, dp[N%2][j]);

      cout << maxv << endl;
  }
  return 0;
}
