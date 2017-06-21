#include<iostream>
#include<cassert>
#include<cmath>
#define MAX 2000000
using namespace std;

void eratos ( int n, bool prime[]){
    for ( int i = 0; i <= n; i++ ) prime[i] = false;
    for ( int i = 3; i <= n; i += 2 ) prime[i] = true;
    prime[2] = true;
    int limit = (int)sqrt((double)n) + 1;
    for ( int i = 3; i <= limit; i += 2 ){
	if ( !prime[i] ) continue;
	for ( int j = i + i; j <= n; j += i ) prime[j] = false;
    }
}

void eratos2( int n, bool prime[] ){
  for ( int i = 0; i <= n; i++ ) prime[i] = true;
  prime[0] = prime[1] = false;
  for ( int i = 2; i*i <= n; i++ ){
    if ( prime[i] )
      for ( int j = 2; i*j <= n; j++ ) prime[i*j] = false;
  }
}

int main(void){
    bool prime[MAX + 1];
    bool prime2[MAX + 1];
    int size;
    cin >> size;
    eratos( size, prime );
    eratos2( size, prime2 );

    for ( int i = 0; i < size; i++ ) {
      assert( prime[i] == prime2[i] );
      //if ( prime2[i] ) cout << i << " ";
    }
    //    cout << endl;

    return 0;
}
