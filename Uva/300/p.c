// @JUDGE_ID:  17051CA  300  C++
// @begin_of_source_code
/* Simulation - Calculation - Calendar */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>

map<string, int> Haab;
vector<pair<int, string> > Tzolkin;

void init(){
  Haab["pop"] = 1;
  Haab["no"] = 2;
  Haab["zip"] = 3;
  Haab["zotz"] = 4;
  Haab["tzec"] = 5;
  Haab["xul"] = 6;
  Haab["yoxkin"] = 7;
  Haab["mol"] = 8;
  Haab["chen"] = 9;
  Haab["yax"] = 10;
  Haab["zac"] = 11;
  Haab["ceh"] = 12;
  Haab["mac"] = 13;
  Haab["kankin"] = 14;
  Haab["muan"] = 15;
  Haab["pax"] = 16;
  Haab["koyab"] = 17;
  Haab["cumhu"] = 18;
  Haab["uayet"] = 19;

  Tzolkin.resize( 260 );
  string table[20] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

  int day = 1;
  int index = 0;
  for ( int i = 0; i < 260; i++ ){
    Tzolkin[i] = pair<int, string>(day, table[index]);
    day++; index++;
    if ( day > 13 ) day = 1;
    if ( index > 19 ) index = 0;
  }

}

void convert( int total ){
  int year;
  int day;
  year = total / 260;
  day = total % 260;

  cout << Tzolkin[day].first << " " << Tzolkin[day].second << " " << year << endl;
}

void work(){
  int day, year;
  string month;
  char ch;
  cin >> day >> ch >> month >> year;

  int total;

  total = 0;

  total += year*365 + (Haab[month]-1)*20 + day;

  convert( total );

}

main(){
  int t;
  cin >> t;
  init();
  cout << t << endl;
  for ( int i = 0; i < t; i++ ){
    work();
  }
}
// @end_of_source_code
