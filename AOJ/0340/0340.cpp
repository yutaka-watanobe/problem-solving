#include <iostream>
using namespace std;
static const int MAX = 5000;

int main() {
  int N, p[MAX], r[MAX];
  int ans = (1 << 29);
  cin >> N;
  for(int i = 0; i < N; i++ ) cin >> p[i];

  for(int j = 0; j <= p[0]; j++) {
    int x = j;
    for(int i = 0; i < N; i++) r[i] = p[i];
    r[0] -= j;
    for(int i = 0; i < N - 1; i++) {
      int y = max(0, r[i]);
      r[i] -= y;
      r[i + 1] -= y;
      x += y * 2;
    }
    ans = min(ans, x + max(0, r[N - 1]));
  }
  
  cout << ans << endl;
  
  return 0;
}
