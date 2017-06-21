// @JUDGE_ID:  17051CA  10190  C++
// @begin_of_source_code
/* Number Judge */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

long long n, m;

int read(){
  cin >> n >> m;
  return (cin.eof() ? false : true);
}

void work(){
  vector<long> v;

  if(n == 0 || m == 0 || n == 1 || m == 1 || (n == 1 && m == 1) ) {
    cout << "Boring!" << endl;
    return;
  }

  while(1){
    v.push_back(n);

    if(n==1) break;

    if(n%m!=0 || !(n>n/m)){
      cout << "Boring!" << endl;
      return;
    }
    n = n/m;
  }

  for(int i=0; i<v.size(); i++){
    if(i!=0) cout << " ";
    cout << v[i];
  }
  cout << endl;
}

main(){
  while(read()) work();
}
// @end_of_source_code
