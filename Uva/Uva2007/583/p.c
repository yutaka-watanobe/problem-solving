// @JUDGE_ID:  17051CA  583  C++
// @begin_of_source_code
/* Number Factorize */
#include<stdio.h>
#include<iostream>
#include<vector>
typedef long long llong;

/*
 * 素因数分解 version 1 (Factorization)
 * xの因数をvector<ullong>に入れる。１は素数ではないので入れない。
 * 要件: なし
 */
void factorize(vector<llong> &v, llong x){
  v.clear();
  if(x<2) return;

  for(; !(x&1); x>>=1) v.push_back(2);
  for(; x%3==0; x/=3) v.push_back(3);

  for(llong p=5, b=1; x/p>=p; b=-b, p+=3+b){
    for(; x%p==0; x/=p) v.push_back(p);
  }
  
  if(x>1) v.push_back(x);
}

llong n;

int read(){
  cin >> n;
  if ( n == 0 ) return 0;
  return 1;
}

void work(){
  int m = n;
  if ( m < 0 ) m = -m;

  vector<llong> v;
  factorize( v, m );

  cout << n << " = ";
  if ( n < 0 ) cout << -1 << " x ";

  for ( int i = 0; i < v.size(); i++ ){
    cout << v[i];
    if ( i != v.size() - 1 ) cout << " x ";
  }
  cout << endl;
}

main(){
  while ( read() ) work();
}
// @end_of_source_code
