#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> divisor(int n) {
  vector<int> d;
  for( int i = 1; i*i <= n; i++ ) {
    if( n % i == 0 ) {
      d.push_back(i);
      if( i * i != n ) d.push_back(n / i);
    }
  }
  sort(d.begin(), d.end());
  return d;
}

int main() {
  int n, t[100000];
  cin >> n;
  for( int i = 0; i < n; i++ ) cin >> t[i];
  vector<int> p = divisor(*max_element(t, t + n));
  int ans = 0;
  for( int i = 0; i < n; i++ ) {
    int x = *lower_bound(p.begin(), p.end(), t[i]);
    ans += x - t[i];
  }
  cout << ans << endl;
  return 0;
}
