#include<iostream>
#include<algorithm>
using namespace std;
static const int N_MAX = 10;
int N, a[N_MAX], w[N_MAX], ans;
int table[N_MAX]; // 座席表
bool sat[N_MAX];  // 座ったかどうか

void rec(int p){
  if ( p == N ){
    int sum = 0;
    for ( int i = 0; i < N; i++ ){
      if ( a[table[i]] == 0 && a[table[(i - 1 + N) % N]] == 1 ||
	   a[table[i]] == 1 && a[table[(i + 1) % N]] == 0 )
	sum += w[table[i]];
    }
    ans = min(sum, ans);
    return;
  }
  for ( int i = 0; i < N; i++ ){
    if ( sat[i] ) continue;
    sat[i] = true;
    table[p] = i;
    rec(p + 1);
    sat[i] = false;
  }
}

int main() {
  cin >> N;
  for ( int i = 0; i < N; i++ ) cin >> a[i];
  for ( int i = 0; i < N; i++ ) cin >> w[i];
  ans = 1000 * N;
  rec(0);
  cout << ans << endl;
  return 0;
}

