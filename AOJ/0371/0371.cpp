#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// O(√N)で約数を列挙する
vector<int> findDivisors(int n) {
  vector<int> divisors;
  for( int i = 1; i * i <= n; i++ ) {
    if( n % i == 0 ) {
      divisors.push_back(i);
      // がiで割り切れれば，そのペアとなる
      // n をiで割った値もnを割り切る
      if( i * i != n )
	divisors.push_back(n / i);
    }
  }
  sort(divisors.begin(), divisors.end());
  return divisors;
}

int main() {
  int n, t[100000], maxt = 0;;
  cin >> n;
  for( int i = 0; i < n; i++ ) {
    cin >> t[i];
    // 間隔が一番長いmaxtを更新
    maxt = max(maxt, t[i]);
  }

  // maxtの約数を昇順に列挙 
  vector<int> divisors = findDivisors(maxt);

  int ans = 0;
  for( int i = 0; i < n; i++ ) {
    // tを増やしたときに最初に一致する
    // maxtの約数を二分探索
    int x = *lower_bound(divisors.begin(),
			 divisors.end(),
			 t[i]);
    ans += x - t[i];
  }
  cout << ans << endl;
  return 0;
}

