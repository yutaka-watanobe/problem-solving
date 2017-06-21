#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
static const int N = 100;

int lcs(string s1, string s2){
  int c[N+1][N+1];
  int m = s1.size();
  int n = s2.size();
  int maxl = 0;
  s1 = ' ' + s1;
  s2 = ' ' + s2;
  for ( int i = 1; i <= m; i++ ) c[i][0] = 0;
  for ( int j = 1; j <= n; j++ ) c[0][j] = 0;

  for ( int i = 1; i <= m; i++ ){
    for ( int j = 1; j <= n; j++ ){
      if ( s1[i] == s2[j] ){
	c[i][j] = c[i-1][j-1] + 1;
      } else {
	c[i][j] = max(c[i-1][j], c[i][j-1]);
      }
      maxl = max(maxl, c[i][j]);
    }
  }

  return maxl;
}

main(){
  string s1, s2;
  cin >> s1 >> s2;
  cout << lcs(s1, s2) << endl;
}
