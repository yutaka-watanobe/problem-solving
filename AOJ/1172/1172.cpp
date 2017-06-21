#include<iostream>
#include<algorithm>
#include<cmath>
#include<math.h>
using namespace std;

bool isPrime( int x ){
    if ( x < 2 ) return false;
    else if ( x == 2 ) return true;
    if ( x % 2 == 0 ) return false;
    int limit = (int)sqrt((double)x) + 1;
    for ( int i = 3; i <= limit; i += 2 ){
	if ( x % i == 0 ) return false;
    }
    return true;
}

int main(void){
  int n;
  while ( cin >> n, n){
    int cnt = 0;
    for ( int i = n+1; i <= 2*n; i++ )
      if ( isPrime( i ) )cnt++;
    cout << cnt << endl;
  }
    return 0;
}

