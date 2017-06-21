#include<iostream>
#include<algorithm>
using namespace std;

static const int N = 100;

void pr(int s[N+1][N+1], int i , int j ){
  if ( i == j ) cout << "A" << i;
  else {
    cout << "(";
    pr(s, i, s[i][j]);
    pr(s, s[i][j]+1, j);
    cout << ")";
  }
}

main(){
  int n, p[N+1], m[N+1][N+1],s[N+1][N+1];
  cin >> n;
  for ( int i = 1; i <= n; i++ ){
    cin >> p[i-1] >> p[i];
  }

  for ( int i = 1; i <= n; i++ ) m[i][i] = 0;
  for ( int l = 2; l <= n; l++ ){
    for ( int i = 1; i <= n-l+1; i++ ){
      int j = i+l-1;
      m[i][j] = (1<<21);
      for ( int k = i; k <= j-1; k++ ){
	if ( m[i][j]> m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]) s[i][j] = k;
	m[i][j] = min(m[i][j], m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]);
	/*

	cout << "m[" << i << "," << j << "] = ";
	cout << "m[" << i << "," << k << "] + ";
	cout << "m[" << k+1 << "," << j << "] + ... = ";
	cout << m[i][j] << endl;
	*/

	
      }
      cout << endl;
    }
  }
  

  cout << m[1][n] << endl;
  pr(s, 1, n);
  cout << endl;
  
}
