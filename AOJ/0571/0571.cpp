#include<iostream>
#include<vector>
#include<string>
using namespace std;

main(){
  string str; cin >> str;
  vector<pair<char, int> > v;
  str += 'X';
  int cnt = 1;
  char pre = str[0];
  for ( int i = 0; i < str.size(); i++ ){
    if ( pre != str[i] ){
      v.push_back(make_pair(pre, cnt));
      cnt = 1;
    } else {
      cnt++;
    }
    pre = str[i];
  }

  int maxv = 0;
  for ( int i = 0; i <= (int)v.size()-3; i++ ){
    if ( v[i].first == 'J' &&
	 v[i+1].first == 'O' &&
	 v[i+2].first == 'I' ){
      if ( v[i+1].second <= v[i].second &&
	   v[i+1].second <= v[i+2].second ){
	maxv = max(maxv, min(v[i].second, min(v[i+1].second, v[i+2].second)));
      }
    }
  }

  cout << maxv << endl;
  
}
