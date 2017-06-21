// @JUDGE_ID:  17051CA  10191  C++
// @begin_of_source_code
/* Calculation */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

int n;
string line;

int read(){
  getline( cin, line );
  if ( cin.eof() ) return 0;
  n = atoi( line.c_str() );
  return 1;
}

void work(){
  vector<pair<int, int> > S;
  char ch;
  int hour, minute, start, end;

  S.push_back( make_pair( 480, 600 ) );

  for ( int i = 0; i < n; i++ ){
    cin >> hour >> ch >> minute;
    start = hour * 60 + minute;
    cin >> hour >> ch >> minute;
    end = hour * 60 + minute;
    S.push_back( make_pair(start, end) );
    getline( cin, line );
  }

  S.push_back( make_pair( 1080, 1080 ) );

  sort( S.begin(), S.end() );

  int longest_nap = 0;
  int longest_start = 0;

  for ( int i = 1; i < S.size(); i++ ){
    if ( longest_nap < S[i].first - S[i-1].second ){
      longest_nap = S[i].first - S[i-1].second;
      longest_start = S[i-1].second;
    }
  }

  int start_hour, start_minute;
  start_hour = longest_start / 60;
  start_minute = longest_start % 60;

  hour = longest_nap / 60;
  minute = longest_nap % 60;

  cout << "the longest nap starts at " << start_hour << ":";
  if ( start_minute < 10 ) cout << "0" << start_minute;
  else cout << start_minute;
  cout << " and will last for ";

  if ( longest_nap < 60 ) cout << minute << " minutes." << endl;
  else{
    cout << hour << " hours and " << minute << " minutes." << endl;
  }

  

}

main(){
  for ( int i = 1; read(); i++ ){
    cout << "Day #" << i << ": ";
    work();
  }
}
// @end_of_source_code
