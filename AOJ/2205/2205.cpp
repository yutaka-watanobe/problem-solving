#include<iostream>
#include<string>
using namespace std;
#define MAX 100

bool check( string target, string s ){
  for ( int i = 0; i < target.size(); i++ ){
    if ( target[i] == '*' ) continue;
    if ( target[i] != s[i] ) return false;
  }
  return true;
}

main(){
  int n, m;
  string code;
  pair<string, int> R[MAX];
  while( cin >> n >> m && n &&m ){
    for ( int i = 0; i < n; i++ ){
      cin >> R[i].first >> R[i].second;
    }
    int sum = 0;
    for ( int i = 0; i < m; i++ ){
      cin >> code;
      for ( int j = 0; j < n; j++ ){
	if ( check(R[j].first, code) ) sum += R[j].second;
      }
    }
    cout << sum << endl;
  }
}
