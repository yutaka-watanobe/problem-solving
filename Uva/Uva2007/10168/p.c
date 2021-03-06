// @JUDGE_ID:  17051CA  10168  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<stl.h>
typedef unsigned long long ullong;

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

int n;
vector<ullong> P;

void work(){

}


main(){
  eratos( 0, 10000000, P );
  while ( cin >> n ) work();
}
// @end_of_source_code
