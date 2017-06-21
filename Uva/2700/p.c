// @JUDGE_ID:  17051CA  2700  C++
// @begin_of_source_code
/* Graph + Combinatorial */
#include<stdio.h>
#include<iostream>
#include<stl.h>
#include<map>
typedef unsigned long long ullong;

/*
 * 最大公約数 (Greatest Common Divisor)
 * a > b > 0 を保証すること。
 * 要件: なし
 */
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

class Travel{
 public:
  int L;
  double F1, F2, F3;
  
  Travel(){}
  Travel( int L ): L(L){
    createF1();
    createF2();
    createF3();
  }

  void createF1(){
    ullong numerator = 0;
    ullong denominator = 0;
    ullong p = L - 1;
    for ( int k = 1; k <= L; k++ ){
      numerator += k * p;
      denominator += p;
      p *= ( L - 1 );
    }
    F1 = (double)numerator / denominator;
  }

  void createF2(){
    ullong numerator = 0;
    ullong denominator = 0;
    ullong fac = 1;
    ullong combinationFac;
    for ( int k = 0; k <= L - 2; k++ ){
      /* combination = nCr( L - 2, k ); */
      combinationFac = nCr( L - 2, k ) * fac;
      numerator += ( k + 1 ) * combinationFac;
      denominator += combinationFac;
      fac *= ( k + 1 );
    }
    F2 = (double)numerator / denominator;
  }

  void createF3(){
    ullong numerator = 0;
    ullong denominator = 0;
    ullong fac = 1;
    ullong combinationFac;
    for ( int k = 2; k <= L - 1; k++ ){
      /* combination = nCr( L - 1, k ); */
      combinationFac = nCr( L - 1, k ) * fac;
      numerator += ( k + 1 ) * combinationFac;
      denominator += combinationFac;
      fac *= ( k + 1 );
    }
    F3 = (double)numerator / denominator;
  }
};

map<int, Travel> T;
int L;

void work(){
  if ( T.find( L ) == T.end() ){
    T[ L ] = Travel( L );
  }
  printf("%.4lf %.4lf %.4lf\n", T[ L ].F1, T[ L ].F2, T[ L ].F3 );

}

bool read(){
  cin >> L;
  if ( L == 0 ) return false;
  return true;
}

main(){
  while ( read() ){
    work();
  }
}

// @end_of_source_code


