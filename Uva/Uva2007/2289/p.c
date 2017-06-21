// @JUDGE_ID:  17051CA  2289  C++
// @begin_of_source_code
/* Simple Judgement */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

vector<string> T; /* tableau */

int read(){
  string line;
  T.clear();
  T.resize( 12 );
  for ( int i = 0; i < 12; i++ ){
    cin >> line;
    if ( cin.eof() ) return 0;
    T[i] = line;
  }

  return 1;
}

bool check( string c1, string c2, string c3 ){
  for ( int i = 0; i < 4; i++ ){
    if ( !(
	   ( c1[i] == c2[i] && c2[i] == c3[i] ) ||
	   ( c1[i] != c2[i] && c1[i] != c3[i] && c2[i] != c3[i] )
	   )){
      return false;
    }
  }
  return true;
}

void print(){
  cout << "CARDS: ";
  for ( int i = 0; i < 12; i++ ){
    cout << " " << T[i];
  }
  cout << endl;
}

void work(){
  vector<string> G;

  for ( int i = 0; i <= 9; i++ ){
    for ( int j = i + 1; j <= 10; j++ ){
      for ( int k = j + 1; k <= 11; k++ ){
	if ( check ( T[i], T[j], T[k] ) ){
	  G.push_back( T[i] + " " + T[j] + " " + T[k] );
	}
      }
    }
  }

  print();
  
  cout << "SETS:";

  if ( G.size() == 0 ){
    cout << "   *** None Found ***" << endl;
  }else{
    for ( int i = 0; i < G.size(); i++ ){
      if ( i ) cout << "     ";
      printf("%4d", i+1);
      cout << ".  " << G[i] << endl;
    }
  }
}


main(){
  for ( int i = 0; read(); i++ ){
    work();
    cout << endl;
  }
}
// @end_of_source_code
