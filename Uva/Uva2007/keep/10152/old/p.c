// @JUDGE_ID:  17051CA  10152  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<vector>

string line;
vector<int> G;
map<string, int> M;
vector<string> W;
int N;

void read(){
  getline( cin, line);
  N = atoi( line.c_str() );
  G.clear();
  G.resize(N);
  W.clear();
  W.resize(N);
  M = map<string, int>();

  for ( int i = 0; i < N; i++ ){
    getline( cin, line );
    W[i] = line;
    M[ line ] = i;
  }
  
  for ( int i = 0; i < N; i++ ){
    getline( cin, line );
    G[i] = M[ line ];
  }

}

void work(){
  vector<int> V;
  vector<int> S;
  V.resize( N );
  for ( int i = 0; i < N; i++ ) V[i] = i;

  queue<pair<vector<int>, vector<int> > > q;

  q.push( pair<vector<int>, vector<int> >(V, S));
  vector<int> u, v;
  vector<int> p, t;

  while ( !q.empty() ){

    u = q.front().first; 
    p = q.front().second;
    
    q.pop();

    if ( u == G ) break;

    for ( int i = 1; i < u.size(); i++ ){
      v = u;
      t = p;
      int k = v[i];
      v.erase( v.begin() + i );
      v.insert( v.begin(), k );

      t.push_back( u[i] );
      q.push( pair<vector<int>, vector<int> >(v, t) );
    }
    
  }

  for ( int i = 0; i < p.size(); i++ ){
    cout << W[ p[i] ] << endl;
  }

}

main(){
  int t;
  getline(cin, line);
  t = atoi( line.c_str() );
  for ( int i = 0; i < t; i++ ){
    read();
    work();
    cout << endl;
  }
}
// @end_of_source_code
