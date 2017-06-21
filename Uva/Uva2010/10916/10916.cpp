// 10916:Factstone Benchmark:2.0:Math
// log2(10!) = log2(1) + log2(2) + ... log2(10)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>

using namespace std;

#define REP(i, b, e) for( int i = b; i < n; i++ )
#define rep(i, n) REP(i, n)
typedef long long llong;

int compute(llong bit){
  int i = 1;
  double sum = 0;
  int ans = 0;
  while(1){
    sum += log2(i);
    if ( (int)sum > bit ) return ans;
    ans = i;
    i++;
  }
}

main(){
  llong y, bit;
  while( cin >> y && y ){
    bit = (1<<((y - 1960)/10 + 2));
    cout << compute(bit-1) << endl;
  }
}
