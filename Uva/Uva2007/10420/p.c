// @JUDGE_ID:  17051CA  10420  C++
// @begin_of_source_code
/* Map */
#include<stdio.h>
#include<iostream>
#include<map>
#include<string>

map<string, int> M;

void read(){
  string country, name, line;
  int t;
  getline( cin, line );
  t = atoi( line.c_str() );
  for ( int i = 0; i < t; i++ ){
    cin >> country;
    getline( cin, name );
    M[ country ]++;
  }
}

void work(){
  map<string, int>::iterator pos;

  for ( pos = M.begin(); pos != M.end(); pos++ ){
    cout << (*pos).first << " " << (*pos).second << endl;
  }

}

void main(){
  read();
  work();
}

// @end_of_source_code
