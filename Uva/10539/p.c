// @JUDGE_ID:  17051CA  10539  C++
// @begin_of_source_code
/* Number - Prime */
/* Use vector + sort not set! to binary search */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stl.h>
#include<cmath>

typedef unsigned long long ullong;

ullong power(ullong x, int n){
  ullong tmp = 1;
  if(n>0){
    tmp = power(x, n/2);
    if(n%2==0) tmp = tmp*tmp;
    else tmp = tmp*tmp*x;
  }
  return tmp;
}

/* 
 * エラトステネスの篩 version 1 (The sieve of Eratosthenes)
 * 閉区間[3, x], x>=3, 内の奇数が素数かどうかをvector<bool>に入れる。
 * primes[i] == true が 2*i+3 が素数であることを表す。
 * 要件: なし
 */
void eratos(ullong x, bit_vector &primes){
  ullong i, j;
  
  primes = bit_vector((x-1)/2, 1);
  
  for(i=3; i<=sqrt(x); i+=2)
    for(j=3; i*j<=x; j+=2)
      primes[(i*j-3)/2] = 0;
}

/*
 * エラトステネスの篩 version 2 (The sieve of Eratosthenes)
 * 閉区間[min(a, b), max(a, b)], a, b>0, 内の素数をvector<ulong>に入れる。
 * 要件: 関数 eratos (version 1)
 */
void eratos(ullong a, ullong b, vector<ullong> &p){
  bit_vector v;
  ullong i;
  
  if(a>b) swap(a, b);
  if(b<2) return;
  if(b==2){ p = vector<ullong>(1, 2); return; }
  
  eratos(b, v);
  
  if(a<=2){ p.push_back(2); a = 2; }
  for(i=(a-2)/2; i<=(b-3)/2; i++)
    if(v[i]) p.push_back(2*i+3);
}

vector<ullong> P;
vector<ullong> T;

ullong lower, upper;

void read(){
  cin >> lower >> upper;
}

void work(){
  vector<ullong>::iterator low_pos, up_pos;
  
  low_pos = lower_bound( T.begin(), T.end(), lower );
  up_pos = lower_bound( T.begin(), T.end(), upper );

  cout << distance( low_pos, up_pos ) << endl;
}

main(){
  eratos( 2, 1000000, P );
  ullong pp;

  for ( int i = 0; i < P.size(); i++ ){
    ullong p = P[i];
    pp = p;
    while ( 1 ){
      pp *= p;
      if ( pp >= 1000000000000LL ) break;
      T.push_back ( pp );
    }
  }

  sort( T.begin(), T.end() );

  int t;
  cin >> t;
  for ( int i = 0; i < t; i++ ){
    read();
    work();
  }
}
// @end_of_source_code
