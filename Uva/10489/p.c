// @JUDGE_ID:  17051CA  10489  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>

typedef unsigned long long ullong;

void work(){
  int N, B, K, ai;
  cin >> N >> B;
  ullong sum = 0;
  ullong mul = 1;
  for(int i=0; i<B; i++){
    cin >> K;
    mul = 1;
    for(int j=0; j<K; j++){
      cin >> ai;
      mul *= ai;
      mul = mul%N;
    }
    if(K==0) mul = 0;
    sum += mul;
  }
  
  cout << sum%N << endl;
}

main(){
  int n;
  cin >> n;
  for(int i=0; i<n; i++) work();
}
// @end_of_source_code
