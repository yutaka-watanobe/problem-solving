#include<iostream>
#include<stdio.h>
#include<string>
#define MAX 1000
#define EMPTY ' '
using namespace std;

string dictionaly[18][MAX];
int dsize[18];
string lines[80];
int lsize;

char M[27];

bool rec( int cursor ){
  if ( cursor == lsize ) return true;

  string str = lines[ cursor ];
  int strSize = str.size();
  if ( strSize > 16 ) return false;

  for ( int d = 0; d < dsize[ strSize ]; d++ ){
    string word = dictionaly[strSize][d];

    /*cout << ".";
    for ( int c = 0; c < word.size(); c++ ){
      int index = str[c] - 'a';
      cout << M[index];
    }
    cout << "." <<  endl;*/

    for ( int c = 0; c < word.size(); c++ ){
      int index = str[c] - 'a';
      
      if ( M[ index ] == EMPTY || M[ index ] == word[c] ){
      } else {
	goto next;
      }
    }

    //cout << word << endl;

    char tmp[ 26 ];
    for ( int c = 0; c < word.size(); c++ ){
      int index = str[c] - 'a';
      tmp[ index ] = M[ index ];
    }

    for ( int c = 0; c < word.size(); c++ ){
      int index = str[c] - 'a';
      M[ index ] = word[c];
    }

    if ( rec( cursor + 1 ) ) return true;

    for ( int c = 0; c < word.size(); c++ ){
      int index = str[c] - 'a';
      M[ index ] = tmp[ index ];
    }


  next:;
  }



  return false;
}

void compute(){
  
  for ( int i = 0; i < 26; i++ ) M[i] = EMPTY;

  if ( rec( 0 ) ){
    for ( int i = 0; i < lsize; i++ ){
      if ( i ) printf(" ");
      string str = lines[i];
      for (int j = 0;  j < str.size(); j++ ){
	printf("%c", M[ str[j] - 'a'] );
      }
    }
  } else {
    for ( int i = 0; i < lsize; i++ ){
      if ( i ) printf(" ");
      string str = lines[i];
      for (int j = 0;  j < str.size(); j++ ){
	printf("*");
      }
    }
  }
  printf("\n");
}

void work(){
  string line; 
  while ( 1 ){
    getline( cin, line );
    if ( cin.eof() ) return;
    
    string str = "";
    char ch;
    lsize = 0;
    for ( int i = 0; i < line.size(); i++ ){
      ch = line[i];
      if ( ch == ' ' ){
	if ( str.size() ){
	  lines[ lsize++ ] = str;
	  str = "";
	} 
      } else {
	str += ch;
      }
    }
    if ( str.size() ) lines[ lsize++ ] = str;

    compute();
  }
}

void read(){
  int size;
  cin >> size;
  string word;
  for ( int i = 0; i < 18; i++ ) dsize[i] = 0;

  for ( int i = 0; i < size; i++ ){
    cin >> word;
    dictionaly[ word.size() ][ dsize[word.size()]++ ] = word;
  }
  getline( cin, word );
}

main(){
  read();
  work();
}
