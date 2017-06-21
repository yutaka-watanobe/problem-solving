// @JUDGE_ID:  17051CA  10038  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

int n;

int read(){
  cin >> n;
  if(cin.eof()) return 0;
  return 1;
}

void work(){
  vector<bool> v;
  v.resize(n, false);

  int pre, k, sub;

  cin >> pre;
  for(int i=1; i<n; i++){
    cin >> k;
    sub = abs(k-pre);
    if( (1 <=  sub && sub <= n-1) ){
      v[sub] = true;
    }
    pre = k;
  }

  for(int i=1; i<v.size(); i++){
    if(!v[i]){
      cout << "Not jolly" << endl;    
      return;
    }
  }
  cout << "Jolly" << endl;

}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
