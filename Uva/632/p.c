// @JUDGE_ID:  17051CA  632  C++
// @begin_of_source_code
/* Simulation ( Compression method ) */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
#define NCHARACTER 50

int N;

void work(){
  
  string S0, S1;
  cin >> N;

  S0 = "";

  char ch;
  for ( int i = 0; i < N; i++ ){
    scanf( "%c", &ch );
    if ( ch == '\n' ){
      i--;
      continue;
    }
    S0 += ch;
  }

  vector<string> S;

  string inputText = S0;
  S.push_back( S0 );
  for ( int i = 0; i < N - 1; i++ ){
    char pre = inputText[0];
    inputText.erase( inputText.begin() + 0 );
    inputText += pre;
    S.push_back( inputText );
  }
  
  S1 = S[ 1 ];

  sort( S.begin(), S.end() );
  int pos = distance( S.begin(), lower_bound( S.begin(), S.end(), S1 ) );

  cout << pos << endl;
  for ( int i = 0; i < N; i++ ){
    if ( i % NCHARACTER == 0 && i != 0 ) cout << endl;
    cout << S[ i ][ N - 1 ];
  }
  cout << endl;

}

main(){
  int tcase;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    if ( i ) cout << endl;
    work();
  }
}

// @end_of_source_code


