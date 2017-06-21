// @JUDGE_ID:  17051CA  10020  C++
// @begin_of_source_code
/* Dynamic Programming */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stl.h>

vector<pair<int, int> > S; /* Segment list */
int M;

void read(){
  cin >> M;
  int left, right;
  S.clear();
  while ( 1 ){
    cin >> left >> right;
    if ( left == 0 && right == 0 ) break;
    if ( left <= M-1 && right >= 1 && right - left >= 1 ){
      S.push_back( make_pair(left, right) ) ;
    }
  }
  sort( S.begin(), S.end() );
}

/* minimum coverage */
void minimum_coverage(){

  vector<int> L, P;

  L.push_back( 0 );
  P.resize( S.size() + 1, -1 );

  vector<int>::iterator pos;
  int index;
  int minimum = INT_MAX;
  
  for ( int i = 0; i < S.size(); i++ ){
    pos = lower_bound( L.begin(), L.end(), S[i].first );
    
    if ( pos == L.end() ){
      cout << "0" << endl;
      return;
    }

    if ( L[ L.size()-1 ] >= S[i].second ) continue;

    L.erase( pos + 1, L.end() );
    L.push_back( S[i].second );
    P[ L.size() - 1 ] = i;

    if ( L[ L.size() - 1 ] >= M ) {
      cout << L.size() - 1 << endl;
      for ( int i = 1; i < L.size(); i++ ){
	cout << S[ P[i] ].first << " " << S[ P[i] ].second << endl;
      }
      return;
    }
  }
  
  cout << "0" << endl;

}

void work(){
  minimum_coverage();
}

main(){
  int t;
  cin >> t;
  for ( int i = 0; i < t; i++ ){
    if ( i ) cout << endl;
    read();
    work();
  }
}

// @end_of_source_code
