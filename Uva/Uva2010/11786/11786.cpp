// 11786:Global Raining at Bidibibus:2.0:Stack
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<cmath>
#include<cassert>
#include<stack>

using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)

void compute(){
  string line; cin >> line;
  stack<int> S;
  int sum = 0;

  for ( int i = 0; i < line.size(); i++ ){
    char ch = line[i];

    if ( ch == '/' ){
      if ( !S.empty() ){
	int p = S.top(); S.pop();
	sum += (i-p);
      }
    } else if ( ch == '\\' ) {
      S.push(i);
    }
  }

  cout << sum << endl;
  
}

main(){
  int tcase; cin >> tcase;
  rep(t, tcase)  compute();
}
