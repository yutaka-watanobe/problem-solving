// @JUDGE_ID:  17051CA  10295  C++
// @begin_of_source_code
/* ·×»» */
#include<stdio.h>
#include<iostream>
#include<string>
#include<map>

void work(){
  int m, n;
  map<string, int> mp;

  cin >> m >> n;

  string str;
  int k;
  for(int i=0; i<m; i++){
    cin >> str >> k;
    mp[str] = k;
  }

  for(int i=0; i<n; i++){
    long sum = 0;
    while(1){
      cin >> str;
      if(str==".")  break;
      sum += mp[str];
    }
    cout << sum << endl;
  }
}

main(){
  work();
}
// @end_of_source_code
