// @JUDGE_ID:  17051CA  449  C++
// @begin_of_source_code
/* Simulation */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>

void split ( vector<string> &d, const string &s, char c ) {
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

string major[12][7] = { {"C", "D", "E", "F", "G", "A", "B"},
		       {"Db", "Eb", "F", "Gb", "Ab", "Bb", "C"},
		       {"D", "E", "F#", "G", "A", "B", "C#"},
		       {"Eb", "F", "G", "Ab", "Bb", "C", "D"},
		       {"E", "F#", "G#", "A", "B", "C#", "D#"},
		       {"F", "G", "A", "Bb", "C", "D", "E"},
		       {"Gb", "Ab", "Bb", "Cb", "Db", "Eb", "F"},
		       {"G", "A", "B", "C", "D", "E", "F#"},
		       {"Ab", "Bb", "C", "Db", "Eb", "F", "G"},
		       {"A", "B", "C#", "D", "E", "F#", "G#"},
		       {"Bb", "C", "D", "Eb", "F", "G", "A"},
		       {"B", "C#", "D#", "E", "F#", "G#", "A#"} };

map<string, int> StoI; /* scale to index */

class MajoringInScales{
 public:
  string scale;
  int scaleIndex;
  vector<string> query;

  int getLength( string str ){
    if ( str == "SECOND" ) return 1;
    else if ( str == "THIRD" ) return 2;
    else if ( str == "FOURTH" ) return 3;
    else if ( str == "FIFTH" ) return 4;
    else if ( str == "SIXTH" ) return 5;
    else if ( str == "SEVENTH" ) return 6;
    else if ( str == "OCTAVE" ) return 7;
    else assert( false );
  }

  void compute( string start, string direction, string len ){
    int source = -1;
    for ( int i = 0; i < 7; i++ ){
      if ( major[scaleIndex][i] == start ){
	source = i;
	break;
      }
    }

    if ( source == - 1 ){
      cout << start << ": invalid note for this key" << endl;
      return;
    }

    int length = getLength( len );
    int target;

    if ( direction == "UP" ) target = ( source + length ) % 7;
    else if ( direction == "DOWN" ){
      target = source - length;
      if ( target < 0 ) target = 7 + target;
    } else assert( false );
    
    cout << start << ": " << direction << " " << len << " > ";
    cout << (string)major[scaleIndex][target] << endl;
  }

  void work(){
    cout << "Key of " << scale << endl;

    for ( int i= 0; i < query.size(); i++ ){
      vector<string> command;
      split( command, query[i], ' ');
      assert( command.size() == 3 );
      compute( command[0], command[1], command[2] );
    }
  }

  bool read(){
    string line;
    getline( cin, line );
    if ( cin.eof() ) return false;

    scale = line;
    if ( StoI.find( scale ) == StoI.end() ) assert( false );
    scaleIndex = StoI[ scale ];
    
    getline( cin, line );
    query.clear();
    split( query, line, ';' );
    return true;
  }

};

main(){
  StoI["C"] = 0;
  StoI["Db"] = 1;
  StoI["D"] = 2;
  StoI["Eb"] = 3;
  StoI["E"] = 4;
  StoI["F"] = 5;
  StoI["Gb"] = 6;
  StoI["G"] = 7;
  StoI["Ab"] = 8;
  StoI["A"] = 9;
  StoI["Bb"] = 10;
  StoI["B"] = 11;

  MajoringInScales MIS;
  for ( int i = 0; MIS.read(); i++ ){
    MIS.work();
    cout << endl;
  }
}

// @end_of_source_code


