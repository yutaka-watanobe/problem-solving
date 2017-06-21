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

int simulate(int n){
  if ( n == 1 ) return 1;

  vector<int> v;
  for ( int i = 1; i <= n; i++ ) v.push_back(i);
  int t;

  while(v.size() > 1){
    v.erase(v.begin());
    t = v[0];
    v.erase(v.begin());
    v.push_back(t);


  }
  return t;
}


main(){

  for ( int i = 1; i <= 100; i++ ){
    cout << i << "  " << simulate(i) << endl;
  }
  

}
