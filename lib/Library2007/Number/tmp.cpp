// C++
void eratos( int n, bool prime[] ){
  for ( int i = 0; i <= n; i++ ) prime[i] = true;
  prime[0] = prime[1] = false;
  for ( int i = 2; i*i <= n; i++ ){
    if ( prime[i] )
      for ( int j = 2; i*j <= n; j++ ) prime[i*j] = false;
  }
}

// C
void eratos( int n, int prime[] ){
  int i, j;
  for ( i = 0; i <= n; i++ ) prime[i] = 1;
  prime[0] = prime[1] = 0;
  for ( i = 2; i*i <= n; i++ ){
    if ( prime[i] )
      for ( j = 2; i*j <= n; j++ ) prime[i*j] = 0;
  }
}
