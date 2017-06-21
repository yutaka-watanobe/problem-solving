// @JUDGE_ID:  17051CA  348  C++
// @begin_of_source_code
/* Matrix chain maltiplication Problem */
/* Dynamic Programming */

#include<stdio.h>
#include<iostream>
#include<vector>
#include<stl.h>
#include<string>

int n; /* number of matrix */
vector<int> p; /* element i.e. A is p0*p1 matrix */
vector<vector<int> > m;
vector<vector<int> > s;

/**
 * *note that, element of m and s and matrix A? start with 1 not 0.
 */
void matrix_chain_order(){
  n = p.size()-1; /* number of matrix */
  m.resize(n+1);
  for(int i=1; i<=n; i++) m[i].resize(n+1, 0);
  s.resize(n+1);
  for(int i=1; i<=n; i++) s[i].resize(n+1, 0);

  for(int i=1; i<=n; i++) m[i][i] = 0;
  for(int l=2; l<=n; l++){ /* l is chain length */
    for(int i=1; i<=n-l+1; i++){
      int j = i + l -1;
      m[i][j] = INT_MAX;
      for(int k=i; k<=j-1; k++){
	int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
	if(q < m[i][j]){
	  m[i][j] = q;
	  s[i][j] = k;
	}
      }
    }
  }
}

void print_optimal_parens(int i, int j){
  if(i==j){
    cout << 'A' << i;
  }else{
    cout << "(";
    print_optimal_parens(i, s[i][j]);
    cout << " x ";
    print_optimal_parens(s[i][j]+1, j);
    cout << ")";
  }
}

int read(){
  cin >> n;
  if(n==0) return false;
  
  p.clear();

  int a, b;
  for(int i=0; i<n; i++){
    cin >> a >> b;
    if(i==0){
      p.push_back(a);
      p.push_back(b);
    }else if(i>0){
      p.push_back(b);
    }
  }

  return true;
}

int main(){
  for(int i=1; read(); i++){
    cout << "Case " << i << ": ";
    matrix_chain_order();
    print_optimal_parens(1, n);
    cout << endl;
  }
  return 0;
}

// @end_of_source_code
