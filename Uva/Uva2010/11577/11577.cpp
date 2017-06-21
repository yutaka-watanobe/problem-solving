// 11577:Letter Frequency:0.5:Count
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#include<cassert>
#include<cstring>

using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)

void compute(){
  string line;
  int cnt[255];
  rep(i, 255) cnt[i] = 0;
  getline(cin, line);
  
  rep(i, line.size()){
    char ch = line[i];
    if ( 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z' ){
      ch = tolower(ch);
      cnt[ch]++;
    }
  }
  int maxv = 0;
  rep(i, 255) maxv = max(maxv, cnt[i]);

  rep(i, 255){
    if ( cnt[i] == maxv ) cout << (char)i;
  }
  cout << endl;


}

main(){
  int t; cin>> t;
  string line; getline(cin, line);
  rep(i, t) compute();
}
