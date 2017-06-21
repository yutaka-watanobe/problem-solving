// @JUDGE_ID:  17051CA  10165  C++
// @begin_of_source_code
/* ©Тою */
/* MIN Game */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

void createBit( int a, vector<int> &bit ){
  bit.clear();
  int next;
  while(a>0 ){
    bit.push_back( a%2 );
    a = a/2;
  }
 reverse(bit.begin(), bit.end());
}

vector<vector<int> > v;
vector<int> input;

int n;

int read(){
  cin >> n;
  if(n==0) return false;
  
  int k, M;
  M = 0;
  vector<int> bit;
  v.clear();
  for(int i=0; i<n; i++){
    cin >> k;
    bit.clear();
    createBit(k, bit);
    v.push_back(bit);
    int s = bit.size();
    M = max(M, s);
  }

  for(int i=0; i<v.size(); i++){
    while(v[i].size() < M){
      v[i].insert(v[i].begin(), 0);
    }
  }

  return true;
}

void work(){

  int sum;
  for(int j=0; j<v[0].size(); j++){
    sum = 0;
    for(int i=0; i<v.size(); i++){
      if(v[i][j]) sum++;
    }
    if(sum%2!=0){
      cout << "Yes" << endl;
      return;
    }
  }

  cout << "No" << endl;
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
