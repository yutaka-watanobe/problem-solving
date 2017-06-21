#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i,n) for ( int i = 0; i < n; i++)
#define REP(i,s,t) for ( int i= s; i <= t; i++ )
#define MAX 5

class Frame{
public:
  int si, sj, ti, tj;
  Frame(int si=0, int sj=0, int ti=0, int tj=0):si(si), sj(sj), ti(ti), tj(tj){}
  bool operator < (const Frame &f) const{
    if ( si == f.si ) {
      if ( sj != f.sj ) {
	return sj < f.sj;
      } else {
	return ti-si < f.ti-f.si;
      }
    }
    return si < f.si;
  }
};


int H, W, limit;
bool S[MAX][MAX];

int nframe;
Frame F[MAX*MAX*MAX*MAX];
bool U[MAX*MAX*MAX*MAX];
bool V[MAX][MAX][MAX][MAX];



int md(int si ){
  int m = 0;
  int pre;
  int cnt = 0;
  for ( int i = si; i < H; i++ ){
    cnt = 0;
    int j = 0;
    while( j < W ){
      if ( S[j] ) {
	cnt++;
	while( j < W && S[j] ) j++;
      } else j++;
    }
    m = max(m, cnt);
  }

  return m;
}

bool dfs(int pos, int cnt ){

  int h = md(F[pos].si);
  if ( h == 0 ) return true;

  if ( pos == nframe) return false;
  if ( cnt + h > limit ) return false;
  if ( cnt  >= limit ) return false;

  

  //  for ( int j = sj-1; j >= 0; j-- ) if ( S[si][j] != G[si][j] ) return false;
  //  if ( si ) if (S[si-1][W-1] != G[si-1][W-1] ) return false;
  int si = F[pos].si;
  int sj = F[pos].sj;
  int ti = F[pos].ti;
  int tj = F[pos].tj;
  if ( sj ) if ( S[si][sj-1] ) return false;
  if ( sj == 0 && si ) if ( S[si-1][W-1] ) return false;



  if ( dfs(pos+1, cnt) ) return true;

 


  REP(i,si,ti) REP(j,sj,tj) S[i][j] ^= 1;// (S[i][j]+1)%2;
  U[pos] = true;
  V[si][sj][ti][tj] = true;
  if ( dfs(pos+1, cnt+1) ) return true;
  U[pos] = false;
  V[si][sj][ti][tj] = false;
  REP(i,si,ti) REP(j,sj,tj) S[i][j] ^= 1;//(S[i][j]+1)%2;

  return false;
}

int compute(){
  nframe = 0;
  rep(i, H) rep(j, W){
    for ( int k = i; k < H; k++ ){
      for ( int l = j; l < W; l++ ){
	F[nframe++] = Frame(i, j, k, l);
      }
    }
  }
  sort( F, F + nframe);

  for ( limit = md(0); limit <= 100; limit++ ){
    rep(i, nframe) U[i] = false;
    rep(i, H) rep(j, W) rep(k, H) rep(l, W) V[i][j][k][l] = false;
    if (dfs(0, 0)) {
      //        rep(i, nframe) if (U[i]) cout << F[i].si << "," << F[i].sj << "," << F[i].ti << "," << F[i].tj << endl;
      return limit;
    }
  }
  return -1;
}

main(){
  while( cin >> H && H ){
    W = H;
    rep(i, H) rep(j, W) cin >> S[i][j];
    cout << compute() << endl;
  }
}
