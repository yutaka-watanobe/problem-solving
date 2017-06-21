// @JUDGE_ID:  17051CA  484  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>

void work();

void work(){
  long n;
  map<long, int> mp;
  vector<long> v;
  v.clear();
  while(1){
    cin >> n;
    if(cin.eof()) break;
    
    if(mp[n] == 0 ) v.push_back(n);
    mp[n]++;
  }

  for(int i=0; i<v.size(); i++){
    cout << v[i] << " " << mp[v[i]] << endl;
  }

}

main(){
  work();
}
// @end_of_source_code
