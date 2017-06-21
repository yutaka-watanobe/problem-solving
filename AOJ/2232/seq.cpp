#include<iostream>
#include<vector>
using namespace std;

main(){
  int n;
  vector<int> v;
  int k;
  cin >> n;
  for ( int i = 0; i < n; i++ ){
    cin >> k;
    v.push_back(k);
  }

  int j = 0;
  int cnt = 1;
  while( j < v.size() ){
    int s = j;
    while ( j+1 < v.size() && v[j] == v[j+1] ){ j++; cnt++;}
    cout << v[s] << ":" << cnt << endl;
    cnt = 1;
    j++;
  }
  cout << endl;
}
