// 11597:Spanning Subtrees:1.0: /2
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#include<cassert>

using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)

main(){
  int n;
  int t = 1;
  while( cin >> n && n ){
    cout << "Case " << t++ << ": ";
    cout << n/2 << endl;
  }
}

