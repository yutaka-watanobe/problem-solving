#include<stdio.h>
#include<stdlib.h>

int getNumberOfPrime(int );

main(){
  int n;
  scanf("%d", &n);
  printf("\n");
  printf("number of prime %d \n", getNumberOfPrime(n) );
  return 0;
}

int getNumberOfPrime(int n){
  int *primes;
  primes = (int *)malloc(n*sizeof(int));
  int i, k;
  
  /* sieve of Eratosthenes */
  for ( i = 0; i <= n; i++ ) primes[ i ] = i;
  
  i = 2; 
  primes[ i ] = 0;
  while ( i <= n ) {
    for ( k = i + 1; k <= n; k++ ){
      if ( ( primes[ k ] != 0 ) && ( primes[ k ] % i == 0 ) )
	primes[ k ] = 0;
    }
    do i++; while ( i <= n && primes[ i ] == 0 ); 
  }
  
  
  for ( i = 1, k = 0; i <= n; i++ ){
    if ( primes[ i ] != 0 ) {
      printf( "%6d", primes[ i ] );
      k++;
      if ( k % 10 == 0 ) putchar( '\n' );
    }
  }
  return k;
}

