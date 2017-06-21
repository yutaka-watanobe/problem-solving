// @JUDGE_ID:  17051CA  10404  C++
// @begin_of_source_code
/* ゲームシミュレーション */
/* 数論のように見えるが、DPによってn個目がWINかLOSEか順に決定していく */ 
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
#define MAX 1000000
int n, m;
int S[MAX+1];
int R[MAX+1];

int read(){
  cin >> n >> m;
  if(cin.eof()) return 0;
  else return 1;
}

void work(){
  fill(S, S+n, false);
  
  int maxR = 0;
  for(int i=0; i<m; i++){
    cin >> R[i];
    maxR = max(maxR, R[i]);
  }
  
  sort(R, R+m);

  S[0] = false;
  for ( int i = 1; i <= n; i++ ) {
    for ( int j = 0; j < m; j++ ) {
      if ( i < R[j] ) goto next;
      if ( S[i] = !S[i - R[j]] ) break;
    }
  next:;
  }
  
  if(S[n]) cout << "Stan wins" << endl;
  else cout << "Ollie wins" << endl;
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
