#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
using namespace std;

static const int M = 1000000007;

void compute(int N, int H, vector<int> v){
  vector<pair<int, int> > R; // 
  int s, t;
  for ( int i = 0; i < H; i++ ){
    cin >> s >> t;
    swap(v[s], v[t]);
  }

  for ( int i = 1; i <= N; i++ ){
    if ( v[i] != i ) R.push_back(make_pair(v[i], i));
  }

  long long cnt = 0;
  long long a = 1, f = 1;
  for ( int p = N; p > 0; p-- ){
    long long L = max(v[p]-1, p-1);
    //long long W = max(L-p, 0LL);
    long long W = min(v[p], p);
    for ( int i = 0; i < R.size(); i++ ){
      if ( R[i].second <= p ) continue;
      if ( R[i].second <= L) W--;
      if ( R[i].first < v[p] ) W++;
    }
    cnt = (cnt + (W*a)%M)%M;
    a = (a*f)%M;
    f = (f+1)%M;
  }
  cout << cnt << endl;
}

main(){
  int N, H;
  while(1){
    cin >> N;
    if ( N == 0 ) break;
    cin >> H;
    vector<int> v;
    v.push_back(0);
    for ( int i = 0; i < N; i++ ) v.push_back(i+1);
    compute(N, H, v);
  }
}
