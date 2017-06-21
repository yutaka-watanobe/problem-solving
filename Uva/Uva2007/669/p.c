// @JUDGE_ID:  17051CA  669  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
#include<stl.h>

#define MAX 10000
#define EMPTY 0

int N, K;
int S[MAX+1];
int E[MAX+1];
multimap<int, int> M;

int read(){
  cin >> N >> K;
  
  fill ( S, S+N+1, EMPTY );
  fill ( E, E+N+1, EMPTY );
  M = multimap<int, int>();

  int k, l, start;
  start = 1;
  for ( int i = 1; i <= K; i++ ){
    cin >> k;
    for ( int j = 0; j < k; j++ ){
      cin >> l;
      S[l] = i;
      M.insert(pair<int,int>(i, l));
    }
    for ( int j = start; j < start+k; j++ ){
      E[j] = i;
    }
    start += k;
  }

  for ( int i = 1; i <= N; i++ ) cout << S[i] << " ";
  cout << endl;
  for ( int i = 1; i <= N; i++ ) cout << E[i] << " ";
  cout << endl;

  multimap<int, int>::iterator pos;
  
  for ( pos = M.begin(); pos != M.end(); pos++ ){
    cout << (*pos).first << " " << (*pos).second << endl;
  }
}

void work(){
  int empty;
  for ( int i = N; i >= 1; i-- ){
    if ( S[i] == EMPTY ){
      empty = i;
      break;
    }
  }

  




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
