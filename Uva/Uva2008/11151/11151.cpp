#include<iostream>
#include<string>
#include<vector>
using namespace std;

int lcs(string &x, string &y ){
  int m, n;
  vector<vector<int> > c;
  m = x.size();
  n = y.size();

  c.resize(m+1, vector<int>(n+1));
  
  for(int i=0; i<=m; i++) c[i][0] = 0;
  for(int j=0; j<=n; j++) c[0][j] = 0;

  for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
      if(x[i-1]==y[j-1]){
	c[i][j] = c[i-1][j-1]+1;
      }else if(c[i-1][j]>=c[i][j-1]){
	c[i][j] = c[i-1][j];
      }else{
	c[i][j] = c[i][j-1];
      }
    }
  }
  
  return c[m][n];
}

main(){
    int tcase; cin >> tcase;
    string str1, str2;
    getline(cin, str1);

    for ( int i = 0; i < tcase; i++ ){
	getline(cin, str1);
	str2 = str1;
	reverse( str2.begin(), str2.end() );
	cout << lcs(str1, str2 ) << endl;
    }
}
