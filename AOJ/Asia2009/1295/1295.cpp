#include<iostream>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++)
main(){
  int w, d, L[10], R[10];
  while( cin >> w >> d && w){
    rep(i, w) cin >> L[i];
    rep(i, d) cin >> R[i];
    int s = 0;
    rep(i, w) rep(j, d){
      if ( R[j] && L[i] == R[j] ){ s += R[j]; L[i] = R[j] = 0;}
    }
    rep(i, w) if (L[i]) s += L[i];
    rep(i, d) if (R[i]) s += R[i];
    cout << s << endl;
  }
}
