// @JUDGE_ID:  17051CA  10020  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
#define MAX 5001

int T[MAX];
vector<pair<int, int> > S;
int M;

void read(){
  S.clear();
  int l, r;
  cin >> M;
  while( 1 ){
    cin >> l >> r;
    if ( l == 0 && r == 0 ) break;
    S.push_back( make_pair(l, r) );
  }
  
  sort( S.begin(), S.end() );
}

void work(){
  fill ( T, T+MAX, 0 );
  int l, r;
  int cost;
  for ( int i = 0; i < S.size(); i++ ){
    l = S[i].first; r = S[i].second;
    if ( r < 0 ) continue;
    if ( r == l ) continue;

    if ( l < 0 ) cost = 1;    
    else cost = T[l] + 1;

    for ( int i = l; i <= r; i++ ){
      if ( !( 0 <= i && i < MAX ) ) continue;
      if ( T[i] == 0 ) T[i] = cost;
    }
  }
  cout << T[M] << endl;
}

main(){
  int t;
  cin >> t;
  for ( int i = 0; i < t; i++ ){
    read();
    work();
  }
}
// @end_of_source_code
