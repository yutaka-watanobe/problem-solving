#include<iostream>
#include<cassert>
using namespace std;

typedef unsigned long long ullong;

ullong gcd(ullong a, ullong b){ return b==0?a: gcd(b, a%b);}
ullong lcm(ullong a, ullong b){ return a*(b/gcd(a, b));}

bool isRP(int x){
  if (  x == 13 || x == 17 || x == 19 || x == 23 ) return true;
  return false;
}

main(){
  int N;
  ullong D[100], S[100], T[100][24];
  ullong lcm1, lcm2, max1, max2;

  while(1){
    cin >> N;
    if ( N == 0 ) break;
    lcm1 = lcm2 = 1;
    max1 = max2 = 0;

    for ( int i = 0; i < N; i++ ){
      cin >> D[i] >> S[i];
      assert( 0 <= S[i] && S[i] <= D[i]-1);
      for ( int j = 0; j < D[i]; j++ ) cin >> T[i][j];
      if ( isRP(D[i])) {
	lcm2 = lcm(lcm2, D[i]);
      } else {
	lcm1 = lcm(lcm1, D[i]);
      }
    }

    for ( int j = 0; j < lcm1; j++ ){
      ullong sum = 0;
      for ( int i = 0; i < N; i++ ){
	if ( isRP(D[i]) ) continue;      
	sum += T[i][(j+S[i])%D[i]];
      }
      max1 = max(max1, sum);
    }

    for ( int j = 0; j < lcm2; j++ ){
      ullong sum = 0;
      for ( int i = 0; i < N; i++ ){
	if ( !isRP(D[i]) ) continue;      
	sum += T[i][(j+S[i])%D[i]];
      }
      max2 = max(max2, sum);
    }

    cout << max1 + max2 << endl;
  }
}
