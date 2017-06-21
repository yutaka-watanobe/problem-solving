// @JUDGE_ID:  17051CA  10503  C++
// @begin_of_source_code
/* Simulation + Recursion */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

int N, M;

vector<pair<int, int> > D;
pair<int, int> L, R;
bool able;

int read(){
  D.clear();
  cin >> N >> M;
  if ( N == 0 ) return 0;
  
  int a, b;

  cin >> a >> b;
  
  L = pair<int, int>(a, b);

  cin >> a >> b;

  R = pair<int, int>(a, b);

  for ( int i = 0; i < M; i++ ){
    cin >> a >> b;
    D.push_back( pair<int, int>(a, b) );
  }

  return 1;
}

void parse( int pre, vector<pair<int, int> > d , int n){

  if( n == N ){
    if ( pre == R.first ){
      able = true;
      return;
    }
  }
  
  vector<pair<int, int> > tmp;

  for ( int i = 0; i < d.size(); i++ ){
    if ( d[i].first == pre ){
      tmp = d;
      tmp.erase( tmp.begin() + i );
      parse( d[i].second, tmp, n+1 );
    }
    if ( d[i].second == pre ){
      tmp = d;
      tmp.erase( tmp.begin() + i );
      parse( d[i].first, tmp, n+1 );
    }
  }
}

void work(){
  able = false;

  parse( L.second, D, 0);
  
  if ( able ){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

main(){
  while( read() ){
    work();
  }
}
// @end_of_source_code
