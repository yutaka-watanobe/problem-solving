// @JUDGE_ID:  17051CA  231  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

int lis(vector<int> &v){
  vector<int> l;
  l.resize(v.size());
  l[0] = 0;
  for(int i=0; i<v.size(); i++){
    int m = 0;
    for(int j=0; j<i; j++){
      if(v[j]>v[i] && m<l[j]){
	m = l[j];
      }
    }
    l[i] = m + 1;
  }

  return *max_element(l.begin(), l.end());
}

vector<int> v;

int read(){
  int k;
  v.clear();
  while(1){
    cin >> k;
    if(v.size()==0 && k==-1) return 0;
    if(v.size()>0 && k==-1) return 1;
    v.push_back(k);
  }
}

void work(){
  cout << "  maximum possible interceptions: " << lis(v) << endl;
}

main(){
  for(int i=1; read(); i++){
    cout << "Test #" << i << ":" << endl;
    work();
    cout << endl;
  }
}
// @end_of_source_code
