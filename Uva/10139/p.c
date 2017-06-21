// @JUDGE_ID:  17051CA  10139  C++
// @begin_of_source_code
/* Number Theory */
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

ullong power(ullong x, int n){
  ullong tmp = 1;

  if(n>0){
    tmp = power(x, n/2);
    if(n%2==0) tmp = tmp*tmp;
    else tmp = tmp*tmp*x;
  }
  return tmp;
}

int n, m;
vector<ullong> P;

int read(){
  cin >> n >> m;
  if ( cin.eof() ) return 0;
  return 1;
}

void work(){
  if ( m == 0 ){
    cout << "0 does not divide " << n << "!" << endl;
    return;
  }

  vector<pair<ullong, int> > F;
  map<ullong, int> counter;

  factorize( F, m );

  for ( int i = 0; i < F.size(); i++ ){
    int p = 1;
    while ( 1 ){
      ullong a = power( F[i].first, p );
      if ( 1 <= a && a <= n ){
	counter[F[i].first] += n / a;
      }else{
	goto next;
      }
      p++;
    }
  next:;
  }

  bool divide = true;

  for ( int i = 0; i < F.size(); i++ ){
    int target = F[i].first;
    if ( counter[target] < F[i].second ){
      divide = false;
      break;
    }
  }

  cout << m ;
  if ( divide ) cout << " divides ";
  else cout << " does not divide ";
  cout << n << "!" << endl;

}

main(){
  while ( read() ) work();
}
// @end_of_source_code
