// @JUDGE_ID:  17051CA  10125  C++
// @begin_of_source_code
/* Set + Binary Search + Multimap */
/* 4.98 sec Not Good !! */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stl.h>
#define MAX 1001

int n;
int S[ MAX ];
multimap<int, pair<int, int> > M; /* sum */

bool read(){
  cin >> n;
  if ( n == 0 ) return false;
  for ( int i = 0; i < n ; i++ ){
    cin >> S[i];
  }

  return true;
}

void work(){
  sort( S, S + n );

  M = multimap<int, pair<int, int> >();

  for ( int i = 0; i < n - 1; i++ ){
    for ( int j = i + 1; j < n; j++ ){
      M.insert( make_pair(  S[i] + S[j], make_pair( S[i], S[j] ) ) );
    }
  }

  multimap<int, pair<int, int> >::iterator pos;

  int max_d = -1;
  /* search d - c */
  for ( int i = 0; i < n - 1; i++ ){
    for ( int j = i + 1; j < n; j++ ){
      int d = S[j];
      int c = S[i];
      
      int key = d - c;
      for ( pos = M.lower_bound(key); pos != M.upper_bound(key); pos++ ){
	pair<int, int> p = (*pos).second;
	if ( d != p.second && c != p.first ) max_d = max( max_d, d );
      }
    }
  }

  if ( max_d == -1 ) cout << "no solution" << endl;
  else cout << max_d << endl;
}


main(){
  while ( read() ){
    work();
  }
}
// @end_of_source_code
