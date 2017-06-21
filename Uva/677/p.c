// @JUDGE_ID:  17051CA  677  C++
// @begin_of_source_code
/* Graph DFS */
/* Good Problem for path length */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#define MAX 12

int M[MAX][MAX];
int N, n;
vector<vector<int> > P;
vector<int> current;
int U[MAX];
int read(){
  cin >> N >> n;
  if ( cin.eof() ) return 0;
  for ( int i = 0; i < N; i++ ){
    for ( int j = 0; j < N; j++ ){
      cin >> M[i][j];
    }
  }
  int damy;
  cin >> damy;
  P.clear();
  return 1;
}

void dfs( int i, int len ){
  if ( len == n ){
    P.push_back( current );
    return ;
  }

  for ( int j = 0; j < N; j++ ){
    if ( M[i][j] && !U[j]){
      current.push_back( j );
      U[j] = 1;
      dfs( j, len+1 );
      U[j] = 0;
      current.erase( current.begin() + current.size() - 1 );
    }
  }


}

void work(){
  current.clear();
  fill ( U, U + MAX, 0 );
  U[0] = 1;
  current.push_back ( 0 );
  dfs ( 0, 0 );

  if ( P.size() == 0 ){
    cout << "no walk of length " << n << endl;
  }else{
    for ( int i = 0; i < P.size(); i++ ){
      cout << "(";
      for ( int j = 0; j < P[i].size(); j++ ){
	if ( j ) cout << ",";
	cout << P[i][j] + 1;
      }
      cout << ")" << endl;
    }
  }
}

main(){
  for (int i = 0;  read(); i++ ){
    if ( i ) cout <<  endl;
    work();
  }
}
// @end_of_source_code
