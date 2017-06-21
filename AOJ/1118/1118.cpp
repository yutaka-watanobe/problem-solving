#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++)
class Cube{
    public:
    int f[6];
    Cube(){}
    void roll_y(){ roll(0, 2, 5, 3);}
    void roll_x(){ roll(0, 1, 5, 4);}
    void roll(int i, int j, int k, int l){
	int t = f[i]; f[i] = f[j]; f[j] = f[k]; f[k] = f[l]; f[l] = t;
    }
  
  bool valid(){
    bool v[6];
    rep(i, 6) v[i] = false;
    rep(i, 6) if ( 1 <= f[i]  && f[i] <= 6 ) v[f[i]-1] = true;
    rep(i, 6) if ( !v[i] ) return false;
    return f[0]+f[5]==7 && f[1]+f[4]==7 && f[2]+f[3]==7;
  }
};

class State{
  public:
  int pi, pj;
  Cube cube;
  State(){}
  State(int pi, int pj):pi(pi),pj(pj){
    rep(i, 6) cube.f[i] = -1;
  }
  bool operator < ( const State &s) const{
    if ( pi != s.pi ) return pi < s.pi;
    if ( pj != s.pj ) return pj < s.pj;
    rep(i, 6){
      if ( cube.f[i] == s.cube.f[i] ) continue;
      return cube.f[i] < s.cube.f[i];
    }
    return false;
  }
};

int G[7][7];
set<State> V;

bool dfs(State u){
  u.cube.f[5] = G[u.pi][u.pj];
  if ( u.cube.valid() ) return true;
  V.insert(u);

  State v;
  int di[4] = {1, -1, 0, 0};
  int dj[4] = {0, 0, -1, 1};
  int dp[4] = {1, 4, 3, 2};
  rep(r, 4){
    if ( u.cube.f[dp[r]] == -1 && G[u.pi+di[r]][u.pj+dj[r]] ||
	 u.cube.f[dp[r]] == G[u.pi+di[r]][u.pj+dj[r]] ){
      v = u;
      v.pi += di[r]; v.pj += dj[r];
      if ( dp[r] == 1 ) rep(i, 3) v.cube.roll_x();
      if ( dp[r] == 4 ) v.cube.roll_x();
      if ( dp[r] == 3 ) v.cube.roll_y();
      if ( dp[r] == 2 ) rep(i, 3) v.cube.roll_y();
      if ( V.find(v) == V.end() && dfs(v) ) return true;
    }
  }
  return false;
}

bool valid(vector<int> d){
  if ( d.size() != 6 ) return false;
  sort(d.begin(), d.end());
  rep(i, 6)
    if ( i+1 != d[i] ) return false;
  return true;
}

main(){
  int tcase; cin >> tcase;
  rep(t, tcase){
    rep(i, 7) rep(j, 7) G[i][j] = 0;
    int si, sj;
    vector<int> d;
    for ( int i = 1; i <= 5; i++ ){
      for ( int j = 1; j <= 5; j++ ){
	cin >> G[i][j];
	if ( G[i][j] ) { 
	  si = i; sj = j; 
	  d.push_back(G[i][j]);
	}
      }
    }
    State s = State(si, sj);
    V.clear();
    if ( valid(d) && dfs(s) ) cout << "true" << endl;
    else cout << "false" << endl;
  }
}
