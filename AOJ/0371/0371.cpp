#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> findDivisors(int n) {
  vector<int> divisors;
  for( int i = 1; i*i <= n; i++ ) {
    if( n % i == 0 ) {
      divisors.push_back(i);
      if( i * i != n ) divisors.push_back(n / i);
    }
  }
  sort(divisors.begin(), divisors.end());
  return divisors;
}

int main() {
  int n, t[100000];
  cin >> n;
  for( int i = 0; i < n; i++ ) cin >> t[i];
  vector<int> divisors = findDivisors(*max_element(t, t + n));
  int ans = 0;
  for( int i = 0; i < n; i++ ) {
    int x = *lower_bound(divisors.begin(), divisors.end(), t[i]);
    ans += x - t[i];
  }
  cout << ans << endl;
  return 0;
}
