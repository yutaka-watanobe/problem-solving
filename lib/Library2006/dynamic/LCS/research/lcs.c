/******************************
 * Longest Common Subsequence *
 * by C++                     *
 ******************************/
#include<stdio.h>
#include<vector>
#include<string>

#define TOPLEFT 0
#define TOP 1
#define LEFT 2

class LongestCommonSubsequence{
 public:
  string X, Y, Z;
  vector<vector<int> > T, P;
  int longestLength;

  LongestCommonSubsequence(){}

  void input(){
    cin >> X >> Y;
    X = ' ' + X;
    Y = ' ' + Y;
  }
  
  void computeLCS(){
    int n, m;

    n = X.size();
    m = Y.size();
    
    T.resize(n, vector<int>(m));
    P.resize(n, vector<int>(m));
    
    for ( int i = 0; i < n; i++ ) T[i][0] = 0;
    for ( int j = 0; j < m; j++ ) T[0][j] = 0;
    
    for ( int i = 1; i < n; i++ ){
      for ( int j = 1; j < m; j++ ){
	if ( X[i] == Y[j] ){
	  T[i][j] = T[i-1][j-1] + 1;
	  P[i][j] = TOPLEFT;
	} else if ( T[i-1][j] >= T[i][j-1] ){
	  T[i][j] = T[i-1][j];
	  P[i][j] = TOP;
	}else{
	  T[i][j] = T[i][j-1];
	  P[i][j] = LEFT;
	}
      }
    }

    longestLength = T[n-1][m-1];
    Z.resize(T[n-1][m-1]);
    parseLCS( n-1, m-1, Z.size()-1);
  }

  void parseLCS( int i, int j, int k ){
    if ( i==0 || j==0 ) return;

    if ( P[i][j] == TOPLEFT ){
      parseLCS( i-1, j-1, k-1 );
      Z[k] = X[i];
    } else if ( P[i][j] == TOP) {
      parseLCS( i-1, j, k );
    }else{
      parseLCS( i, j-1, k );
    }
  }

  void output(){
    cout << "Longest Common Subsequence of " << X << " and " << Y << "." << endl;
    cout << Z << " (length " << longestLength << ")." << endl;
  }

};

int main(){
  LongestCommonSubsequence LCS;

  string str1, str2;

  LCS = LongestCommonSubsequence();

  LCS.input();
  LCS.computeLCS();
  LCS.output();

  return 1;
}
