// @JUDGE_ID:  17051CA  10527  C++
// @begin_of_source_code
/* BigInteger Division */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>

string input;

void div( vector<int> v, vector<int> &ans, int p, bool &isone, bool &dividable){
  while ( 1 ){
    if (v[v.size()-1] == 0 ){
      v.pop_back();
    }else break;
  }

  if ( v.size() == 1 && v[0] == p ){
    isone = true;
    dividable = true;
    return;
  }

  v.push_back( 0 );
  ans.clear();

  for ( int i = v.size()-2; i >=0; i-- ){
    int x = 10 * v[i+1] + v[i];
    v[i] = x%p;
    v[i+1] = 0;
    ans.push_back( x/p );
  }

  reverse(ans.begin(), ans.end());
  isone = false;

  for ( int i = 0; i < v.size(); i++ ){
    if ( v[i] != 0 ) {
      dividable = false;
      return;
    }
  }
  dividable = true;

}

vector<int> v;
string line;

int read(){
  cin >> line;
  if ( line == "-1" ) return 0;
  v.clear();

  for ( int i = line.size() -1 ; i >=0; i-- ){
    v.push_back( line[i] -'0' );
  }
  
  return 1;
}

void work(){
  vector<int> P;
  vector<int> current, ans;

  current = v;
  if ( line == "0" ){
    cout << "10" << endl;
    return;
  }

  if ( line == "1" ){
    cout << "11" << endl;
    return ;
  }

  bool dividable, isone;

  while ( 1 ){
    for ( int i = 9; i >= 0; i-- ){
      if ( i == 1 ) goto end;
     
      div( current, ans, i, isone, dividable );

      if ( dividable ){
	current = ans;
	P.push_back( i );
	goto next;
      }
    }
    next:;

    if( isone ) break;
  }

  end:;

  if ( !isone ) {
    cout << "There is no such number." << endl;
    return;
  }

  if ( P.size() == 1 ) P.push_back( 1 );

  sort( P.begin(), P.end() );

  for ( int i = 0; i < P.size(); i++ ){
    cout << P[i];
  }
  cout << endl;

}

main(){
  while ( read() ) work();
}
// @end_of_source_code
