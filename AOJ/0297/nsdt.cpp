#include<iostream>
using namespace std;
int main(){
  int i, n, k, p;
  cin >> n;
  for ( i=0; i<n; ++i ) {
    cin >> k >> p;
    if ( k%p == 0 ) cout << n << endl;
    else            cout << k%p << endl;
  }
  return 0;
}
