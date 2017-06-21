#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
#define rep(i, n) for ( int i = 0; i < (int)n; i++)
#define MAX 10

int maxw;
int cnt, H, W;
int T[MAX][MAX], K[MAX][MAX], X[MAX][MAX];
bool C[MAX][MAX];

class State{
public:
  int n;
  pair<int, int> v[MAX*MAX];
  bool used[MAX*MAX];
  int A[MAX][MAX];
  int X[MAX][MAX];
  State(){}
  State(int n):n(n){
    rep(i, n ) used[i] = false;
    rep(i, H) rep(j, W) A[i][j] = X[i][j] = 0;
  }
  bool operator < ( const State &s)const{
    /*
    rep(i, H) rep(j, W){
      if ( C[i][j] == s.C[i][j] ) continue;
      return C[i][j] < s.C[i][j];
    }
    return false;
    */
    for ( int i = 0; i < n; i++ ){
      if ( used[i] == s.used[i] ) continue;
      return used[i] < s.used[i];
    }
    return false;
  }

  bool select(int p){
    int pi = v[p].first;
    int pj = v[p].second;
    int w = T[pi][pj];
    bool checked = false;
    for ( int i = pi; i >= pi-w+1; i--){
      for ( int j = pj; j >= pj-w+1; j--) {
	X[i][j]++;
	//	if ( C[i][j] ) checked = true;
	//	C[i][j] = false;
	//	A[i][j]++;
      }
    }
    used[p] = true;

    rep(i, n){
      bool all2 = true;
      if ( !used[i] ) continue;
      pi = v[i].first;
      pj = v[i].second;
      w = T[pi][pj];
      for ( int y = pi; y >= pi-w+1; y--){
	for ( int x = pj; x >= pj-w+1; x--){
	  if ( X[y][x] <= 1 ) all2 = false;
	}
      }
      if ( all2 ) { return false;}
    }

    //    return checked;
    return true;
  }

  bool check(){
    rep(i, H) rep(j, W){
      if ( C[i][j] && X[i][j] == 0 ) return false;
    }
    return true;
  }
  int cost(){
    int sum = 0;
    for ( int i = 0; i < n; i++ )
      if ( used[i] ) sum++;
    return sum;
  }

  int md(){
    int sum = 0;
    rep(i, H) rep(j, W){
      if ( C[i][j] && X[i][j] == 0 ) sum++;
    }
    return sum/(maxw*maxw);
  }
};

class QState{
public:
  State s;
  int dist;
  QState(){}
  QState(State s, int dist):s(s), dist(dist){}
  bool operator < ( const QState &q)const{
    return dist > q.dist;
  }
};

vector<pair<int, int> > compute(){
  
  bool U[MAX][MAX];
  bool V[MAX][MAX];

  rep(i, H) rep(j, W) U[i][j] = true;
  rep(i, H) rep(j, W) V[i][j] = false;
  rep(i, H) rep(j, W) T[i][j] = K[i][j] = X[i][j] = 0;
  rep(i, H) T[i][0] = (C[i][0])?1:0;
  rep(j, W) T[0][j] = (C[0][j])?1:0;
  for ( int i = 1; i < H; i++ ){
    for ( int j = 1; j < W; j++ ){
      if ( C[i][j] ){
	T[i][j] = min(T[i-1][j-1], min(T[i-1][j], T[i][j-1])) +1;
      } else T[i][j] = 0;
    }
  }

  rep(i, H) rep(j, W){
    int w = T[i][j];
    for ( int pi=i; pi >= i-(w-1); pi--){
      for ( int pj=j; pj >= j-(w-1); pj--){
	if ( i == pi && j == pj ) continue;
	int l = max(i-pi, j-pj);
	if ( w-l >= T[pi][pj] ) U[pi][pj] = false;
      }
    }
  }

  rep(i, H) rep(j, W){
    if ( U[i][j] && T[i][j] ){
      for ( int y = i; y >= i-T[i][j]+1; y--){
	for ( int x = j; x >= j-T[i][j]+1; x--) K[y][x]++;
      }
    }
  }

  vector<pair<int, int> > v;
  rep(i, H) rep(j, W){
    if ( U[i][j] && T[i][j] ){
      //      v.push_back(make_pair(i, j));
      bool f = false;
      for ( int y = i; y >= i-T[i][j]+1; y--){
      	for ( int x = j; x >= j-T[i][j]+1; x--) {
      	  if ( K[y][x] == 1 ) f = true;
      	}
      }
      if ( f ){
	for ( int y = i; y >= i-T[i][j]+1; y--){
	  for ( int x = j; x >= j-T[i][j]+1; x--) {
	    X[y][x]++;
	  }
	}
	cnt++;
	T[i][j] = 0;
      }
    }
  }

  maxw = 0;
  rep(i, H) rep(j, W){
    if ( T[i][j] > 0 && U[i][j])maxw = max(maxw, T[i][j]);
  }

 rep(i, H) rep(j, W){
    if ( U[i][j] && T[i][j] ){
      v.push_back(make_pair(i, j));
    }
 }

  return v;

}

int bfs(vector<pair<int, int> > v){
  vector<pair<int, int> > vv;
  for ( int i = 0; i < v.size(); i++ ) vv.push_back(v[i]);
  //  for ( int i = 1; i < v.size(); i+=2 ) vv.push_back(v[i]);

  int n = v.size();
  //  State s = State(v.size());
  State s = State(v.size());
  rep(i, v.size()) s.v[i] = vv[i];
  rep(i, H) rep(j, W) s.X[i][j] = X[i][j];

  set<State> V;
  V.insert(s);
  priority_queue<QState> Q;
  Q.push(QState(s, 0));
  QState qs;
  State u, nex;
  while(!Q.empty()){
    qs = Q.top(); Q.pop();
    u = qs.s;
    //    cout << Q.size() << endl;
    if ( u.check() ) return u.cost();

    for ( int i = 0; i < n; i++ ){
      if ( u.used[i] ) continue;
      nex = u;
      if ( !nex.select(i) ) continue;
      if ( V.find(nex) == V.end() ){
	V.insert(nex);
	Q.push(QState(nex, nex.cost() + nex.md()));
      }
    }
  }
  return -1;
}

main(){
  while( cin >> W >> H ){
    if ( W == 0 && H == 0 ) break;
    rep(i, H) rep(j, W) cin >> C[i][j];
    cnt = 0;
    cout << bfs( compute()) + cnt<< endl;
  }
}

