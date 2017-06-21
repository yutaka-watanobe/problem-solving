// @JUDGE_ID:  17051CA  10066  C++
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

int N1, N2;
vector<int> v1, v2;

int read(){
  cin >> N1 >> N2;
  if(N1==0 && N2==0) return 0;
  v1.resize(N1);
  v2.resize(N2);
  for(int i=0; i<N1; i++) cin >> v1[i];
  for(int i=0; i<N2; i++) cin >> v2[i];
  return 1;
}



main(){
  for(int i=1; read(); i++){
    cout << "Twin Towers #" << i << endl;
    cout << "Number of Tiles : " << lcs(v1, v2) << endl;
    cout << endl;
  }
}
// @end_of_source_code
