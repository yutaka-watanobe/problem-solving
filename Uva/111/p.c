// @JUDGE_ID:  17051CA  111  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

#define TOPLEFT 0
#define TOP 1
#define LEFT 2

int lcs(vector<int> &x, vector<int> &y){
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

int n;


void work(){
  cin >> n;
  int k;
  vector<int> ans, st;
  ans.resize(n);
  st.resize(n);
  for(int i=0; i<n; i++){
    cin >> k;
    ans[k-1] = i;
  }

  while(1){
    for(int i=0; i<n; i++){
      cin >> k;
      st[k-1] = i;
      if(cin.eof()) return;
    }
    cout << lcs(ans, st) << endl;
  }

}

main(){
  work();
}
// @end_of_source_code
