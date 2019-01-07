/*
y を決め打ちして、x=(y+a)^nを満たすものの個数を数えます。
yの最大値は99999999 = 72 で十分

*/

#include <iostream>
using namespace std;

long long val(long long x){
  long long sum = 0;
  while(x){
    sum += x%10;
    x /= 10;
  }
  return sum;
}

int main(){
  long long a, n, m;
  cin >> a >> n >> m;
  int cnt = 0;
  for ( int y = 1; y <= 72; y++ ){
    long long x = 1;
    for ( int t = 1; t <= n; t++ ){
      x *= (y+a);
      //      if ( x > m ) return cnt;
    }
    if (x <= m && val(x) == y) cnt++;
  }

  cout << cnt << endl;

  return 0;
}

