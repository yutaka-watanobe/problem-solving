// @JUDGE_ID:  17051CA  161  C++
// @begin_of_source_code
/* Simulation  Traffic Lights */
/* 1.2 sec */
/* Is it number theory ?? */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#define BLUE 0
#define YELLOW 1
#define RED 2

vector<int> S;

int read(){
  S.clear();
  int k;
  while ( 1 ) {
    cin >> k;
    if( k == 0 ) break;
    S.push_back( k );
  }

  if ( S.size() == 0 ) return 0;
  return 1;
}

void start(){

  vector<int> counter;
  vector<int> signal;

  bool orange = false;

  counter.resize( S.size(), 0 );
  signal.resize( S.size(), BLUE );
  
  int t;

  int cnt = 0;
  
  for ( t = 0; t < 18001; t++ ){
    int sum = 0;
    for ( int j = 0; j < S.size(); j++ ){
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

  if ( t > 18000 ) {
    cout << "Signals fail to synchronise in 5 hours" << endl;
    return;
  }

  int h, m, s;
  h = t / 3600;
  m = ( t - h*3600 ) / 60;
  s = ( t - h*3600 ) % 60;
  if(h<10) cout << "0";
  cout << h << ":";
  if(m<10) cout << "0";
  cout << m << ":"; 
  if(s<10) cout << "0";
  cout << s << endl;

}

void work(){
  start();
}

main(){
  while ( read() ){
    work();
  }
}
// @end_of_source_code
