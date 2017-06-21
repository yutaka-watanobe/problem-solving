// @JUDGE_ID:  17051CA  2364  C++
// @begin_of_source_code
/* Simple Calculation */
#include<stdio.h>
#include<string>
#include<iostream>
#include<stl.h>
#include<set>
#include<map>
#include<vector>
#include<cmath>
#define SEPARATER "----------"

void split(vector<string> &d, const string &s, char c=' '){
  string t = "";
  d.clear();
  for(int i=0; i<s.size(); i++){    
    if(s[i]==c){
      if(t!=""){ d.push_back(t); t = ""; }
    }
    else t += s[i];
  }
  if(t.size()) d.push_back(t);
}

void valid( string &str ){
  string tmp = "";

  for ( int i = 0; i < str.size(); i++ ){
    if ( isalpha( str[i] ) || isdigit( str[i] ) ){
      tmp += tolower( str[i] );
    }
  }

  str = tmp;
}

map<string, int> S; /* search string */
map<string, int> D; /* document */

void read(){
  string search_string = "";

  string line;
  getline( cin, line );

  assert( line.size() == 0 );

  S.clear();

  while ( 1 ){
    getline( cin, line );
    if ( line == SEPARATER ) break;
    search_string += ' ';
    search_string.append( line );
  }

  vector<string> sp;

  split( sp, search_string );

  for ( int i = 0; i < sp.size(); i++ ){
    valid( sp[i] );
    if ( sp[i].size() )  S[ sp[i] ]++;
  }
}


void work(){

  string document = "";
  string line;

  vector<string> sp;

  while ( 1 ){
    getline( cin, document );
    if ( document == SEPARATER ) break;

    while ( 1 ){
      getline( cin, line );
      if ( line == SEPARATER ) goto next;
      document += ' ';
      document.append( line );
    }

  next:;

    D.clear();

    split ( sp, document );
    
    for ( int i = 0; i < sp.size(); i++ ){
      valid( sp[i] );
      if ( sp[i].size() )  D[ sp[i] ]++;
    }
    
    double sum = 0.0;
    map<string, int>::iterator s_pos, d_pos;
    for ( s_pos = S.begin(); s_pos != S.end(); s_pos++ ){
      if ( D.find( (*s_pos).first ) != D.end() ){
	sum += sqrt( 1.0 * (*s_pos).second * D[(*s_pos).first] );
      }
    }

    printf("%.2lf\n", sum );
  }
}

main(){
  string line;
  getline( cin, line );
  int t = atoi( line.c_str() );
  for ( int i = 0; i < t; i++ ){
    if ( i ) cout << endl;
    read();
    work();
  }
}
// @end_of_source_code
