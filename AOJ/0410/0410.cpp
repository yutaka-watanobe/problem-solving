#include<iostream>
#include<numeric>
using namespace std;

long long lcm(long long x, long long y){ return x / gcd(x, y) * y; }
  
int main(){
  int N, A[20], cnt = 0;
  cin >> N;
  for ( int i = 0; i < N; i++ ) cin >> A[i];

  for ( int bit = 1; bit < (1 << N); bit++ ) {
    bool valid = true;
    long long LCM = 1;
    for ( int i = 0; i < N; i++ ){
      if ( bit & (1 << i) ) LCM = lcm(LCM, A[i]);
    }
    for ( int i = 0; i < N; i++ ){
      if ( (bit & (1 << i)) == 0 )
	if ( LCM >= A[i] && LCM % A[i] == 0 ) valid = false; 
    }
    if ( valid ) cnt++;
  }
  
  cout << cnt << endl;
  return 0;
}
