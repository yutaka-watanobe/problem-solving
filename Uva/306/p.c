// @JUDGE_ID:  17051CA  306  C++
// @begin_of_source_code
/* Encrypt */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#define MAX 250

class Cipher{
 public:
  int N, K;
  int key[ MAX ];
  vector<vector<int> > T;
  char text[ MAX ];

  void encode(){
    string buffer;

    cin.get();
    getline( cin, buffer );

    buffer.resize( N, ' ' );

    for ( int i = 0; i < buffer.size(); i++ ){
      int p = K % T[i].size();
      text[ T[i][p] ] = buffer[i];
    }
    
    for ( int i = 0; i < N; i++ ){
      printf("%c", text[i] );
    }
    cout << endl;
  }

  void work(){
    
    while ( 1 ){
      cin >> K;
      if ( K == 0 ) break;
      encode();
    }

  }

  bool read(){
    cin >> N;
    if ( N == 0 ) return false;
    int k;

    for ( int i = 0; i < N; i++ ){
      cin >> k;
      key[i] = k - 1;
    }

    /* create Table */
    T.assign( N, vector<int>() );

    for ( int i = 0; i < N; i++ ){
      T[i].push_back( i );
      for ( int current = key[i]; current != i; current = key[current] ){
	T[i].push_back( current );
      }
    }

    return true;
  }

};


main(){
  Cipher C;
  while ( C.read() ){
    C.work();
    cout << endl;
  }
}



// @end_of_source_code


