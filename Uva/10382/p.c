// @JUDGE_ID:  17051CA  10382  C++
// @begin_of_source_code
/* Dynamic Programming */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
#include<cmath>

int n;
double l, w;
vector<pair<double, double> > S;

int read(){
  double d, pos, r;
  cin >> n >> l >> w;
  if ( cin.eof() ) return 0;
  S.clear();

  for ( int i = 0; i < n; i++ ){
    cin >> pos >> r;
    d = sqrt( r*r - (w/2)*(w/2) );
    S.push_back( make_pair( pos - d, pos + d ) );
  }

  sort( S.begin(), S.end() );
  return 1;
}

int minimum_coverage(){
  vector<double> L;

  L.push_back( 0 );

  vector<double>::iterator pos;

  for ( int i = 0; i < S.size(); i++ ){
    pos = lower_bound( L.begin(), L.end(), S[i].first );

    if ( pos == L.end() ) return -1;

    if ( L[ L.size()-1 ] >= S[i].second ) continue;

    L.erase( pos + 1, L.end() );
    L.push_back( S[i].second );

    if ( L[ L.size() - 1 ] >= l ){
      return L.size() - 1;
    }
  }

  return -1;
}

void work(){
  cout <<  minimum_coverage() << endl;
}

main(){
  while ( read() ){
    work();
  }
}
// @end_of_source_code
