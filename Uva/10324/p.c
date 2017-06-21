// @JUDGE_ID:  17051CA  10324  C++
// @begin_of_source_code
/* Upper Bound */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>

string line;
int n;

int read(){
  cin >> line;
  if ( cin.eof() ) return 0;
  cin >> n;
  return 1;
}

void work(){
  vector<int> T;
  
  char pre = line[0];
  for ( int i = 0; i < line.size(); i++ ){
    if ( pre != line[i] ) T.push_back( i );
    pre = line[i];
  }

  int a, b, L, U;
  for ( int i = 0; i < n; i++ ){
    cin >> a >> b;
    L = min( a, b ); U = max( a, b );
    if ( upper_bound( T.begin(), T.end(), L ) == upper_bound( T.begin(), T.end(), U ) ){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }

}

main(){
  for ( int i = 1;  read(); i++ ){
    cout << "Case " << i << ":" << endl;
    work();
  }
}
// @end_of_source_code
