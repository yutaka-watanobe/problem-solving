#include <iostream>
using namespace std;

long long getY(long long x){
  long long y = 0;
  while(x){
    y += x % 10;
    x /= 10;
  }
  return y;
}

int main(){
  long long a, n, m;
  cin >> a >> n >> m;
  int cnt = 0;
  for ( int y = 1; y <= 72; y++ ){
    long long x = 1;
    for ( int t = 1; t <= n; t++ ){
      x *= (y + a);
    }
    if (x <= m && getY(x) == y) cnt++;
  }
  cout << cnt << endl;
  return 0;
}

