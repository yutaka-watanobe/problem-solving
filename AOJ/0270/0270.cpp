#include<iostream>
using namespace std;
static const int MAX = 300000;

bool T[MAX+1];
int L[MAX+1];

main(){
  int N, Q, q, x;

  cin >> N >> Q;

  for ( int i = 0; i < N; i++ ) {
    cin >> x;
    T[x] = true;
  }

  int m = 0;
  for ( int i = 1; i <= MAX; i++ ){
    L[i] = m;
    if ( T[i] ) m = i;
  }

  for ( int i = 0; i < Q; i++ ){
    cin >> q;
    int maxv = 0;
    int cur = m;
    while(cur){
      int p = cur % q;
      maxv = max(maxv, p);
      if ( cur - p < 0 ) break;
      cur = L[cur - p];
    }
    cout << maxv << endl;
  }
}
