// @JUDGE_ID:  17051CA  10188  C++
// @begin_of_source_code
/* Judge */
#include<stdio.h>
#include<iostream>
#include<string>

int n;
string line;

int read(){
  getline( cin, line );
  n = atoi( line.c_str() );
  if ( n == 0 ) return 0;
  return 1;
}

void work(){
  string standard, team;
  string standard_number, team_number;
  standard = team = standard_number = team_number = "";
  int m;
  int cnt = 0;
  char ch;

  while ( 1 ){
    cin.get( ch );
    if ( ch == '\n' ) cnt++;
    standard += ch;
    if ( isdigit( ch ) ) standard_number += ch;
    if ( cnt == n ) break;
  }

  getline( cin, line );
  m = atoi ( line.c_str() );
  
  cnt = 0;
  while ( 1 ){
    cin.get( ch );
    if ( ch == '\n' ) cnt++;
    team += ch;
    if ( isdigit( ch ) ) team_number += ch;
    if ( cnt == m ) break;
  }
  
  if ( team == standard ) cout << "Accepted" << endl;
  else {
    if ( team_number == standard_number ){
      cout << "Presentation Error" << endl;
    }else{
      cout << "Wrong Answer" << endl;
    }
  }
  
}

main(){
  for ( int i = 1; read(); i++ ){
    cout << "Run #" << i << ": " ;
    work();
  }
}
// @end_of_source_code
