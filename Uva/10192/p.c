// @JUDGE_ID:  17051CA  10192  C++
// @begin_of_source_code
/* L C S !!*/
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

  /*l.resize(c[m][n]);*/
  /*  printLcs(l, b, x, m, n, l.size()-1);*/
  return c[m][n];
}

string line1, line2;

int read(){
  getline(cin, line1);
  if(line1[0]=='#') return 0;
  getline(cin, line2);
  return 1;
}

void work(){
  string l;
  cout << "you can visit at most " << lcs(line1, line2, l) << " cities." << endl;

}
main(){
  for(int i=1; read(); i++){
    cout << "Case #" << i << ": ";
    work();
  }
}
// @end_of_source_code
