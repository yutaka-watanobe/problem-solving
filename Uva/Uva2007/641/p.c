// @JUDGE_ID:  17051CA  641  C++
// @begin_of_source_code
/* Encryption & Decryption */
/* Ciphercode --> Plaincode */
/* PE ?? */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
int k, n;

vector<int> ciphercode;
vector<int> plaincode;

int getCode( char ch ){
  if ( ch == '_' ) return 0;
  if ( ch == '.' ) return 27;
  return ch - 'a' + 1;
}

char getText( int i ){
  if ( i == 0 ) return '_';
  if ( i == 27 ) return '.';
  return (char)( i - 1 + 'a' );
}

void decrypt(){
  for ( int i = 0; i < n; i++ ){
    int code = ciphercode[i];
    int index = ( k * i ) % n;
    plaincode[ index ] = ( code + i ) % 28;
  }
}

void work(){
  decrypt();

  for ( int i = 0; i < n; i++ ){
    cout << getText( plaincode[i] );
  }
  cout << endl;
}

bool read(){
  cin >> k;
  if ( k == 0 ) return false;
  
  ciphercode.clear();
  plaincode.clear();

  string str;
  cin >> str;
  n = str.size();

  ciphercode.resize( n );
  plaincode.resize( n );
  
  for ( int i = 0; i < str.size(); i++ ){
    ciphercode[ i ] = getCode( str[i] );
  }

  return true;
}

main(){
  while ( read() ){
    work();
  }
}
// @end_of_source_code
