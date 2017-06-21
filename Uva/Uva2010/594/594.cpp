// 594:One Little, Two Little, Three Little Endians:1.5:Conversion
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

typedef long long llong;

void reverse(int bit[32]){
   rep(i, 32){ bit[i] = ((bit[i]==1)?0:1); }
    int i = 0;
    while( bit[i] == 1 ){ bit[i] = 0;  i++;}
    bit[i] = 1;
}

int convert(int x){
  if ( x == 0 ) return 0;
  if ( x == -2147483648 ) return 128; // special case for this buggy prog.
  int bit[32], tmp[32];
  bool neg = false;
  if ( x < 0 ){ neg = true; x *= (-1); }
  rep(i, 32) bit[i] = 0;
  for ( int i = 0; i < 32; i++ ){
    bit[i] = x%2; x/=2;
  }

  if ( neg) reverse(bit);

  rep(i, 32) tmp[i] = bit[i];
  for ( int i = 0; i < 32; i+=8){
    int s = 24-i;
    for ( int j = s; j < s + 8; j++ ) bit[j] = tmp[i+j-s];
  }

  neg = false;
  if ( bit[31] == 1 ) { reverse(bit); neg = true; }

  int v = 0, p = 1;
  for ( int i = 0; i < 32; i++ ){
    if ( bit[i] ) v += p;
    p *= 2;
  }

  if ( neg ) v *= -1;
  return v;

}

main(){
  int x;
  while( cin >> x ) cout << x << " converts to " << convert(x) << endl;
}
