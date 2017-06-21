// @JUDGE_ID:  17051CA  10042  C++
// @begin_of_source_code
/* Number Theory */
/* Factorize + Prime Number */
#include<stdio.h>
#include<iostream>
#include<vector>
typedef unsigned long long ullong;

/* a*b mod N の計算
 * 要件: 0 < N <= 2**30
 */
ullong abmodN(ullong a, ullong b, ullong N){
  ullong i, ret, tmp[64];

  for(i=1, tmp[0]=a%N; i<sizeof(ullong)*8; i++)
    tmp[i] = (tmp[i-1]*2)%N;

  for(i=0, ret=0; i<sizeof(ullong)*8; i++){
    if(b&1){
      ret += tmp[i];
      ret %= N;
    }
    b >>= 1;
  }
  return ret;
}

/* 素数かどうかのテスト (primality test)
 * 要件: 1 <= x <= 3415500717128321, 下記の配列, 関数 abmodN
 *       (119269249まではテスト済み)
 */
int base[8] = {0, 2, 3, 5, 7, 11, 13, 17};
ullong limit[8] = {0, 2047, 1373653, 25326001, 3215031751LL, 
		   2152302898747LL, 3474749660383LL, 3415500717128321LL};

bool is_prime(ullong x){
  ullong d, d1, prod, a2j;
  int s;

  if(x<2) return 0;
  if(x==2) return 1;
  if(!(x&1)) return 0;
  
  for(d=x-1, s=0; d>0 && !(d&1); d>>=1, s++);
  d1 = d;
  
  for(int i=1; i<=7; i++){
    a2j = base[i]; 
    prod = 1; 
    d = d1; 
    while(d > 0){
      if(d&1) prod = abmodN(prod, a2j, x);
      d >>= 1;
      a2j = abmodN(a2j, a2j, x);
    }
    
    if(prod==1 || prod==x-1) goto lim_check;
    
    for(int j=1; j<s; j++){
      prod = abmodN(prod, prod, x);
      if(prod==1) return 0;
      if(prod==x-1) goto lim_check;
    }
    return 0;
  lim_check:
    if(x < limit[i]) return 1;
  }
}

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

class SmithNumbers{
 public:
  ullong n;

  ullong getSum( ullong x ){
    ullong sum = 0;
    while ( 1 ){
      sum += x % 10;
      if ( x < 10 ) break;
      x /= 10;
    }
    return sum;
  }

  bool is_smithNumber( ullong x ){
    vector<pair<ullong,int> > v;
    factorize( v, x );
    ullong sum1 = getSum( x );
    ullong sum2 = 0;
    for ( int i = 0; i < v.size(); i++ ) {
      sum2 += getSum( v[i].first ) * v[i].second;
    }
    return sum1 == sum2;
  }

  void work(){
    n++;
    while ( 1 ){
      if ( is_prime( n ) ){
	n++;
      } else {
	if ( is_smithNumber( n ) ){
	  break;
	} else {
	  n++;
	}
      }
    }

    cout << n << endl;
  }

  void read(){
    cin >> n;
  }
  
};

main(){
  SmithNumbers SN;
  int tcase;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    SN.read();
    SN.work();
  }
}
// @end_of_source_code


