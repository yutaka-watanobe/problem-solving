// @JUDGE_ID:  17051CA  434  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>

int cube[8][8][8];
int front[8];
int right[8];
int n;

void read(){
  cin >> n;
  for(int i=0; i<n; i++) cin >> front[i];
  for(int i=0; i<n; i++) cin >> right[i];
}

void work(){
  int N, M, block;
  bool f[8], r[8];

  /* min */
  block = 0;

  for(int i=0; i<n; i++) {
    f[i] = false;
    r[i] = false;
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(r[j]) continue;
      if(front[i]==right[j]){
	block += front[i];
	f[i] = r[j] = true;
	goto next;
      }
    }
  next:;
  }

  for(int i=0; i<n; i++){
    if(!f[i]) block += front[i];
    if(!r[i]) block += right[i];
  }

  N = block;

  /* max */
  block = 0;

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      block += min(front[i], right[j]);
    }
  }

  M = block - N;

  cout << "Matty needs at least " << N << " blocks, and can add at most " << M << " extra blocks." << endl;
  
}

main(){
  int testCase;
  cin >> testCase;
  for(int i=0; i<testCase; i++){
    read();
    work();
  }
}
// @end_of_source_code
