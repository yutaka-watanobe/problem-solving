#include<iostream>
#include<algorithm>
using namespace std;
static const int N = 100;

int getScore(int n, int k, int A[]){
  int ms = 0;
  for ( int i = 0; i < n-k+1; i++ ){
    int p = 1;
    for ( int j = i; j < i+k; j++ ){
      p *= A[j];
    }
    ms = max(ms, p);
  }
  return ms;
}

main(){
  int A[N], n, k, C1, C2;
  while(1){
    cin >> n >> k;
    if ( n == 0 && k == 0 ) break;
    C1 = C2 = 0;
    for ( int i = 0; i < n; i++ ) cin >> A[i];
    C1 = getScore(n, k, A);

    for ( int i = 0; i < n; i++ ){
      for ( int j = 0; j < n; j++ ){
	swap(A[i], A[j]);
	C2 = max(C2, getScore(n, k, A));
	swap(A[i], A[j]);
      }
    }
    
    if ( C2 - C1 < 0) cout << "NO GAME" << endl;
    else cout << C2 - C1 << endl;
      
  }
}
