// @JUDGE_ID:  17051CA  230  C++
// @begin_of_source_code
/* Simulation */
#include<stdio.h>
#include<iostream>
#include<stl.h>
#include<string>
#include<map>

/*
 * stringオブジェクトの前後の空白、改行の削除
 * 要件: #include <string>
 */
void trim(string &s){
  int l, r;

  l = s.find_first_not_of(" \n\r");
  r = s.find_last_not_of(" \n\r");

  if(l==string::npos) s = "";
  else  s = s.substr(l, r-l+1);
}

string getTitle(string s ){
  int t_start, t_end;
  t_start = s.find( '"' );
  t_end = s.rfind( '"' );
  string title = s.substr( t_start+1, t_end - t_start - 1 );
  trim( title );
  return title;
}

void split(string s, string &author, string &title ){

  title = getTitle( s );

  int a_start = s.find( "by" );
  a_start += 2;
  
  author = s.substr( a_start, s.size() - a_start );

  trim( author );
}

map<string, string> M; /* tilte - > author */

class BookSortCriterion{
 public:
  bool operator() ( const string &b1, const string &b2 ) const {
    if ( M[ b1 ] != M[ b2 ] )  return M[b1] < M[b2] ;
    else return b1 < b2;
  }
};

vector<string> S; /* Shelve */
vector<string> D; /* Desk */

void read(){
  string line, author, title;
  while ( 1 ){
    getline ( cin, line );
    if ( line == "END" ) break;
    split( line, author, title );
    S.push_back( title );
    M[ title ] = author;
  }

  sort ( S.begin(), S.end(), BookSortCriterion() );

}

void borrowBook( string title ){
  vector<string>::iterator pos;
  pos = lower_bound( S.begin(), S.end(), title, BookSortCriterion() );
  S.erase( pos );
}

void returnBook( string title ){
  D.push_back( title );
}

void shelve(){
  sort( D.begin(), D.end(), BookSortCriterion() );
  
  vector<string>::iterator pos;
  for ( int i = 0; i < D.size(); i++ ){
    pos = lower_bound( S.begin(), S.end(), D[i], BookSortCriterion() );
    if ( pos == S.begin() ){
      cout << "Put \"" << D[i] << "\" first" << endl;
    }else{
      cout << "Put \"" << D[i] << "\" after \"" << *(pos-1) << "\""  << endl;
    }
    S.insert(pos, D[i]);
  }
  cout << "END" << endl;
  D.clear();
}

void work(){
  string com, title, line;
  while ( 1 ){
    cin >> com;
    if ( com == "BORROW" ){
      getline ( cin, line );
      title = getTitle ( line );
      borrowBook( title );
    }else if ( com == "RETURN" ){
      getline ( cin, line );
      title = getTitle ( line );
      returnBook( title );
    }else if ( com == "SHELVE" ){
      getline( cin, line );
      shelve();
    }else if ( com == "END" ){
      return;
    }
  }
}

main(){
  read();
  work();
}
// @end_of_source_code
