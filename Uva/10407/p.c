// GCD
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#define MAX 1001

int gcd(int a, int b){
  int tmp;

  if(a<b) swap(a, b);

  while(b){
    a %= b;
    
    tmp = a;
    a = b;
    b = tmp;
  }

  return a;
}

int size;
int buffer[ MAX ];
int diff[ MAX ];

void work(){
  for ( int i = 1; i < size; i++ ){
    diff[i] = abs( buffer[i-1] - buffer[i] );
  }
  diff[0] = abs( buffer[0] - buffer[size-1] );

  int GCD = gcd( diff[0], diff[1] );
  for ( int i = 1; i < size; i++ ){
    GCD = gcd( GCD, diff[i] );
  }

  printf("%d\n", GCD);
}

bool read(){
  size = 0;
  int x;
  while ( 1 ){
    scanf("%d", &x);
    if ( x == 0 ) break;
    buffer[size++] = x;
  }

  return ( size != 0 );
}

main(){
  while ( read() ){
    work();
  }
}
