#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

#define TOPLEFT 0
#define TOP 1
#define LEFT 2
#define MAX 2000

void printLcs(string &l, vector<vector<short> > &b, const string &x, int i, int j, int k){
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
  vector<vector<short> > c, b;
  m = x.size();
  n = y.size();

  c.resize(m+1, vector<short>(n+1));
  b.resize(m+1, vector<short>(n+1));
  
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

int main(){
    string s1, s2, l;
    while( cin >> s1 ){
	s2 = s1;
	reverse(s2.begin(), s2.end());
	lcs(s1, s2, l);
	cout << l << endl;
    }
    return 0;
}

