// @JUDGE_ID:  17051CA  10152  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<stl.h>

string line;
vector<string> S, V;
map<string, int> M;
int m;

int read(){
  getline( cin, line );
  m = atoi ( line.c_str() );

  S.clear();
  V.clear();
  S.resize(m);
  V.resize(m);
  M = map<string, int>();

  for ( int i = 0; i < m; i++ ){
    getline( cin, line );
    S[i] = line;
  }

  for ( int i = 0; i < m; i++ ){
    getline( cin, line );
    V[i] = line;
    M[line] = i;
  }

}

void work(){

  vector<int> L, G;

  vector<int> T;
  T.resize( m );

  for ( int i = 0; i < m; i++ ){
    T[i] = M[ S[i] ];
  }

  int source = 0;
  
  while ( 1 ){
    bool f = false;
    source = 0;
    for ( int i = 0; i < T.size(); i++ ){
      if ( T[i] < source ){
	L.push_back( T[i] );
	T.erase( T.begin() + i );
	i--;
	f = true;
      }
      else {
	source = T[i];
      }
    }
    sort( L.begin(), L.end(), greater<int>() );
    for ( int i = 0; i < L.size(); i++ ){
      G.push_back( L[i] );
      T.insert( T.begin(), L[i] );
    }
    L.clear();
    if ( !f ) break;
  }

  for ( int i = 0; i < G.size(); i++ ){
    cout << V[ G[i] ] << endl;
  }

}

main(){
  getline( cin, line );
  int t;
  t = atoi ( line.c_str() );
  for ( int i = 0; i < t; i++ ){
    if ( i ) cout << endl;
    read();
    work();
  }
}
// @end_of_source_code
