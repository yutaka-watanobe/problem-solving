// @JUDGE_ID:  17051CA  2558  C++
// @begin_of_source_code
/* Simulation */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>

void tolower(string &s){
  for(int i=0; i<s.size(); i++) 
    s[i] = tolower(s[i]);
}

string secret_code;
string previous;
vector<string> G; /* guessed list */
bool accepted;
int current;

bool valid( string &str ){
  if ( str.size() != 5 ) return false;
  for ( int i = 0; i < 5; i++ ){
    char ch = str[i];
    if ( !( 'A' <= ch && ch <= 'Z' ) ) return false;
  }
  return true;
}

void giveUp(){
  tolower( secret_code );
  cout << secret_code << endl;
}

void guess( string str ){
  if ( !valid( str ) ){
    cout << previous << endl;
    return;
  }

  bool used[5];
  string answer = ".....";
  fill ( used, used + 5, false );

  for ( int i = 0; i < 5; i++ ){
    if ( secret_code[i] == str[i] ){
      answer[i] = str[i];
      used[i] = true;
    }
  }
  
  for ( int i = 0; i < 5; i++ ){
    if ( answer[i] != '.' ) continue;
    for ( int j = 0; j < 5; j++ ){
      if ( used[j] ) continue;
      if ( str[i] == secret_code[j] ){
	used[j] = true;
	answer[i] = tolower( secret_code[j] );
      }
    }
  }

  if ( current == 6 && answer != secret_code ){
    giveUp();
    accepted = true;
    return;
  }

  if ( answer == secret_code ) {
    cout << answer << endl;
    accepted = true;
    return ;
  }
  cout << answer << endl;  
  previous = answer;
}

void work(){
  previous = "";
  previous += secret_code[0];
  previous +=  "....";
  cout << previous << endl;
  
  accepted = false;

  for ( int i = 0; i < G.size(); i++ ){
    current = i + 1;
    guess( G[i] );
    if ( accepted ) break;
  }

  if ( !accepted ){
    giveUp();
  }
}

bool read(){
  string line;
  G.clear();

  getline( cin, secret_code );

  if ( secret_code == "LINGO" ) return false;

  while ( 1 ){
    getline( cin, line );
    if ( line.size() == 0 || cin.eof() ) return true;
    G.push_back( line );
  }
}
 
main(){
  string line;
  getline( cin, line ); /* fist brank line */
  while ( read() ){
    cout << endl;
    work();
  }
}

// @end_of_source_code


