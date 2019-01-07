#include<stdio.h>
#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
using namespace std;

static const int INFTY = (1LL<<31)-1;
static const int MAX_N = (1<<17); // 131072

long long K, N, Q, A[MAX_N];

int n;
long long D[2*MAX_N-1];
int F[2*MAX_N-1];

void init(int n_){
  n = 1;
  while( n < n_ ) n *= 2;
  for ( int i = 0; i < 2*n-1; i++ ) D[i] = 0;
  for ( int i = 0; i < 2*n-1; i++ ) F[i] = 0;
}

void update(int k, int a){
  k += n - 1;
  D[k] = a;
  F[k] = (a == 0);
  while( k > 0 ){
    k = (k - 1)/2;
    D[k] = D[k*2+1] + D[k*2+2]*(F[k*2+1]?(-1):1);
    F[k] = (F[k*2+1] + F[k*2+2])%2;
  }
}

// [a, b)
pair<long long,int> query(int a, int b, int k, int l, int r){
  if ( r <= a || b <= l ) return make_pair(0, 0);
  if ( a <= l && r <= b ) return make_pair(D[k], F[k]);
  else{
    //int vl = query(a, b, k*2 + 1, l, (l + r)/2);
    //    int vr = query(a, b, k*2 + 2, (l + r)/2, r);
    //    return min(vl, vr);
    pair<long long, int> vl = query(a, b, k*2 + 1, l, (l + r)/2);
    pair<long long, int> vr = query(a, b, k*2 + 2, (l + r)/2, r);
    pair<long long, int> res;
    res.first = vl.first + vr.first*(vl.second?(-1):1);
    res.second = (vl.second + vr.second)%2;
    return res;
  }
}

// [a, b]
pair<long long,int> findMin(int a, int b){
  return query(a, b+1, 0, 0, n);
}

void dump(){
  for ( int i = 0; i < n; i++ ) cout << D[i] << " ";
  cout << endl;
}

main(){
  int L, R;
  cin >> K >> N >> Q;
  init(N);
  for ( int i = 0; i < N; i++ ) cin >> A[i];
  for ( int i = 0; i < N; i++ ) update(i, A[i]);
  for ( int i = 0; i < Q; i++ ){
    cin >> L >> R; L--; R--;
    swap(A[L], A[R]);
    update(L, A[L]);
    update(R, A[R]);
    pair<long long, int> res = findMin(0, N-1);
    long long p = res.first;
    bool isng = (p < 0);

    if ( isng ) p *= -1;
    p %= K;
    if ( isng ) cout << (p+1)*(res.second?-1:1) << endl;
    else cout << ((K-p)%K+1)*(res.second?-1:1) << endl;
  }


}


