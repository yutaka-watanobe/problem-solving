#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
#define rep(i,n) for ( int i = 0; i < n; i++)
#define REP(i,s,t) for ( int i= s; i <= t; i++ )
#define MAX 5

class Frame{
public:
  int si, sj, ti, tj;
  Frame(int si=0, int sj=0, int ti=0, int tj=0):si(si), sj(sj), ti(ti), tj(tj){}
  bool operator < (const Frame &f) const{
    if ( si == f.si ) return sj < f.sj;
    return si < f.si;
  }
};

int H, W, G[MAX][MAX], limit;

class State{
public:
  int S[MAX][MAX], cost, nf;
  bool U[MAX*MAX*MAX*MAX];

  State(int cost=0, int nf=0):cost(cost), nf(nf){
    rep(i, nf) U[i] = false;
  }

  bool eq(){
    rep(i, H) rep(j, W) if ( G[i][j] != S[i][j] ) return false;
    return true;
  }

  int value(){
    int sum = 0, p = 1;
    rep(i, H) rep(j, W){
      if ( S[i][j] ) sum += p;
      p*=2;
    }
    return sum;
  }
  bool operator < ( const State &s) const{
    rep(i, H) rep(j, W){
      if ( S[i][j] == s.S[i][j] ) continue;
      return S[i][j] < s.S[i][j];
    }
    return false;
    /*
    rep(i, nf){
      if ( U[i] == s.U[i] ) continue;
      return U[i] < s.U[i];
      }*/
  }
};

int nframe;
Frame F[MAX*MAX*MAX*MAX];

int compute(){
  nframe = 0;
  rep(i, H) rep(j, W){
    for ( int k = i; k < H; k++ ){
      for ( int l = j; l < W; l++ ){
	F[nframe++] = Frame(i, j, k, l);
      }
    }
  }
  sort(F, F + nframe);

  State init = State(0, nframe);
  rep(i, H) rep(j, W) init.S[i][j] = 0;

  queue<State> Q;
  set<int> V;
  Q.push(init);
  V.insert(init.value());

  State u, v;
  while(!Q.empty()){
    u = Q.front(); Q.pop();
    if ( u.eq() ) return u.cost;

    for ( int i = 0; i < nframe; i++ ){
      v =u;
      if ( v.U[i] ) continue;

      int ui = F[i].si;
      bool fale = false;
      for ( int a = 0; a < ui; a++ ) rep(j, W) if (G[a][j] != v.S[a][j] ) fale = true;
      if ( fale ) continue;



      v.U[i] = true;
      REP(pi,F[i].si, F[i].ti) REP(pj, F[i].sj, F[i].tj) v.S[pi][pj] = (v.S[pi][pj]+1)%2;
      v.cost++;
      if ( V.find(v.value()) == V.end() ){
	V.insert(v.value());
	Q.push(v);
      }
    }
  }
}

main(){
  int n;
  while( cin >> n && n ){
    H = W = n;
    rep(i, H) rep(j, W) cin >> G[i][j];
    int cnt = compute();
    for ( int i = 0; i < cnt; i++ ) cout << "myon";
    cout << endl;
  }
}
