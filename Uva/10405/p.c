// @JUDGE_ID:  17051CA  10405  C++
// @begin_of_source_code
/* LCS */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#define TOPLEFT 0
#define TOP 1
#define LEFT 2

int lcs(string &x, string &y, string &l){
  int m, n;
  vector<vector<int> > c, b;
  m = x.size();
  n = y.size();

  c.resize(m+1, vector<int>(n+1));
  b.resize(m+1, vector<int>(n+1));

  for(int i=0; i<=m; i++) c[i][0] = 0;
  for(int j=0; j<=n; j++) c[0][j] = 0;

  for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
      if(x[i-1]==y[j-1]){
	c[i][j] = c[i-1][j-1]+1;
	b[i][j] = TOPLEFT;
      }else if(c[i-1][j]>=c[i][j-1]){
	c[i][j] = c[i-1][j];
	b[i][j] = TOP;
      }else{
	c[i][j] = c[i][j-1];
	b[i][j] = 0;
      }
    }
  }

  return c[m][n];

}

string s1, s2;

int read(){
  getline(cin, s1);
  if(cin.eof()) return 0;
  getline(cin, s2);
  return 1;
}

void work(){
  string s3;
  cout << lcs(s1, s2, s3) << endl;
}

int main(){
  while(read()){
    work();
  }
  return 0;
}
// @end_of_source_code
