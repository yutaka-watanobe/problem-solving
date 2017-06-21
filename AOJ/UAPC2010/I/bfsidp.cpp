#include<iostream>
#include<queue>
#include<set>

#define rep(i, n) for ( int i = 0; i <(int)n;i++)
#define REP(i, b, e) for ( int i = b; i <= e; i++)
using namespace std;
#define MAX 5
#define INFTY (1<<8)

class Frame{
public:
  int si, sj, ti, tj;
  Frame(int si=0, int sj=0, int ti=0, int tj=0):si(si), sj(sj), ti(ti), tj(tj){}
  bool operator < (const Frame &f) const{
    if ( si == f.si ) {
      if ( sj != f.sj ) {
	return sj < f.sj;
      } else {
	if ( ti-si != f.ti-f.si )
	  return ti-si < f.ti-f.si;
	else
	  return tj-sj < f.tj-f.sj;
      }
    }
    return si < f.si;
  }
};


class State{
public:
  int H, W;
  bool S[MAX][MAX];
  State(int H=0, int W=0):H(H), W(W){
    rep(i, H) rep(j, W) S[i][j] = 0;
  }
  
  int getValue(){
    int p = 1, sum = 0;
    rep(i, H) rep(j, W) {
      if ( S[i][j] ) sum += p;
      p *= 2;
    }
    return sum;
  }
  bool operator < ( const State &s) const{
    rep(i, H) rep(j, W) {
      if ( S[i][j] == s.S[i][j] ) continue;
      return S[i][j] < s.S[i][j];
    }
    return false;
  }
};

int n, ans, limit;
bool G[MAX][MAX];
//int D[MAX+1][(1<<(MAX*((MAX+1)/2)))];
unsigned short D[MAX+1][(1<<(MAX*(MAX-1)))];

int nframe;
Frame F[MAX*MAX*MAX*MAX];

int md(int si, int sj ){
  /*
  if ( si == n/2 && sj == 0 ) {
    int v = 0;
    int p = 1;
    for ( int i = si; i < n; i++ ) {
      rep(j, n){
	if ( G[i][j] ) v += p;
	p += 2;
      }
    }
    return D[n][v];
    }*/

  int m = 0;
  int pre;
  int cnt = 0;
  bool X[MAX];

  for ( int i = si; i < n; i++ ){
    cnt = 0;
    int j = 0;
    while( j < n ){
      if ( G[i][j] ) {
	cnt++;
	while( j < n && G[i][j] ) j++;
      } else j++;
    }
    m = max(m, cnt);
  }
  /*
  for ( int j = 0; j < n; j++ ){
    cnt = 0;
    int i = 0;
    while( i < n){
      if ( G[i][j] ){
	cnt++;
	while( i < n && G[i][j] ) i++;
      } else i++;
    }
    m = max(m, cnt);
    }*/


  return m;
}

bool dfs(int pos, int cnt){
  //  bool suc = true;
  //  rep(i, n) rep(j, n) if ( G[i][j] ) { suc = false; break;}
  //  if ( suc ) return true;
  int h = md(F[pos].si, F[pos].sj);
  if ( h == 0 ) return true;
  if ( pos == nframe) return false;
  if ( cnt + h > limit ) return false;
  if ( cnt  >= limit ) return false;
  int si = F[pos].si;
  int sj = F[pos].sj;
  int ti = F[pos].ti;
  int tj = F[pos].tj;
  if ( sj ) if ( G[si][sj-1] ) return false;
  if ( sj == 0 && si ) if ( G[si-1][n-1]) return false;

  /*
  if ( si == n/2 ){
    ans = min(ans, cnt + md(F[pos].si, F[pos].sj) );
    return false;
    }*/


  if ( dfs(pos+1, cnt) ) return true;

  REP(i,si,ti) REP(j,sj,tj) G[i][j] ^= 1;
  if ( dfs(pos+1, cnt+1) ) return true;
  REP(i,si,ti) REP(j,sj,tj) G[i][j] ^= 1;

  return false;
}


void bfs(int nn){
    int H = (nn+1)/2, W = nn;
    //int H = (nn-1), W = nn;
  State init = State(H, W);
  /*
  rep(i, H*W){
    init.S[i/W][i%W] = p%2;
    p /= 2;
    }*/

  /*
  cout << "bfs  " << value<< endl;
  cout << init.getValue() << endl;
  rep(i, H) {
    rep(j, W){
      cout << init.S[i][j] << " ";;
    }
    cout << endl;
    }*/

  queue<State> Q;

  rep(i, (1<<(nn*((nn+1)/2))) ) D[nn][i] = INFTY;
  D[nn][init.getValue()] = 0;
  Q.push(init);
  State u, v;
  while( !Q.empty() ){
    u = Q.front(); Q.pop();
    rep(si, H) rep(sj, W) REP(ti, si, H-1) REP(tj, sj, W-1){
      v = u;
      REP(i, si, ti ) REP(j, sj, tj) v.S[i][j] ^= 1;
      if ( D[nn][v.getValue()] == INFTY ){
	D[nn][v.getValue()] = D[nn][u.getValue()] + 1;
	Q.push(v);
      }
    }
  }
}

int compute(){
  nframe = 0;
  rep(i, n) rep(j, n){
    for ( int k = i; k < n; k++ ){
      for ( int l = j; l < n; l++ ){
	F[nframe++] = Frame(i, j, k, l);
      }
    }
  }
  sort( F, F + nframe);

  ans = INFTY;
  for ( limit = md(0, 0); limit <= 100; limit++ ){
    //rep(i, nframe) U[i] = false;
    if (dfs(0, 0)) {
      return limit;
    }
  }
  return ans;
  return -1;
}

main(){
  REP(i, 1, MAX) bfs(i);
  while( cin >> n && n ){
    rep(i, n) rep(j, n) cin >> G[i][j];

    cout << compute() << endl;

    /*
    rep(k, (1<<(n*((n+1)/2))) ){
      cout << k << "  " << D[k] << endl;
      int p = k;
      rep(i, (n+1)/2){
	rep(j, n){
	  cout << p%2 << " ";
	  p/= 2;
	}
	cout << endl;
      }
    }

    */

    

  }
}
