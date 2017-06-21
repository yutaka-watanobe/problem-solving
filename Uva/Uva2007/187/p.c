// @JUDGE_ID:  17051CA  187  C++
// @begin_of_source_code
/* Simulation */
#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<stl.h>
#include<cmath>

class Record{
 public:
  string sequence, account;
  int value;

  Record(string sequence, string account, string name):
    sequence(sequence), account(account){
    value = atoi( name.c_str() );
  }

};

map<string, string> accounts;

void read(){
  string line;
  while ( 1 ) {
    getline( cin, line );
    while ( line.size() < 33 ) line += ' ';
    if ( line.substr(0, 3) == "000" ) break;
    accounts[ line.substr(0, 3) ] = line.substr( 3, 30 );
  }
}

void checkTransaction( vector<Record> T ){
  int balance, value, cent, sign;
  balance = 0;
  for ( int i = 0; i < T.size(); i++ ){
    balance += T[i].value;
  }

  if ( balance == 0 ) return;

  cout << "*** Transaction " << T[0].sequence << " is out of balance ***" << endl;
  for ( int i = 0; i < T.size(); i++ ){
    cout << T[i].account << " " << accounts[ T[i].account ];
    value = T[i].value;
    printf("%11.2f\n",value/100.0 );
  }

  cout << "999 Out of Balance                ";
  printf("%11.2f\n", fabs(balance/100.0) );
  cout << endl;
}

void work(){
  string line;
  vector<Record> T;

  getline( cin, line );
  T.push_back( Record( line.substr(0, 3), line.substr(3, 3), line.substr(6) ) );
  

  while ( 1 ){
    if ( line.substr(0, 3) == "000" ) return;
    getline( cin, line );

    if ( line.substr(0, 3) != T[ T.size()-1 ].sequence ){
      checkTransaction( T );
      T.clear();
      T.push_back( Record( line.substr(0, 3), line.substr(3, 3), line.substr(6) ) );
    }else{
      T.push_back( Record( line.substr(0, 3), line.substr(3, 3), line.substr(6) ) );
    }

  }

}

main(){
  read();
  work();
}
// @end_of_source_code
