// @JUDGE_ID:  17051CA  524  C++
// @begin_of_source_code
/* 素数 (総当たり）テーブルをつくると遅くなる */
/* 2.52 sec */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#define N 35

bool prime[N];

void eratos( int n ){

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

int n;
map<int, vector<vector<int> > > M;
vector<int> U, V;
int K;

int read(){
  cin >> n;
  if ( cin.eof() ) return 0;
  return 1;
}

void rec( int index ){

  if ( index > K ){
    if ( prime[ V[1] + V[K] ] ){
      /* print */
      for ( int i = 1; i < V.size(); i++ ){
	if ( i > 1 ) cout << " ";
	cout << V[i];
      }
      cout << endl;
    }
    return ;
  }

  if ( index == 1 ){
    V[index] = 1;
    U[1] = true;
    rec( index + 1 );
  }else{
    for ( int i = 2; i <= K; i++ ){
      if ( !U[i] && prime[ V[index - 1] + i ] ){
	V[index] = i;
	U[i] = true;
	rec( index + 1 );
	U[i] = false;
      }
    }
  }

}

void init(){
  eratos( N - 1 );
}

void work(){
    U.clear();
    V.clear();
    U.resize( n+1, 0 );
    V.resize( n+1, 0 );
    K = n;
    rec( 1 ); 
}

main(){
  init();
  for ( int i = 1; read(); i++){
    if ( i > 1 ) cout << endl;
    cout << "Case " << i << ":" << endl;
    work();
  }
}
// @end_of_source_code
