#include<iostream>
#include<algorithm>
using namespace std;
#define REP(i, b, e) for ( int i = b; i < (int)e; i++ )
#define rep(i, n) REP(i, 0, n)

static const int MAX = 100000;

main(){
  int T[MAX+2], A[MAX+2];
  pair<int, int> M[MAX+2];
  int N, L, ans = 0;
  cin >> N >> L;
  rep(i, N+2) T[i] = 0;
  M[0] = make_pair(0, 0);
  M[N+1] = make_pair(0, N+1);
  rep(i, N+2) A[i] = 0;
  
  REP(i, 1, N+1) {
    cin >> T[i];
    M[i] = make_pair((-1)*T[i], i);
  }
  sort(M, M+(N+2));

  rep(i, N+2){
    int idx = M[i].second;
    if ( idx == 0 || idx == N+1 ) continue;
    if ( T[idx] > T[idx-1] && T[idx] > T[idx+1] ){
      A[idx] = L - T[idx];
    } else {
      A[idx] = max(A[idx-1], A[idx+1]) + (L - T[idx]);
    }
  }
  rep(i, N+2) ans = max(ans, A[i] );
  cout << ans << endl;

}
