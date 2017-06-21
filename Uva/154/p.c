// @JUDGE_ID:  17051CA  154  C++
// @begin_of_source_code
/* Simulation */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>

void split( vector<string> &d, string s ){
  char c = ',';
  string t = "";
  
  for ( int i = 0; i < s.size(); i++ ){
    if ( s[i] == c ){
      if ( t != "" ) { d.push_back(t); t = "";}
    }
    else t += s[i];
  }
  if( t.size() ) d.push_back( t );
}

int N;

map<char, char> C[100];

string line;

int read(){
  int cnt = 0;
  while ( 1 ){
    vector<string> v;
    getline( cin, line );
    if ( line == "#" ) return 0;
    if ( line[0] == 'e' ) return 1;
    
    split( v, line);
    map<char, char> m;
    
    for ( int i = 0; i < v.size(); i++ ){
      m[ v[i][0] ] = v[i][2];
    }

    C[cnt] = m;
    cnt++;
    N = cnt;
  }
}

void work(){

  int T[100];
  fill ( T, T + 100, 0 );

  for ( int i = 0; i < N; i++ ){
    for ( int k = 0; k < N; k++ ){
      if ( C[i]['r'] != C[k]['r'] ) T[i]++;
      if ( C[i]['o'] != C[k]['o'] ) T[i]++;
      if ( C[i]['y'] != C[k]['y'] ) T[i]++;
      if ( C[i]['g'] != C[k]['g'] ) T[i]++;
      if ( C[i]['b'] != C[k]['b'] ) T[i]++;
    }
  }
  
  int m = INT_MAX;
  int mi;
  for ( int i = 0; i < N; i++ ){
    if ( T[i] < m ){
      mi = i;
      m = T[i];
    }
  }

  cout << mi + 1 << endl;
}

main(){
  while ( read() ){
    work();
  }
}
// @end_of_source_code
