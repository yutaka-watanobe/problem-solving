// @JUDGE_ID:  17051CA  10203  C++
// @begin_of_source_code
/* Math - Geometory */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>

void split ( vector<int> &d, const string &s, char c=' ' ) {
  string t = "";
  d.clear();

  for ( int i = 0; i < s.size(); i++ ){    
    if ( s[i] == c ){
      if ( t != "" ){ d.push_back( atoi(t.c_str()) ); t = ""; }
    }
    else t += s[i];
  }
  if ( t.size() ) d.push_back( atoi(t.c_str()) );
}

class SnowClearing{
 public:
  double dist;

  double getDistance( int x1, int y1, int x2, int y2 ){
    return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
  }

  void work(){

    int t = (int)( (2 * dist / 20000) * 60 + 0.5 );

    int hour = t / 60;
    int minute = t % 60;

    cout << hour << ":";
    if ( minute < 10 ) cout << '0';
    cout << minute << endl;

  }

  void read(){
    string line;
    vector<int> coordinate;

    dist = 0;

    getline( cin, line );

    while ( 1 ){
      getline( cin, line );
      if ( line.size() == 0 || cin.eof() ) return; 
      
      split( coordinate, line );
      dist += getDistance( coordinate[0], coordinate[1], 
			   coordinate[2], coordinate[3] );
    }
  }

};

main(){
  SnowClearing SC;
  int tcase;
  string line;
  cin >> tcase;
  getline( cin, line );
  getline( cin, line );

  for ( int i = 0; i < tcase; i++ ){
    if ( i ) cout << endl;
    SC.read();
    SC.work();
  }
}

// @end_of_source_code


