// @JUDGE_ID:  17051CA  10299  C++
// @begin_of_source_code
/* Number theory */
/* Eular Phi */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stl.h>
typedef unsigned long long ullong;

/*
 * 素因数分解 version 2 (Factorization) 
 * xの因数をvector<pair<ullong, int> >に, (因数,その乗数)のペアで入れる。
 * 要件: なし
 */
void factorize(vector<pair<ullong, int> > &v, ullong x){
  vector<ullong> t;

  if(x<2) return;

  for(; !(x&1); x>>=1) t.push_back(2);
  for(; x%3==0; x/=3) t.push_back(3);

  for(ullong p=5, b=1; x/p>=p; b=-b, p+=3+b){
    for(; x%p==0; x/=p) t.push_back(p);
  }
  if(x>1) t.push_back(x);

  v.clear();
  v.push_back(pair<ullong, int>(t[0], 1));

  for(int i=1; i<t.size(); i++){
    if(v.back().first==t[i]) v.back().second++;
    else v.push_back(pair<ullong, int>(t[i], 1));
  }
}

/*
 * オイラーφ (φ(x)=([1,x]までの整数の中で、xと素なものの数)) 
 * 要件: 関数 factorize (version 2) 
 */
ullong phi(ullong x){
  vector<pair<ullong, int> > v;
  ullong i, j, ret;
  
  if(x==1) return 0;

  factorize(v, x);
  for(i=0, ret=1; i<v.size(); i++){
    ret *= v[i].first-1;
    for(j=1; j<v[i].second; j++) ret *= v[i].first;
  }
  return ret;
}

ullong n;

int read(){
  cin >> n;
  if ( n == 0 ) return 0;
  return 1;
}

void work(){
  if ( n == 1 ) cout << 0 << endl;
  else cout << phi( n ) << endl;
}

main(){
  while ( read() ) work();
}
// @end_of_source_code
