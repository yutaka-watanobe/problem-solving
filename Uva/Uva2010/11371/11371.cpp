// 11371:Number Theory for Newbies:1.5:String, Number Theory
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

typedef long long llong;

llong convert(string str){
  llong p = 1;
  llong sum = 0;
  for ( int i = str.size()-1; i >= 0;i--){
    sum += p* (str[i]-'0');
    p *= 10;
  }
  return sum;
}

void compute(string num){
  string maxv, minv;
  maxv = num;
  minv = num;
  sort(minv.begin(), minv.end());
  sort(maxv.begin(), maxv.end());
  reverse(maxv.begin(), maxv.end());

  if ( atoi(minv.c_str()) != 0 ){
    int p = 0;
    while( minv[p] == '0' ) p++;
    char top = minv[p];
    for ( int i = p; i > 0; i-- ) minv[i] = minv[i-1];
    minv[0] = top;
  }
  
  llong minv_i = convert(minv);
  llong maxv_i = convert(maxv);
  llong sum = maxv_i - minv_i;
  cout << maxv_i << " - " << minv_i << " = " << sum << " = 9 * " << sum/9 << endl;
}

main(){
  string num;
  while( cin >> num ) compute(num);
}

