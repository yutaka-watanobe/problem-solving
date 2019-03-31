#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int N, x, y, b, p;
  cin >> N;
  for(int i = 0; i < N; ++i) {
    cin >> x >> y >> b >> p;
    cout << min(x*b+y*p, (x*max(b,5)+y*max(p,2))*4/5) << endl;
  }
  return 0;
}
