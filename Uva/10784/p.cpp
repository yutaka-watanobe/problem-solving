#include<iostream>
#include<cmath>

#define MAX 100

typedef unsigned long long ullong;

int compute( ullong N ){
  if ( N == 0 ) return 3;
  if ( N == 1 ) return 4;
  
  ullong ans =  (int)(  (3 + sqrt( 9.0 + 8*N )) / 2);
  ans -= 1;
  if ( ans < 0 ) ans = 3;
  while ( ans*(ans-1)/2 - ans < N ) ans++;

  if ( ans <= 4 ) ans = 4;
  return ans;

}

main(){
  ullong n;
  for ( int i = 1; cin >> n; i++ ){
    if ( n == 0 ) break;
    cout << "Case " << i << ": " << compute( n ) << endl;
  }
}
