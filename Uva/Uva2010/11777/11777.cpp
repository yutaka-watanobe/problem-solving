// 11777:Automate the Grades:0.5:Writing
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

using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)

char compute(){
  int ct[3], x;
  int sum = 0;
  rep(i, 4){ cin >> x; sum += x; }
  rep(i, 3) cin >> ct[i];
  sort(ct, ct + 3 );
  sum += (ct[1] + ct[2])/2;

  if ( sum >= 90 ) return 'A';
  else if ( 80 <= sum && sum < 90 ) return 'B';
  else if ( 70 <= sum && sum < 80 ) return 'C';
  else if ( 60 <= sum && sum < 70 ) return 'D';
  return 'F';
}

main(){
  int t; cin >> t;
  rep(i, t) {
    cout << "Case " << i+1 << ": " << compute() << endl;
  }
}
