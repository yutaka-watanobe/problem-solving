#include<stdio.h>
#include<iostream>
typedef unsigned long long ullong;

#define first(n) ((ullong)((1U << (n)) - 1U))

ullong nextset(ullong x){
  ullong smallest, ripple, new_smallest, ones;
  smallest = x & -x;
  ripple = x + smallest;
  new_smallest = ripple & -ripple;
  ones = ((new_smallest / smallest) >> 1) -1;
  return ripple | ones;
}

void printset( ullong s, int &n ){
  cout << s << endl;
  for ( int i = 1; i <= n; i++ ){
    if ( s & 1 ) cout << " " << i ;
    s >>= 1;
  }
  cout << endl;
}

/**
 * nCk
 * Solved 347,
 */
void generate(int n, int k){
  int i = 1;
  ullong x, y;
  x = first(k);
  while ( !( x & ~first(n) ) ){
    cout << "  " << i << " ";
    printset(x, n);
    x = nextset(x); i++;
  }
}

main(){
  int N, K;
  cin >> N >> K;
  generate(N, K); /* nCk */
}

