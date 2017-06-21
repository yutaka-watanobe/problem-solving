// @JUDGE_ID:  17051CA  699  C++
// @begin_of_source_code
/* Tree parsing */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>

int k;
map<int, int> M;
vector<int> V;

void rec ( int cursor ){
  cin >> k;

  if ( k == -1 ) return;

  M[cursor] += k;

  rec( cursor - 1 );
  rec( cursor + 1 );
}

int read(){
  map<int, int>::iterator pos;
  M = map<int, int>();
  V.clear();

  rec ( 0 );

  /* map key --> M.first;  map value --> M.second */
  for ( pos = M.begin(); pos != M.end(); pos++ ){
    V.push_back( (*pos).second );
  }

  if( V.size() == 0 ) return 0;
  else return 1;
}

void work(){
  for ( int i = 0; i < V.size(); i++ ){
    if ( i ) cout << " ";
    cout << V[i];
  }
  cout << endl;
}

main(){
  for ( int i = 1;  read(); i++ ){
    cout << "Case " << i << ":" << endl;
    work();
    cout << endl;
  }
}
// @end_of_source_code

