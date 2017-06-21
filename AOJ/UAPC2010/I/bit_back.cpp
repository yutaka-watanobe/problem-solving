#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++)
#define REP(i, b, e) for ( int i = b; i <= e; i++)
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

class State{
public:
  short S[MAX];
  int n;
  State(int n=0):n(n){}
  bool operator < ( const State &s)const{
    rep(i, n){
      if ( S[i] == s.S[i] ) continue;
      return S[i] < s.S[i];
    }
  }
};

int n, limit;

short M[MAX][MAX], S[MAX], MD[(1<<MAX)];
int nframe;
Frame F[MAX*MAX*MAX*MAX];
bool V[MAX][MAX][MAX][MAX];

set<State> VS;

void init(){
  rep(i, n) rep(j, n) M[i][j] = 0;
  REP(i, 0, n-1) REP(j, i, n-1 ){
    short base = (1<<(1+j-i))-1;
    M[i][j] = (base << i);
  }
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
  int m = 0;
  for ( int i = si; i < n; i++ ){
    m = max(m, (int)MD[S[i]]);
  }
  return m;
}

bool dfs(int pos, int cnt ){
  /*
  State s = State(n);
  rep(i, n) s.S[i] = S[i];
  VS.insert(s);
  */

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

  /*
 
 if ( sj ){
    if ( si == ti && sj == tj ){
      if ( V[si][sj-1][si][sj-1] && V[si][sj-1][si][sj] ) return false;
    }
    }*/


  REP(i,si,ti) S[i] ^= M[sj][tj];
  //V[si][sj][ti][tj] = true;

  //State v = State(n); 
  //rep(i, n) v.S[i] = S[i];

  //if (  VS.find(v) == VS.end()&&dfs(pos+1, cnt+1) ) return true;
  if ( dfs(pos+1, cnt+1) ) return true;
  REP(i,si,ti) S[i] ^= M[sj][tj];
  //V[si][sj][ti][tj] = false;

  //VS.erase(s);


  return false;
}

int compute(){
  
  nframe = 0;
  rep(i, n) rep(j, n){
    REP(k, i, n-1) REP(l, j, n-1){
      F[nframe++] = Frame(i, j, k, l);
    }
  }
  sort( F, F + nframe);

  for ( limit = md(0); limit <= 100; limit++ ){
    rep(i, n) rep(j, n) rep(k, n) rep(l, n) V[i][j][k][l] = false;
    VS.clear();
    if (dfs(0, 0)) return limit;
  }
  return -1;
}

main(){
  while( cin >> n && n ){
    init();
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
