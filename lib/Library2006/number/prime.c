/*************************
 * Prime                 *
 *************************/

#include <iostream>
#include <vector>
#include <cmath>

/*
 * 配列バージョン
 * Solved 10394,
 */
bool prime[N+1];
void eratos( int n){

  fill(prime, prime+N, false);
  /* 奇数を素数候補とする */
  for ( int i = 3; i <= n; i += 2 ) prime[i] = true;
  prime[2] = true;
  
  /* 合成数でない奇数だけを残す */
  for ( int i = 3, limit = (int)sqrt(n); i <= limit; i += 2 ) {
    if ( !prime[i] ) continue;
    
    for ( int j = i * i, k = i * 2; j <= n; j += k ) prime[j] = false;
  }
}
/**  エラトステネスの篩 (Sieve of Eratosthenes) 
 * 
 *  説明: 
 *    0 .. n の範囲で素数表を作成 
 *  使い方: 
 *    素数表を保存する vector<int> を渡すこと。容量確保は関数が行う. 
*/
void eratos( int n, vector<int> &p ) {
  p.assign(n + 1, false);
  
  /* 奇数を素数候補とする */
  for ( int i = 3; i <= n; i += 2 ) p[i] = true;
  p[2] = true;
  
  /* 合成数でない奇数だけを残す */
  for ( int i = 3, limit = (int)sqrt(n); i <= limit; i += 2 ) {
    if ( !p[i] ) continue;
    
    for ( int j = i * i, k = i * 2; j <= n; j += k ) p[j] = false;
  }
}


/*  素数判定 */

/*  説明 */
/*    与えられた負でない整数 n が素数かどうか判定する. */
/*    多くの素数について行うと効率が悪いので素数表を作ること. */

bool isprime( int n ) {
  if ( n == 0 || n == 1 ) return false;
  
  /* 2 と 3 で割り切れないかチェック */
  if ( n == 2 || n == 3 ) return true;
  if ( n % 2 == 0 || n % 3 == 0 ) return false;
  
  /* 他の素数候補で割り切れないかチェック */
  for ( int i = 5, b = 1, limit = (int)sqrt(n); i <= limit; b = -b, i += 3 + b )
    if ( n % i == 0 ) return false;
  
  return true;
}


int main() {
  vector<int> prime;
  
  /*  0 .. 100000 の素数表を作成*/
  eratos(100000, prime);
  
  /* 素数表と素数判定の結果が等しいか検証する(検証済み)*/
  for ( int i = 0; i <= 100000; i++ )
    if ( isprime(i) != prime[i] ) cout << "ERROR!! : " << i << endl;
  
  return 0;
}
