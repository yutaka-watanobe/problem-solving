// 11729:Commando War:1.5:Sort + Greedy
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<cmath>
#include<cassert>

using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)

#define MAX 1000

class Soldier{
public:
  int btime, ttime;
  Soldier(int b=0, int t=0):btime(b), ttime(t){}

  bool operator < ( const Soldier &s) const{
    return ttime > s.ttime;
  }
};

main(){
  int n, t = 1;
  Soldier S[MAX];
  while( cin >> n && n ){
    int cur = 0, ans = 0;

    rep(i, n){ cin >> S[i].btime >> S[i].ttime; }
    sort( S, S + n );
    
    rep(i, n){
      cur += S[i].btime;
      ans = max(ans, cur + S[i].ttime);
    }
    
    cout << "Case " << t << ": " << ans << endl;
    t++;
  }
}

