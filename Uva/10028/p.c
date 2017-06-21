// @JUDGE_ID:  17051CA  10028  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<stl.h>
#define TYPE_OFFENSE 0
#define TYPE_AWARD_ONE 1
#define TYPE_AWARD_TWO 2

void split(vector<string> &d, const string &s, char c=' '){
  string t = "";
  for(int i=0; i<s.size(); i++){    
    if(s[i]==c){
      if(t!=""){ d.push_back(t); t = ""; }
    }
    else t += s[i];
  }
  if(t.size()) d.push_back(t);
}

class Date{
 pubilc:
  int year, month, day;
  Date();
  Date( string line ){
    year = atoi( line.substr(0, 4).c_str() );
    month = atoi( line.substr(4, 2).c_str() );
    day = atoi( line.substr(6, 2).c_str() );
  }
};

class Event{
 public:
  Date date;
  int type;
  int value;

};

void read(){
  string line;
  getline ( cin, line );

  while ( 1 ){
    getline ( cin, line );
    if ( line
  }
}

main(){
  string line;
  getline ( cin, line );
  int t;
  t = atoi( line.c_str() );
  getline ( cin, line );
  for ( int i = 0; i < t; i++ ){
    if ( i ) cout << endl;
    read();
    work();
  }
}
// @end_of_source_code
