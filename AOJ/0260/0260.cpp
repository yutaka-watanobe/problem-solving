#include<iostream>
#include<algorithm>
using namespace std;
static const int MAX = 65000;
typedef long long llong;

main(){
  llong n, totalp, totalj;
  llong P[MAX], J[MAX];
  while(1){
    cin >> n;
    if ( n == 0 ) break;
    totalp = 0;
    for ( int i = 0; i < n; i++ ) {
      cin >> P[i];
      totalp += P[i];
    }
    for ( int i = 0; i < n-1; i++ ) {
      cin >> J[i];
    }

    llong maxv = 0;
    sort(J, J+(n-1));
    reverse(J, J+(n-1));
    totalj = 0;
    for ( llong j = 0, t = n; t >= 1; t--, j++ ){
      llong v = t*(totalj + totalp);
      totalj += J[j];
      maxv = max(v, maxv);
    }
    cout << maxv << endl;
  }
}
