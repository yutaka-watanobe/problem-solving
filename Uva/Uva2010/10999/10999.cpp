// 10999:Crabbles:2.5:Recursive + binary search (set)
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
#define MAX 100000
#define PMAX 10

//string D[MAX]; // dic
set<string> D;
int n, p, maxv;
pair<char, int> P[PMAX];

void rec( int cur, string path, int sum){
  if ( cur >= p ) {
    sort(path.begin(), path.end());
    if ( D.find(path) != D.end() ) maxv = max(maxv, sum);
    return;
  }

  rec(cur+1, path, sum);
  rec(cur+1, path + P[cur].first, sum + P[cur].second);

}

int compute(){
  maxv = 0;
  cin >> p;
  rep(i, p) cin >> P[i].first >> P[i].second;
  rec(0, "", 0);
  cout << maxv << endl;
}

main(){
  string word;
  int nhand;
  while( cin >> n ){
    D.clear();
    rep(i, n){
      cin >> word;
      sort(word.begin(), word.end());
      //      D[i] = word;
      D.insert(word);
    }
    cin >> nhand;
    rep(i, nhand){
      compute();
    }
  }
}
