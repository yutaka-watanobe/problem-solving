#include<iostream>
#include<stdlib.h>
#include<cstdio>
#include<cmath>
using namespace std;
typedef unsigned long long ullong;
#define LIM 500000000000LL
int B[33], b;

void parse(long long x, int a){
  if ( 32 < a ) return;
  parse(x/2, a+1);
  B[b++] = x%2;
}

main(){
  int tcase; cin>> tcase;
  for ( int i = 0; i < tcase; i++ ){
    long long x;
    scanf("%llx", &x);
    b = 1;
    parse(x, 1);
    ullong d = 0, f = 0;
    if ( B[1] ) cout << "-";
    for ( ullong i = 2, s = 23; i <= 25; i++, s-- ) d += (1<<s)*B[i];
    for ( ullong i = 26, s = LIM; i <= 32; i++, s /= 2 ) f += B[i]*s;
    cout << d << ".";
    if ( f ) for ( ullong i = f*10; i < LIM*2; i *= 10 ) cout << 0;
    while( f && f%10 == 0 ) f /= 10;
    cout << f << endl;


  }
}
