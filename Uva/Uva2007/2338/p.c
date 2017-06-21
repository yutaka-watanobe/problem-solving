// @JUDGE_ID:  17051CA  2338  C++
// @begin_of_source_code
/* Parencoding */
#include<stdio.h>
#include<iostream>
#include<vector>

#define LEFT -1
#define RIGHT 1

vector<int> Parencode;
vector<int> Wsequence;

void init(){
  Parencode.clear();
  Wsequence.clear();
}

void read(){
  int n;
  cin >> n;
  
  int pre = 0;
  int p;
  for ( int i = 0; i < n ; i++ ){
    cin >> p;
    for ( int j = 0; j < p - pre; j++ ) Parencode.push_back( LEFT );
    Parencode.push_back( RIGHT );
    pre = p;
  }

}

void work(){

  for ( int i = 0; i < Parencode.size(); i++ ){
    if ( Parencode[i] == LEFT ) continue;

    int cnt = 0;
    int sum = RIGHT;
    int pos = i - 1;
    while ( 1 ){
      if ( sum == 0 ) break;
      sum += Parencode[pos];
      cnt++;
      pos--;
    }
    
    Wsequence.push_back( (cnt + 1) / 2 );
  }

  for ( int i = 0; i < Wsequence.size(); i++ ){
    cout << Wsequence[i] << " ";
  }
  cout << endl;
}

main(){
  int tcase;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    init();
    read();
    work();
  }
}
// @end_of_source_code
