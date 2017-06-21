// @JUDGE_ID:  17051CA  729  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stl.h>


void work(){
  int n, h;
  cin >> n >> h;

  vector<int> v;
  v.clear();
  for(int i=0; i<n; i++){
    if(i>=n-h) v.push_back(1);
    else v.push_back(0);
  }

  do{
    for(int i=0; i<n; i++){
      cout << v[i];
    }
    cout << endl;
  }while(next_permutation(v.begin(), v.end()));
}

main(){
  int testCase;
  cin >> testCase;
  for(int i=0; i<testCase; i++){
    if(i!=0) cout << endl;
    work();
  }
}
// @end_of_source_code
