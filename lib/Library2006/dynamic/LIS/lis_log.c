#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>

int lis(vector<int> &v){
  vector<int> l;
  l.resize(v.size());
  l[0] = 0;
  for(int i=0; i<v.size(); i++){
    int m = 0;
    for(int j=0; j<i; j++){
      if(v[j]<v[i] && m<l[j]){
	m = l[j];
      }
    }
    l[i] = m + 1;
  }

  return *max_element(l.begin(), l.end());
}

int n;
vector<int> v;

int read(){
  cin >> n;

  if ( cin.eof() ) return 0;
  v.clear();
  v.resize(n);
  for ( int i = 0; i < n; i++ ){
    cin >> v[i];
  }
  return 1;
}

main(){
  while ( read() ){
    cout << lis(v) << endl;; 
  }
}
