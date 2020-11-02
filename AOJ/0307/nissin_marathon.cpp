#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, R, T;
  cin >> N >> R >> T;

  vector<int> p(N);
  for ( int i = 0; i < N; i++ ) cin >> p[i];

  vector<int> filled(R);
  int res = 0;

  for ( int i = 1; i <= T; i++ ) {
    for ( int j = 0; j < N; j++ ) {
      if ( filled[(p[j] * i) % R] <= 0 ) ++res;
      else --filled[(p[j] * i) % R];
    }

    if ( i > 1 ) {
      for ( int j = 0; j < N; j++ ) ++filled[(p[j] * i) % R];
    }
  }

  cout << res << endl;
  return 0;
}
