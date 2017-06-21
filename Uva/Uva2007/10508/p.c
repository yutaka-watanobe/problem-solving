// @JUDGE_ID:  17051CA  10508  C++
// @begin_of_source_code
/* Calculation - ordering */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>

int N, M;
vector<pair<int, string> > W;
string first, last;

int read(){
  cin >> N >> M;
  if ( cin.eof() ) return 0;

  cin >> first >> last;
  W.clear();
  W.resize( N-2 );

  string word;
  for ( int i = 0; i < N - 2; i++ ) {
    cin >> word;
    W[i] = pair<int, string>(0, word);
  }

  return 1;
}

void work(){
  for ( int i = 0; i < W.size(); i++ ){
    int sum = 0;
    for ( int j = 0; j < M; j++ ){
      if( W[i].second[j] != first[j] ) sum++;
    }
    W[i].first = sum;
  }

  sort( W.begin(), W.end() );
  
  cout << first << endl;
  for ( int i = 0; i < W.size(); i++ ){
    cout << W[i].second << endl;
  }
  cout << last << endl;
}

main(){
  while ( read() ){
    work();
  }
}
// @end_of_source_code
