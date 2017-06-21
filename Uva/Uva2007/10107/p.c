// @JUDGE_ID:  17051CA  10107  C++
// @begin_of_source_code
/* lower_bound を使う！！ */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>

int n;

int read(){
  cin >> n;
  return cin.eof() ? false : true;
}

void work(){
  vector<int> v;
  int i = 0;
  while(read()){
    v.insert(lower_bound(v.begin(), v.end(), n), n);
    i++;
    if(v.size()%2==0) cout << (v[i/2] + v[i/2-1])/2 << endl;
    else cout << v[i/2] << endl;
  }
}

main(){
  work();
}
// @end_of_source_code
