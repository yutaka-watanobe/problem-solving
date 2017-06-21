#include<iostream>
#include<algorithm>
#include<queue>
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
  int n, cost, h;
  State(int n=0):n(n){cost= 0;}
  bool operator < ( const State &s) const{
    rep(i, n){
      if ( S[i] == s.S[i] ) continue;
      return S[i] < s.S[i];
    }
    return false;
  }
};
class QState{
public:
  State state;
  int cost;
  QState(){}
  QState(State state, short cost):state(state), cost(cost){}
  bool operator < ( const QState &q) const{
    return cost > q.cost;
  }
};

int n, limit;

short M[MAX][MAX], S[MAX], MD[(1<<MAX)];
int nframe;
Frame F[MAX*MAX*MAX*MAX];

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
int md(short S[MAX], int si ){
  int m = 0;
  for ( int i = si; i < n; i++ ){
    m = max(m, (int)MD[S[i]]);
  }
  return m;
}

int astar(){
  State source = State(n);
  rep(i, n) source.S[i] = S[i];
  source.h = md(source.S, 0);
  priority_queue<QState> PQ;
  PQ.push(QState(source, 0));
  set<State> V;
  V.insert(source);

  QState u;
  State v;
  while( !PQ.empty() ){
    u = PQ.top(); PQ.pop();
    if ( u.state.h == 0 ) return u.state.cost;
    rep(si, n) rep(sj, n) REP(ti, si, n-1) REP(tj, sj, n-1){
      v = u.state;
      REP(i, si, ti )  v.S[i] ^= M[sj][tj];
      if ( V.find(v) == V.end() ){
	V.insert(v);
	v.cost = u.state.cost+1;
	v.h = md(v.S, 0);
	PQ.push(QState(v, v.cost+v.h));
      }
    }
  }
  return -1;
}

int compute(){
  return astar();
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
