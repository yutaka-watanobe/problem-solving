// @JUDGE_ID:  17051CA  10659  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

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

class Slide{
 public:
  vector<vector<string> > P;
  int X, Y;

  bool tryFont( int font ){
    int column = 1;
    int x;
    for ( int p = 0; p < P.size(); p++ ){
      x = 0;
      if (  column * font > Y ) return false;
      vector<string> paragraph = P[p];
      for ( int i = 0; i < paragraph.size(); i++ ){
	string str = paragraph[i];
	int space = (x==0) ? 0 : 1;
	if ( x == 0 && str.size() > X ) return false;
	if ( x + font * ( str.size() + space ) > X ){
	  x = 0; column++; i--;
	  if ( column * font > Y ) return false;
	} else {
	  x += font * (str.size() + space );
	}
      }
      column++;
    }
    return true;

  }

  void work(){
    for ( int font = 28; font >= 8; font-- ){
      if ( tryFont ( font ) ){
	cout << font << endl;
	return;
      }
    }
    cout << "No solution" << endl;
  }
  
  void read(){
    string line;
    int m;
    getline( cin, line );
    m = atoi( line.c_str() );
    vector<string> com;
    P.clear();

    for ( int i = 0; i < m; i++ ){
      getline ( cin, line );
      split( com, line );
      P.push_back( com );
    }

    getline( cin, line );
    split( com, line );
    X = atoi(com[0].c_str() );
    Y = atoi(com[1].c_str() );
  }
};

main(){
  int tcase;
  string line;
  getline( cin, line );
  tcase = atoi( line.c_str() );

  for ( int i = 0; i < tcase; i++ ){
    Slide S;
    S.read();
    S.work();
  }
}

// @end_of_source_code


