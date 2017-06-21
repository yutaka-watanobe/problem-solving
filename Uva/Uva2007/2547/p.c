// @JUDGE_ID:  17051CA  2547  C++
// @begin_of_source_code
/* Simple Calculation */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<stl.h>

void split( vector<int> &d, const string &s, char c=' ' ){
  d.clear();
  string t = "";

  for ( int i = 0; i < s.size(); i++ ){
    if ( s[i] == c ){
      if ( t != "" ) { d.push_back( atoi( t.c_str() ) ); t = ""; }
    }
    else t += s[i];
  }
  if ( t.size() ) d.push_back ( atoi( t.c_str() ) );
}

class BusSchedule{
 public:
  int N;
  vector<string> bussList;
  int arrivalTime;
  int minimum_cost;
  
  void compute( string buss ){
    vector<int> route;
    split( route, buss );
    
    int M = route.size();
    
    int current = 0;
    int pos = 0;
    while ( 1 ) {
      if ( current >= arrivalTime ) break;
      current += route[ pos % M ];
      pos++;
    }
    
    if ( minimum_cost > current - arrivalTime ){
      minimum_cost = current - arrivalTime;
    }
  }
  
  void work(){
    minimum_cost = INT_MAX;
    
    for ( int i = 0; i < bussList.size(); i++ ){
      compute( bussList[i] );
    }
    
    cout << minimum_cost << endl;
  }
  
  bool read(){
    string line;
    cin >> line;
    if ( line == "ENDOFINPUT" ) return false;
    bussList.clear();
    cin >> N;
    getline( cin, line );
    for ( int i = 0; i < N; i++ ){
      getline( cin, line );
      bussList.push_back( line );
    }
    
    cin >> arrivalTime;
    
    cin >> line; /* END */
    return true;
  }
};

main(){
  BusSchedule bus;

  while ( bus.read() ){
    bus.work();
  }
}


// @end_of_source_code


