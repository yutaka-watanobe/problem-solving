#include<iostream>
#include<algorithm>
using namespace std;
static const int MAX = 100001;

main(){
  int n, m; cin >> n >> m;
  int D[MAX], k, a, sum, p;
  D[0] = 0;
  for ( int i = 1; i < n; i++ ){
    cin >> k;
    D[i] = D[i-1] + k;
  }
  sum = 0, p = 0;
  for ( int i = 0; i < m; i++ ){
    cin >> a;
    sum += max(D[p], D[p+a]) - min(D[p], D[p+a]);
    sum = sum%100000;
    p = p+a;
  }
  cout << sum << endl;
}
