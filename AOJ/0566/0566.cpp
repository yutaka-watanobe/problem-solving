#include<iostream>
#include<algorithm>
using namespace std;
#define REP(i, b, e) for ( int i = b; i < (int)e; i++ )
#define rep(i, n) REP(i, 0, n)
static const int MAX = 100;

main(){
  int N, s, t, ps, pt;
  int R[MAX];
  pair<int, int> S[MAX];
  cin >> N;
  rep(i, N) { S[i].first = 0; S[i].second = i; }
  rep(i, N*(N-1)/2){
    cin >> s >> t >> ps >> pt; s--; t--; // to 0 base
    if ( ps > pt ) S[s].first += 3;
    else if ( ps < pt ) S[t].first += 3;
    else { S[t].first++; S[s].first++; }
  }
  
  sort(S, S + N);
  reverse(S, S + N);

  int r = 1;
  R[S[0].second] = r;
  REP(i, 1, N){
    if ( S[i].first != S[i-1].first ) r = (i+1);
    R[S[i].second] = r;
  }
  
  rep(i, N) cout << R[i] << endl;
}
