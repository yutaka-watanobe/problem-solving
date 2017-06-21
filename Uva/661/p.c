// @JUDGE_ID:  17051CA  661  C++
// @begin_of_source_code
/* Simulation */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#define MAX 22
#define OFF 0
#define ON 1

int C[MAX];
bool S[MAX];

int n, m, c;

int read(){
  cin >> n >> m >> c;
  if ( n == 0 && m == 0 && c == 0 ) return 0;
  for ( int i = 0; i < n; i++ ){
    cin >> C[i];
  }
  return 1;
}

void work(){
  fill ( S, S + MAX, 0 );
  
  int current = 0;
  int max_power = 0;
  int blown = false;
  int number;

  for ( int i = 0; i < m; i++ ){
    cin >> number; number--;
    if ( S[number] == OFF ){
      S[number] = ON;
      current += C[number];
    }else {
      S[number] = OFF;
      current -= C[number];
    }
    max_power = max( max_power, current );
    if ( current > c ) blown = true;
  }

  if ( blown ){
    cout << "Fuse was blown." << endl;
  }else{
    cout << "Fuse was not blown." << endl;
    cout << "Maximal power consumption was " << max_power << " amperes." << endl;
  }
}

main(){
  for (int i = 1;  read(); i++  ){
    cout << "Sequence " << i << endl;
    work();
    cout << endl;
  }
}
// @end_of_source_code
