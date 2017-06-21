// @JUDGE_ID:  17051CA  10006  C++
// @begin_of_source_code
/* Number Theory */
/* a^n mod n */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#define N 65000

bool prime[N+1];
void eratos( int n){

  fill(prime, prime+N, false);
  /* 奇数を素数候補とする */
  for ( int i = 3; i <= n; i += 2 ) prime[i] = true;
  prime[2] = true;
  
  /* 合成数でない奇数だけを残す */
  for ( int i = 3, limit = (int)sqrt(n); i <= limit; i += 2 ) {
    if ( !prime[i] ) continue;
    
    for ( int j = i * i, k = i * 2; j <= n; j += k ) prime[j] = false;
  }
}

unsigned int n;

int read(){
  cin >> n;
  if ( n == 0 ) return 0;
  return 1;
}

int anmod( unsigned int a, unsigned int k, unsigned int m ){
  unsigned int b = 1;
  
  while ( k >= 1 ){
    if ( k % 2 != 0 ) b = a*b%m;
    a = a*a%m;
    k = k/2;
  }
  return b;
}

void work(){
  if ( prime[ n ] || n == 1){
    cout << n << " is normal." << endl;
    return ;
  }

  for ( unsigned int a = 2; a <= n-1; a++ ){
    if ( anmod( a, n, n) != a ){
      cout << n << " is normal." << endl;
      return ;
    }
  }
  
  cout << "The number " << n << " is a Carmichael number." << endl;
}

main(){
  eratos( N );
  while ( read() ) work();
}
// @end_of_source_code
