// @JUDGE_ID:  17051CA  531  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<stl.h>

#define TOPLEFT 0
#define TOP 1
#define LEFT 2

class Compromise{
 public:
  vector<string> word1, word2;

  void printLcs( vector<string> &l, const vector<vector<int> > &b, 
		 const vector<string> &x, int i, int j, int k){
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
  
  void lcs( vector<string> &x, vector<string> &y, vector<string> &l){
    int m, n;

    vector<vector<int> > c, b;
    m = x.size();
    n = y.size();
    
    c.resize( m+1, vector<int>(n+1) );
    b.resize( m+1, vector<int>(n+1) );
    
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
    
    l.resize( c[m][n]);
    
    printLcs(l, b, x, m, n, l.size()-1);
    
  }

  void work(){
    vector<string> l;
    lcs( word1, word2, l );

    if ( l.size() ){
      for ( int i = 1; i < l.size(); i++ ) {
	if ( i > 1) cout << " ";
	cout << l[i];
      }
    }
    cout << endl;
  }

  bool read(){
    word1.clear();
    word2.clear();
    string word;

    char ch;

    string line;
    
    word1.push_back( "" );
    word2.push_back( "" );

    while ( 1 ){
      if ( !( cin >> line ) ) return false;
      if ( line == "#" ) break;
      word1.push_back( line );
    }
    
    while ( 1 ){
      cin >> line;
      if ( line == "#" ) break;
      word2.push_back( line );
    }

    return true;
  }
  
};


main(){
  Compromise C;
  for ( int i = 0; C.read(); i++ ){
    C.work();
  }
}

// @end_of_source_code
