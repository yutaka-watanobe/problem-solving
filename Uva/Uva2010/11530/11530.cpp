// 11530:SMS Typing:1.0:Writing
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

int T[255];

int compute(string line){
  int sum = 0;
  rep(i, line.size()){
    sum += T[line[i]];
  }
  return sum;
}

void init(){
  string S[8] ={"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  T[' '] = 1;
  rep(i, 8){
    string str = S[i];
    rep(j, str.size() ) T[str[j]] = j+1;
  }
}

main(){
  init();
  string line;
  int t; cin >> t;
  getline(cin, line);
  rep(i, t) {
    getline(cin, line);
    cout << "Case #" << i+1 << ": " << compute(line) << endl;
  }
}
