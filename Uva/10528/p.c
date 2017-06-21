// @JUDGE_ID:  17051CA  10528  C++
// @begin_of_source_code
/* Simulation */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>

#define NOTES 12

void split( vector<string> &d, string s, char c=' '){
  string t = "";

  for ( int i = 0; i < s.size(); i++ ){
    if ( s[i] == c ){
      if ( t != "" ){ d.push_back( t ); t = "" ;}
    }
    else t += s[i];
  }
  if ( t.size() ) d.push_back( t);
}

string octave[NOTES];
bool Used[NOTES];
bool UsedIn[NOTES];

int major[7] = {2, 2, 1, 2, 2, 2, 1};

map<string, int> ID;

void init(){
  octave[0] = "C";
  octave[1] = "C#";
  octave[2] = "D";
  octave[3] = "D#";
  octave[4] = "E";
  octave[5] = "F";
  octave[6] = "F#";
  octave[7] = "G";
  octave[8] = "G#";
  octave[9] = "A";
  octave[10] = "A#";
  octave[11] = "B";
  for ( int i = 0; i < 12; i++ ) ID[octave[i]] = i;
}

int read(){
  string line;
  getline( cin, line );
  if ( line == "END" ) return 0;
  vector<string> com;
  split( com, line );
  
  fill ( UsedIn, UsedIn + NOTES, false );
  for ( int i = 0; i < com.size(); i++ ){
    UsedIn[ ID[com[i]] ] = true;
  }

  return 1;
}

bool parse( int start ){
  Used = UsedIn;

  int index = start;
  Used[ index ] = false;

  for ( int i = 0; i < 7; i++ ){
    index += major[i];
    Used[ index%NOTES ] = false;
  }
  
  for ( int i = 0; i < NOTES; i++ ){
    if ( Used[i] ) return false;
  }

  return true;
}

void work(){
  bool first = true;
  for ( int i = 0; i < NOTES; i++ ){
    if ( parse( i ) ){
      if ( !first ) cout << " ";
      else first = false;
      cout << octave[i];
    }
  }
  cout << endl;
}

main(){
  init();
  while ( read() ) work();
}
// @end_of_source_code
