// @JUDGE_ID:  17051CA  467  C++
// @begin_of_source_code
/* Simulation  Traffic Lights */
/* 1.7 sec ---> Use Array not Vector !! */
/* Is it number theory ?? */

#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#define BLUE 0
#define YELLOW 1
#define RED 2

void split( vector<string> &d, const string &s, char c = ' '){
  string t = "";
  
  for ( int i = 0; i < s.size(); i++ ){
    if ( s[i] == c ){
      if ( t != "" ) { d.push_back(t); t = ""; }
    }
    else  t += s[i];
  }
  if ( t.size() ) d.push_back(t);
}

int S[10];

int N;

int read(){

  string line;
  vector<string> com;

  getline( cin, line );
  if ( cin.eof() ) return 0;

  split( com, line );

  N = com.size();

  for ( int i = 0; i < N; i++ ){
    S[i] =  atoi( com[i].c_str() ) ;
  }
  return 1;
}

void start(){

  int counter[10];
  int signal[10];

  bool orange = false;

  fill ( counter, counter + N, 0 );
  fill ( signal, signal + N, BLUE );
  
  int t;

  int cnt = 0;
  
  for ( t = 0; t < 3601; t++ ){
    int sum = 0;
    for ( int j = 0; j < N; j++ ){
      counter[j]++;
      sum += signal[j];
      if( signal[j] == BLUE ){
	if ( counter[j] == S[j] - 5){
	  signal[j] = YELLOW;
	  counter[j] = 0;
	}
      }else if ( signal[j] == YELLOW ){
	orange = true;
	if ( counter[j] == 5 ){
	  signal[j] = RED;
	  counter[j] = 0;
	}
      }else if ( signal[j] == RED ){
	if ( counter[j] == S[j] ){
	  signal[j] = BLUE;
	  counter[j] = 0;
	}
      }
    }
    if ( sum == 0 && orange ) break;

  }

  if ( t > 3600 ) {
    cout << " is unable to synch after one hour." << endl;
    return;
  }

  int m, s;
  
  m = t / 60;
  s = t % 60;

  cout << " synchs again at " << m << " minute(s) and " << s << " second(s)";
  cout << " after all turning green." << endl;

}

void work(){
  start();
}

main(){
  for ( int i = 1; read(); i++ ){
    cout << "Set " << i ;
    work();
  }
}
// @end_of_source_code
