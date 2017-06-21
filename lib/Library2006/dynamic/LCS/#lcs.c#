/*********
 * L C S *
 *********/
#include<stdio.h>
#include<vector>
#include<string>

#define TOPLEFT 0
#define TOP 1
#define LEFT 2

void printLcs(string &l, const vector<vector<int> > &b, const string &x, int i, int j, int k){
  if(i==0 || j==0) return;
  if(b[i][j]==TOPLEFT){
    printLcs(l, b, x, i-1, j-1, k-1);
    l[k] = x[i-1];
  }else if(b[i][j]==TOP){
    printLcs(l, b, x, i-1, j, k);
  }else{
    printLcs(l, b, x, i, j-1, k);
  }
}

void lcs(string &x, string &y, string &l){
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
	b[i][j] = LEFT;
      }
    }
  }

  l.resize(c[m][n]);

  printLcs(l, b, x, m, n, l.size()-1);

}

main(){
  string s1 = "ABCBDAB";
  string s2 = "BDCABA";

  string l;
  lcs(s1, s2, l);

  cout << l.size() << endl;
  for(int i=0; i<l.size(); i++) cout << l[i] << " ";
  cout << endl;
  

}
