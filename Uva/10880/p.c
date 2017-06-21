// factorize + recursive
#include<stdio.h>
#include<vector>
#include<set>

using namespace std;

#define MAX 100000

/*
 * 素因数分解 version 2 (Factorization) 
 * xの因数をvector<pair<ullong, int> >に, (因数,その乗数)のペアで入れる。
 * 要件: なし
 */

pair<int, int> P[MAX];
int size;

void factorize(int x){
  vector<int> t;

  size = 0;

  if(x<2) return;

  for(; !(x&1); x>>=1) t.push_back(2);
  for(; x%3==0; x/=3) t.push_back(3);

  for(int p=5, b=1; x/p>=p; b=-b, p+=3+b){
    for(; x%p==0; x/=p) t.push_back(p);
  }
  if(x>1) t.push_back(x);

  //  v.clear();
  //  v.push_back(pair<int, int>(t[0], 1));
  
  size = 0;
  P[size++] = pair<int, int>(t[0], 1);

  for(int i=1; i<t.size(); i++){
    //    if(v.back().first==t[i]) v.back().second++;
    //    else v.push_back(pair<int, int>(t[i], 1));
    if ( P[size-1].first == t[i] ) P[size-1].second++;
    else P[size++] = pair<int, int>(t[i], 1);
  }
}

set<int> S;

int C, R;
void rec( int pos, int value ){
  if ( pos == size ) {
    if ( value > R ){
      S.insert( value );
    }
    return;
  }

  int x = P[pos].first;
  int n = P[pos].second;
  
  int p = 1;

  for ( int i = 0; i < n+1; i++ ){
    rec( pos + 1, value * p );
    p *= x;
  }

}

void compute(){
  scanf("%d %d", &C, &R);
  int x = C - R;

  if ( x == 0 ){
    cout << " 0" << endl;
    return;
  }


  S.clear();

  factorize(  x );

  rec( 0, 1 );
  
  set<int>::iterator it;

  for ( it = S.begin(); it != S.end(); it++ ){
    printf(" %d", *it);
  }
  printf("\n");
}

main(){
  int tcase; scanf("%d", &tcase);
  for (int i = 1; i <=tcase; i++ ){
    printf("Case #%d:", i);
    compute();
  }
}
