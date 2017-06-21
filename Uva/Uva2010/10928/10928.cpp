// 10928:My Dear Neightbours:1.0:Input,Line,Sort
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>

using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)


void compute(){
  string line; getline(cin, line);
  getline(cin, line);
  int n = atoi(line.c_str());

  vector<pair<int, int> > v;
  rep(i, n){
    getline(cin, line);
    int c = 0;
    rep(j, line.size()) if ( line[j] == ' ' ) c++;
    c++;
    v.push_back(make_pair(c, i+1) );
  }
  
  sort(v.begin(), v.end());
  vector<int> ans;
  ans.push_back(v[0].second);
  for ( int i = 1; i < v.size(); i++ ){
    if ( v[i].first != v[0].first ) break;
    ans.push_back(v[i].second);
  }

  for ( int i = 0; i < ans.size() ;i++ ){
    if ( i ) cout << " ";
    cout << ans[i];
  }
  cout << endl;
  
}

main(){
  int tcase; cin>> tcase;
  rep(t, tcase) compute();
}
