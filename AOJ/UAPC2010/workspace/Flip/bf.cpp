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

int getValue(){
  int v = 0;
  int p = 1;
  for ( int i = 1; i < n; i++ ) {
    rep(j, n){
      if ( G[i][j] ) v += p;
      p *= 2;
    }
  }
  return v;
}

int md(int si, int sj ){
  //if ( si == n/2 && sj == 0 ) {

  /*
  if ( si == 1 && sj == 0 ) {
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

void dfs(int pos, int cnt ){
  
  if ( cnt > 8 ) return;
  if ( cnt > ans ) return;

  if ( pos == nframe ){
    //    ans = min(ans,cnt+ D[n][getValue()]);
    ans = min(ans, cnt + D[n][getValue()]);
    return;
  }

  int si = F[pos].si;
  int sj = F[pos].sj;
  int ti = F[pos].ti;
  int tj = F[pos].tj;
  if ( sj && G[si][sj-1] ) return;


  dfs(pos+1, cnt);

  REP(i,si,ti) REP(j,sj,tj) G[i][j] ^= 1;
  dfs(pos+1, cnt+1);
  REP(i,si,ti) REP(j,sj,tj) G[i][j] ^= 1;

}


void bfs(int nn){
  //  int H = (nn+1)/2, W = nn;
  int H = (nn-1), W = nn;
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

  //  rep(i, (1<<(n*((n+1)/2))) ) D[nn][i] = INFTY;
  rep(i, (1<<(nn*(nn-1))) ) D[nn][i] = INFTY;
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
  rep(i, 1) rep(j, n){
    for ( int k = i; k < n; k++ ){
      for ( int l = j; l < n; l++ ){
	F[nframe++] = Frame(i, j, k, l);
      }
    }
  }
  sort( F, F + nframe);

  ans = INFTY;
  dfs(0, 0);
  return ans;
}

main(){
  REP(i, 1, MAX) {
    bfs(i);
    cout << "end of bfs " << i << endl;
  }
  while( cin >> n && n ){
    rep(i, n) rep(j, n) cin >> G[i][j];

    cout << compute() << endl;
    
    /*
    rep(k, (1<<(n*(n-1))) ){
      cout << k << "  " << D[n][k] << endl;
      int p = k;
      rep(i, n-1){
	rep(j, n){
	  cout << p%2 << " ";
	  p/= 2;
	}
	cout << endl;
      }
      }*/

    

  }
}
