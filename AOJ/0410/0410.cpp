#include<iostream>
#include<algorithm>
#include<numeric>
typedef unsigned long long ull;
using namespace std;
int N, A[20], cnt;
bool S[20]; // select?

ull lcm(ull x, ull y){
  return x/gcd(x, y)*y;
}
  
void rec(int p, ull LCM, int sum){
  if ( p == N ){
    bool ok = (sum > 0); // 一人以上いる
    for ( int i = 0; i < N; i++ ){
      if ( LCM >= A[i] && LCM % A[i] == 0 ){
        if ( S[i] == false ) ok = false; //　選ばれていない人の周期
      } 
    }
    if ( ok ) cnt++;
    return;
  }
  S[p] = true;
  rec(p+1, lcm(LCM, A[p]), sum+1);
  S[p] = false;
  rec(p+1, LCM, sum);
}
main(){
  cin >> N;
  for ( int i = 0; i < N; i++ ) cin >> A[i];
  cnt = 0;
  rec(0, 1, 0);
  cout << cnt << endl;
}
