// @JUDGE_ID:  17051CA  10394  C++
// @begin_of_source_code
/* 素数 */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#define N 20000001

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

int S;
vector<pair<int, int> > twin;

void init(){

  eratos(N);
  
  pair<int, int> tmp;

  twin.reserve(100002);
  int pre = 3;
  for(int i=3; i<N; i+=2){
    if(!prime[i]) continue;
    if(i-pre==2){
      tmp.first = pre;
      tmp.second = i;
      twin.push_back(tmp);
    }
    pre = i;
  }
}

int read(){
  cin >> S;
  if(cin.eof()) return 0;
  return 1;
}

void work(){
  cout << "(" << twin[S-1].first << ", " << twin[S-1].second << ")" << endl;
}

main(){
  init();
  while(read()){
    work();
  }
}
// @end_of_source_code
