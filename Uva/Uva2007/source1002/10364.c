// @JUDGE_ID:  17051CA  10364  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<stl.h>

void work();
vector<int> v;

void work(){
  int n, k;
  cin >> n;
  v.clear();

  for(int i=0; i<n; i++){
    cin >> k;
    v.push_back(k);
  }
  sort(v.begin(), v.end());

  int sum, q;
  sum = 0;
  for(int i=0; i<v.size(); i++){
    sum += v[i];
  }
  
  if( sum%4 != 0 ){
    cout << "no" << endl;
    return;
  }

  q = sum/4;
  
  
}

main(){
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    work();
  }
}
// @end_of_source_code
