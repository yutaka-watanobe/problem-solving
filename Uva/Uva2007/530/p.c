// @JUDGE_ID:  17051CA  530  C++
// @begin_of_source_code
/* Combination */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
typedef unsigned long long ullong;

ullong gcd(ullong a, ullong b){
  ullong tmp;

  if(a<b) swap(a, b);

  while(b){
    a %= b;
    tmp = a;
    a = b;
    b = tmp;
  }

  return a;
}

/*
 * nCr (組み合わせ)
 * 要件: 31 >= n >= r >= 0であること。 関数 gcd
 */
ullong nCr(int n, int r){
  ullong i, j, tmp, g, ret;
  int ar[32];

  if(r>n/2) r = n-r;
  if(r==0) return 1;
  
  for(i=0; i<r; i++) ar[i] = n-i;
  for(i=r; i>1; i--){
    for(j=0, tmp=i; j<r; j++){
      g = gcd(ar[j], tmp);
      ar[j] /= g;
      tmp /= g;
    }
  }
  for(i=0, ret=1; i<r; i++) ret *= ar[i];
  
  return ret;
}

int n, k;

int read(){
  cin >> n >> k;
  if ( n == 0 && k == 0 ) return 0;
  return 1;
}

void work(){
  cout << nCr( n, k ) << endl;
}

main(){
  while ( read() ) work();
}
// @end_of_source_code
