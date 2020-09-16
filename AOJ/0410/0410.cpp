#include<iostream>
#include<numeric>
using namespace std;
typedef unsigned long long ull;

int N, A[20], cnt;
bool selected[20];

ull lcm(ull x, ull y){ return x / gcd(x, y) * y; }
  
void rec(int p, ull LCM, int sum){
  if ( p == N ){
    bool ok = (sum > 0); // 一人以上いる
    for ( int i = 0; i < N; i++ ){
      //　選ばれていない人の周期
      if ( LCM >= A[i] && LCM % A[i] == 0 && selected[i] == false ) ok = false; 
    }
    if ( ok ) cnt++;
  } else {
    selected[p] = true;
    rec(p+1, lcm(LCM, A[p]), sum+1);
    selected[p] = false;
    rec(p+1, LCM, sum);
  }
}

int main(){
  cin >> N;
  for ( int i = 0; i < N; i++ ) cin >> A[i];
  cnt = 0;
  rec(0, 1, 0);
  cout << cnt << endl;
  return 0;
}
