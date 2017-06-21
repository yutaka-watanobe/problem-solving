// @JUDGE_ID:  17051CA  10460  C++
// @begin_of_source_code
/* Permutation */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

string line;
int index;

void read(){
  cin >> line >> index;
}

void work(){
  vector<int> P; /* path */
  int pos = index - 1;
  int q, r;
  int len;

  for ( int i = line.size() - 1; i >= 1; i-- ){
    len = i + 1;
    q = pos / len;
    r = pos % len;
    P.push_back( r );
    pos = q;
  }

  string ans = "";
  ans += line[0];

  reverse( P.begin(), P.end() );
  int j = 1;
  for ( int i = 0; i < P.size(); i++ ){
    ans.insert( ans.begin() + P[i], line[j++] );
  }

  cout << ans << endl;
}

main(){
  int t;
  cin >> t;
  for ( int i = 0; i < t; i++ ){
    read();
    work();
  }
}
// @end_of_source_code
