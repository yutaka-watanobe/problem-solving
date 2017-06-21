// @JUDGE_ID:  17051CA  2286  C++
// @begin_of_source_code
/* Simulation */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

string line;

class Microprocessor{
 public:
  string S;
  vector<int> M;
  int A, B;
  int pos;

  Microprocessor( string S ): S(S){
    M.clear();
    M.resize( S.size() );
    for ( int i = 0; i < S.size(); i++ ){
      M[i] = hexCdec( S[i] );
    }
    A = B = 0;
    Simulate();
    print();
  }
  
  void Simulate(){
    int code;
    pos = 0;
    while ( 1 ){
      code = M[pos];
      switch( code ){
      case 0:
	LD ( M[pos+1], M[pos+2] );
	pos += 2; break;
      case 1:
	ST ( M[pos+1], M[pos+2] );
	pos += 2; break;
      case 2:
	SWP(); break;
      case 3:
	ADD(); break;
      case 4:
	INC(); break;
      case 5:
	DEC(); break;
      case 6:
	BZ( M[pos+1], M[pos+2] );
	break;
      case 7:
	BR( M[pos+1], M[pos+2] );
	break;
      case 8:
	return;
      }
      pos++;
    }
  }
  
  void LD( int a1, int a2 ){
    int addr = a1 * 16 + a2;
    A = M[ addr ];
  }

  void ST( int a1, int a2 ){
    int addr = a1 * 16 + a2;
    M[ addr ] = A;
  }

  void SWP(){
    int tmp = A;
    A = B;
    B = tmp;
  }

  void ADD(){
    int sum = A + B;
    A = sum % 16;
    B = sum / 16;
  }

  void INC(){
    A = ( A + 1 ) % 16;
  }

  void DEC(){
    A--;
    if ( A < 0 ) A = 15;
  }

  void BZ( int a1, int a2 ){
    if ( A == 0 ){
      int addr = a1 * 16 + a2;
      pos = addr;
      pos--; /* for main increment */
    } else {
      pos += 2;
    }
  }

  void BR( int a1, int a2 ){
    int addr = a1 * 16 + a2;
    pos = addr;
    pos--; /* for main increment */
  }

  /* 16 char --> int */
  int hexCdec( char ch ) {
    if ( isdigit(ch) ) return ch-'0';
  else return (ch - 'A') + 10;
  }

  void print(){
    for ( int i = 0; i < M.size(); i++ ){
      if ( M[i] >= 10 ){
	char ch = 'A' + (M[i] - 10);
	cout << ch;
      } else {
	cout << M[i];
      }
    }
    cout << endl;
  }
};


void work(){
  Microprocessor m = Microprocessor( line );
}

int read(){
  cin >> line;
  if ( line[0] == '8' ) return 0;
  return 1;
}

main(){
  while ( read() ) work();
}

// @end_of_source_code
