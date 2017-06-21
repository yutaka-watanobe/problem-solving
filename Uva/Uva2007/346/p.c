// @JUDGE_ID:  17051CA  346  C++
// @begin_of_source_code
/* Mapping -- Musical Notes */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
#define MAJOR 1
#define MINOR 2

class GettingChorded{
 public:
  string notes[12][2];
  map<string, int> NtoI;
  string n1, n2, n3;

  void createTable(){
    notes[0][0] = "A";  notes[0][1] = "";
    notes[1][0] = "A#"; notes[1][1] = "Bb";
    notes[2][0] = "B"; notes[2][1] = "Cb";
    notes[3][0] = "C"; notes[3][1] = "B#";
    notes[4][0] = "C#"; notes[4][1] = "Db";
    notes[5][0] = "D"; notes[5][1] = "";
    notes[6][0] = "D#"; notes[6][1] = "Eb";
    notes[7][0] = "E"; notes[7][1] = "Fb";
    notes[8][0] = "F"; notes[8][1] = "E#";
    notes[9][0] = "F#"; notes[9][1] = "Gb";
    notes[10][0] = "G"; notes[10][1] = "";
    notes[11][0] = "G#"; notes[11][1] = "Ab";
    NtoI[ "A" ] = 0;
    NtoI[ "A#" ] = 1;
    NtoI[ "Bb" ] = 1;
    NtoI[ "B" ] = 2;
    NtoI[ "Cb" ] = 2;
    NtoI[ "C" ] = 3;
    NtoI[ "B#" ] = 3;
    NtoI[ "C#" ] = 4;
    NtoI[ "Db" ] = 4;
    NtoI[ "D" ] = 5;
    NtoI[ "D#" ] = 6;
    NtoI[ "Eb" ] = 6;
    NtoI[ "E" ] = 7;
    NtoI[ "Fb" ] = 7;
    NtoI[ "F" ] = 8;
    NtoI[ "E#" ] = 8;
    NtoI[ "F#" ] = 9;
    NtoI[ "Gb" ] = 9;
    NtoI[ "G" ] = 10;
    NtoI[ "G#" ] = 11;
    NtoI[ "Ab" ] = 11;
  }

  string getNote( string n1 ){
    string n = n1;
    n[0] = toupper( n[0] );
    return n;
  }

  int parse( string &code ){
    int v[3];
    v[0] = NtoI[ getNote( n1 ) ];
    v[1] = NtoI[ getNote( n2 ) ];
    v[2] = NtoI[ getNote( n3 ) ];
    sort ( v, v + 3 );

    int d1, d2;
    /* start from v0 */
    d1 = v[1] - v[0] - 1;
    d2 = v[2] - v[1] - 1;
    if ( d1 == 3 && d2 == 2 ){
      code = notes[ v[0] ][0];
      return MAJOR;
    } else if ( d1 == 2 && d2 == 3 ){
      code = notes[ v[0] ][0];
      return MINOR;
    }
    /* start from v1 */
    d1 = v[2] - v[1] - 1;
    d2 = 12 - v[2] - 1 + v[0];
    if ( d1 == 3 && d2 == 2 ){
      code = notes[ v[1] ][0];
      return MAJOR;
    } else if ( d1 == 2 && d2 == 3 ){
      code = notes[ v[1] ][0];
      return MINOR;
    }
    /* start from v2 */
    d1 = 12 - v[2] - 1 + v[0];
    d2 = v[1] - v[0] - 1;
    if ( d1 == 3 && d2 == 2 ){
      code = notes[ v[2] ][0];
      return MAJOR;
    } else if ( d1 == 2 && d2 == 3 ){
      code = notes[ v[2] ][0];
      return MINOR;
    }
    return -1;

  }

  bool read(){
    n1, n2,n3;
    if ( !( cin >> n1 >> n2 >> n3 ) ) return false;
    return true;
  }

  void work(){
    cout << n1 << " " << n2 << " " << n3 << " is ";
    string code;
    int result = parse( code );
    if ( result == MAJOR ) {
      cout << "a " << code << " Major chord." << endl;
    } else if ( result == MINOR ){
      cout << "a " << code << " Minor chord." << endl;
    } else {
      cout << "unrecognized." << endl;
    }
  }

  void start(){
    createTable();

    while ( read() ){
      work();
    }

  }

};

main(){
  GettingChorded GC;
  GC.start();
}


// @end_of_source_code


