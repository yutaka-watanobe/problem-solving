// @JUDGE_ID:  17051CA  632  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

string str;
vector<string> S;
int N;
int size;

int read(){
  S.clear();
  cin >> N >> str;
  size = str.size();
  S.resize( N );
}

void work(){
  char first;
  S[0] = str;
  for ( int i = 0; i < N; i++ ) S[i].resize( size );
  string S1;

  for ( int i = 1; i < N; i++ ){
    if ( i >= size ){
      S[i] = S[i%size];
    }else{
      first = S[i-1][0];
      for ( int j = 0; j < size-1; j++ ){
	S[i][j] = S[i-1][j+1];
      }
      S[i][size-1] = first;
    }
  }

  S1 = S[1];

  sort ( S.begin(), S.end() );

  int index;
  index = distance( S.begin(), lower_bound(S.begin(), S.end(), S1) );
  
  cout << index << endl;
  for ( int i = 0; i < N; i++ ) cout << S[i][size-1];
  cout << endl;

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
