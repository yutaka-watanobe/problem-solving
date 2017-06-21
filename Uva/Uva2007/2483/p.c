// @JUDGE_ID:  17051CA  2483  C++
// @begin_of_source_code
/* Bit Set */
/* use cin.unget() for input */
#include<stdio.h>
#include<iostream>
#include<bitset>
#include<vector>
#include<string>

bool isend;
int adollar, bdollar;
vector<int> T;

long long compute( int x ){
  bitset<32> bit;
  bit = x;
  
  bool start = false;
  long long cost = 0;

  for ( int i = 31; i >= 0; i-- ){
    if ( bit[i] ){
      cost += bdollar;
      start = true;
    } else {
      if ( start ) cost += adollar;
    }
  }

  return cost;
}

void work(){
  for ( int i = 0; i < T.size(); i++ ){
    cout << compute( T[i] ) << endl;
  }
}

void read(){
  string line;

  cin >> line;
  cin >> adollar >> bdollar;
  T.clear();
  while ( 1 ){
    /* 一文字列読んでみる */
    cin >> line;

    if ( line == "#" ) {
      isend = true;
      return ;
    }
    if ( line == "COST" ){
      cin.unget();
      return;
    }
    T.push_back( atoi( line.c_str() ) );
  }
}

int main(){
  isend = false;
  for ( int i = 1; !isend; i++ ){
    cout << "Set " << i << endl;
    read();
    work();
  }
  return 0;
}
// @end_of_source_code
