#include<stdio.h>
#include<iostream>
#include<stl.h>
#include<string>

#define N 1000000
/*
 * -A«€ŒÛ•–°º•∏•Á•Û$)B
 * Solved 10394,
 */
bool prime[N+1];
bool digitprime[N+1];

void eratos( int n ){

  fill(prime, prime+N, false);
  /* -A¥ÒøÙ§Ú¡«øÙ∏ı ‰§»§π§Î */$)B
  for ( int i = 3; i <= n; i += 2 ) prime[i] = true;
  prime[2] = true;
  
  /* -AπÁ¿ÆøÙ§«§ §§¥ÒøÙ§¿§±§Úªƒ§π */$)B
  for ( int i = 3, limit = (int)sqrt(n); i <= limit; i += 2 ) {
    if ( !prime[i] ) continue;
    
    for ( int j = i * i, k = i * 2; j <= n; j += k ) prime[j] = false;
  }
}

int t1, t2;

string ltoa(int x){
  char a[11];
  
  sprintf(a, "%d", x);

  return string(a);
}

void work(){
  scanf( "%d %d", &t1, &t2 );
  
  int cnt = 0;
  int sum;
  for ( int i = t1; i <= t2; i++ ){
    if ( digitprime[i] ){
      cnt++;
      continue;
    }
    if ( prime[i] ) {
      string s;
      s = ltoa( i );
      sum = 0;
      for ( int j = 0; j < s.size(); j++ ){
	sum += s[j] - '0';
      }
      if ( prime[sum] ){
	digitprime[i] = true;
	cnt++;
      }
    }
  }

  printf("%d\n", cnt);
}

main(){
  fill( digitprime, digitprime + N, 0 );

  eratos( N );
  int t;
  scanf( "%d", &t );
  for ( int i =0; i < t; i++ ) work();
}
