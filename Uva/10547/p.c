// @JUDGE_ID:  17051CA  10547  C++
// @begin_of_source_code
/* Calculation */
/* Power + moduler */
#include<stdio.h>
#include<iostream>
typedef unsigned long long ullong;

ullong k, n;
int t;

bool read(){
  cin >> k >> n >> t;
  if ( k == 0 && n == 0 && t == 0 ) return false;
  return true;
}

ullong power(ullong x, ullong n, ullong m){
  ullong tmp = 1;
  if(n>0){
    tmp = power(x, n/2, m);
    if(n%2==0) tmp = tmp*tmp%m;
    else tmp = ((tmp*tmp%m)*(x%m))%m;
  }
  return tmp;
}

void work(){
  ullong m = 1;
  for ( int i = 0; i < t; i++ ) m *= 10;
  cout << power( k, n, m ) << endl;
}

main(){
  for ( int i = 1; read(); i++ ){
    cout << "Case #" << i << ": ";
    work();
  }
}
// @end_of_source_code
