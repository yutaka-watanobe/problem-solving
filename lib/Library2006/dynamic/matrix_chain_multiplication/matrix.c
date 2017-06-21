/********************************
 * Matrix chain product Problem *
 * Dynamic Programming          *
 ********************************/

#include<stdio.h>
#include<iostream>
#include<vector>
#include<stl.h>

int n; /* number of matrix */
vector<int> p; /* element i.e. A is p0*p1 matrix */
vector<vector<int> > m;
vector<vector<int> > s;

/**
 * *note that, element of m and s and matrix A? start with 1 not 0.
 * Solved 348,
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
    print_optimal_parens(s[i][j]+1, j);
    cout << ")";
  }
}

int read(){
  int k;
  p.clear();
  while(1){
    cin >> k;
    if(cin.eof()) return false;
    p.push_back(k);
  }
  return true;
}

int main(){
  read();

  matrix_chain_order();
  print_optimal_parens(1, n);
  cout << endl;

  return 0;
}
