#include<iostream>
#include<algorithm>
#include<set>
#include<queue>
#include<cassert>
using namespace std;
#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)
#define MAX 5
#define INFTY (1<<10)

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

class State{
public:
  int n;
  short S[MAX-1];
  State(int n=0): n(n){ rep(i, n-1) S[i] = 0; }
  
  int getValue(){
    int sum = 0;
    rep(i, n-1){
      sum = (sum << n) + S[i];
    }
    return sum;
  }

  bool operator < ( const State &s) const{
    rep(i, n-1){
      if ( S[i] == s.S[i] ) continue;
      return S[i] < s.S[i];
    }
    return false;
  }
};

int limit;
int n;
short D[MAX+1][(1<<(MAX*(MAX-1)))], S[MAX], M[MAX][MAX], MD[(1<<MAX)];
int nframe;
Frame F[MAX*MAX*MAX*MAX];

void bfs(int h){
  State init = State(h);
  queue<State> Q;
  Q.push(init);
  rep(i, (1<< (h*(h-1))) ) D[h][i] = INFTY;
  D[h][init.getValue()] = 0;

  State u, v;
  int value, uvalue;
  while( !Q.empty() ){
    u = Q.front(); Q.pop();
    uvalue = u.getValue();
    rep(si, h-1) rep(sj, h) REP(ti, si, h-1) REP(tj, sj, h){
      v = u;
      REP(i, si, ti+1) v.S[i] ^= M[sj][tj];
      value = v.getValue();
      if ( D[h][value] == INFTY ){
	D[h][value] = D[h][uvalue] + 1;
	Q.push(v);
      }
    }
  }
}

void init(){ 
  rep(i, MAX) rep(j, MAX) M[i][j] = 0;
  REP(i, 0, MAX) REP(j, i, MAX ){
    short base = (1<<(1+j-i))-1;
    M[i][j] = (base << i);
  }

  REP(h, 1, MAX+1) bfs(h);
}

void initMD(){
  rep(i, (1<<n)) {
    bool bit[MAX];
    int v = i;
    rep(j, n){ bit[j] = v%2; v /= 2; }
    int cnt = 0, j = 0;
    while( j < n ){
      if ( bit[j] ){
	cnt++;
	while( j < n && bit[j] ) j++;
      } else j++;
    }
    MD[i] = cnt;
  }
}

int md(int si ){
  if ( si == 0 ){
    int sum = 0;
    for ( int i = 1; i < n; i++ ){
      sum = (sum<<n) + S[i];
    }
    return max( D[n][sum], MD[S[0]]);
  }

  int m = 0;
  for ( int i = si; i < n; i++ ){
    m = max(m, (int)MD[S[i]]);
  }
  return m;
}

bool dfs(int pos, int cnt ){
 int h = md(F[pos].si);
  if ( h == 0 ) return true;
  if ( pos == nframe) { return false; }
  if ( cnt + h > limit || cnt >= limit) { return false; }
  int si = F[pos].si;
  int sj = F[pos].sj;
  int ti = F[pos].ti;
  int tj = F[pos].tj;
  if ( sj ) if ( S[si]&(1<<(sj-1)) ) { return false; }
  if ( sj == 0 && si ) if ( S[si-1]&((1<<(n-1))) ) {  return false;}

  if ( dfs(pos+1, cnt) ) return true;

  REP(i,si,ti+1) S[i] ^= M[sj][tj];
  if ( dfs(pos+1, cnt+1) ) return true;
  REP(i,si,ti+1) S[i] ^= M[sj][tj];
  return false;
}

int compute(){
  nframe = 0;
  rep(i, n) rep(j, n){
    REP(k, i, n) REP(l, j, n){
      F[nframe++] = Frame(i, j, k, l);
    }
  }
  sort( F, F + nframe);

  for ( limit = 0; limit <= 100; limit++ ){
    if (dfs(0, 0)) return limit;
  }
  return -1;
}

main(){
  init();
  while( cin >> n && n ){
    initMD();
    int v, p, b;
    
    rep(i, n){
      v = 0;
      p = 1;
      rep(j, n) {
	cin >> b; 
	if ( b ) v += p;
	p *= 2;
      }
      S[i] = v;
    }
    cout << compute() << endl;
  }
}
