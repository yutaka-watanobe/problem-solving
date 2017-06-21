// @JUDGE_ID:  17051CA  2698  C++
// @begin_of_source_code
/* Simulation - String */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#define NOTHING 0
#define TYPE2 2

void split ( vector<string> &d, const string &s, char c=' ' ) {
  string t = "";
  d.clear();

  for ( int i = 0; i < s.size(); i++ ){    
    if ( s[i] == c ){
      if ( t != "" ){ d.push_back(t); t = ""; }
    }
    else t += s[i];
  }
  if ( t.size() ) d.push_back(t);
}

vector<string> messages;
vector<int> stateTable;

bool isConsonant( char ch ){
  if ( ch == 'a' || ch == 'i' || ch == 'u' || ch == 'e' || ch == 'o' || ch == 'y' ||
       ch == 'A' || ch == 'I' || ch == 'U' || ch == 'E' || ch == 'O' || ch == 'Y' ) return false;
  return isalpha( ch );
}

bool is5consonants( string &str ){
  int sum = 0;
  for ( int i = 0; i < str.size(); i++ ){
    if ( isConsonant( str[i] ) ) sum++;
    else sum = 0;
    if ( sum > 5 ) return true;
  }
  return false;
}

bool is4consonants( string str ){
  vector<string> words;
  split( words, str );

  for ( int i = 0; i < words.size(); i++ ){
    string word = words[i];
    int sum = 0;
    for ( int j = 0; j < word.size(); j++ ){
      if ( isConsonant( word[j] ) ) sum++;
      else sum = 0;
      if ( sum > 4 ) return true;
    }
  }
  return false;
}

bool validate( string message, int pos ){
  int counter, sum;

  if ( is4consonants( message ) ){
    stateTable[ pos ] = TYPE2;

    counter = 0;
    sum = 0;
    for ( int i = pos - 1; i >= 0; i-- ){
      if ( counter >= 10 ) break;
      if ( stateTable[ i ] == TYPE2 ) sum++;
      counter++;
    }
    if ( sum > 2 ) return false ;
  }

  if ( is5consonants( message ) ) return false;

  counter = 0;
  sum = 0;
  for ( int i = pos - 1; i >= 0; i-- ){
    if ( counter >= 10 ) break;
    if ( messages[i] == message ) sum++;
    counter++;
  }
  if ( sum > 1 ) return false;

  return true;
}

void work(){
  for ( int i = 0; i < messages.size(); i++ ){
    if ( validate( messages[i], i ) ){
      cout << "y" << endl;
    } else {
      cout << "n" << endl;
    }
  }
}

void read(){
  string line;
  int n;
  getline( cin, line );
  n = atoi( line.c_str() );

  for ( int i = 0; i < n; i++ ){
    getline ( cin, line );
    messages.push_back( line );
  }
  stateTable.resize( n, NOTHING );
}

main(){
  read();
  work();
}
// @end_of_source_code


