// @JUDGE_ID:  17051CA  602  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<map>

map<int, string> M, D;

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int month_cnt[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

void init(){
  M[1] = "January";
  M[2] = "February";
  M[3] = "March";
  M[4] = "May";
  M[5] = "April";
  M[6] = "June";
  M[7] = "July";
  M[8] = "August";
  M[9] = "September";
  M[10] = "October";
  M[11] = "November";
  M[12] = "December";
  D[0] = "Sunday";
  D[1] = "Monday";
  D[2] = "Tuesday";
  D[3] = "Wednesday";
  D[4] = "Thursday";
  D[5] = "Friday";
  D[6] = "Saturday";
}

int m, d, y;

int read(){
  cin >> m >> d >> y;
  if ( m == 0 && d == 0 && y == 0 ) return 0;
  return 1;
}

void work(){
  int date;
  y--;
  long long total = y*365 + month_cnt[m] + d + y/4 - ( y/100 - y/400 );
  y++;

  if ( y%4 == 0 && !( y%100 == 0 && y%400 != 0)  ){
    if ( m > 2 ) total++;
  }

  date = total % 7;

  cout << D[date] << endl;
}

main(){
  init();
  while ( read () ){
    work();
  }
}
// @end_of_source_code
