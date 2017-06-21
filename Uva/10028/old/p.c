// @JUDGE_ID:  17051CA  10028  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

void split(vector<string> &d, const string &s, char c=' '){
  string t = "";
  for(int i=0; i<s.size(); i++){    
    if(s[i]==c){
      if(t!=""){ d.push_back(t); t = ""; }
    }
    else t += s[i];
  }
  if(t.size()) d.push_back(t);
}

void trim(string &s){
  int l, r;
  l = s.find_first_not_of(" \n\r");
  r = s.find_last_not_of(" \n\r");
  if(l==string::npos) s = "";
  else  s = s.substr(l, r-l+1);
}

class Date{
 public:
  int year, month, day;
  Date(){}
  Date( string line ){
    trim(line);
    year = atoi (line.substr( 0, 4 ).c_str() );
    month = atoi (line.substr( 4, 2 ).c_str() );
    day = atoi (line.substr( 6, 2 ).c_str() );
  }

  Date(int year, int month, int day): year(year), month(month), day(day){}
};

string line;
int merit_point, demerit_point;
Date current_date;
Date resent_date;

void read(){
  getline ( cin, line );
  current_date = Date( line );
  resent_date = current_date;
  merit_point = demerit_point = 0;
}

void printState(){
  int y, m, d;
  y = current_date.year;
  m = current_date.month;
  d = current_date.day;
  if ( y < 1000 ) cout << "0";
  if ( y < 100 ) cout << "0";
  if ( y < 10 ) cout << "0";
  cout << current_date.year << "-";
  if ( m < 10 ) cout << "0";
  cout << current_date.month << "-";
  if ( d < 10 ) cout << "0";
  cout << current_date.day << " ";

  if ( merit_point > 0 ) cout << merit_point << " merit point(s)." << endl;
  else if ( demerit_point > 0 ) cout << demerit_point << " demerit point(s)." << endl;
  else cout << "No merit or demerit points." << endl;
}

void addMerit(){
  if ( merit_point < 5 ){
    merit_point++;
    printState();
  }
}

void reduceDemerit(){
  if ( demerit_point > 0 ){
    demerit_point -= max( (demerit_point+1)/2, 2 );
    if ( demerit_point < 0 ) demerit_point = 0;
    printState();
  }
}

void work(){
  printState();
  Date date;
  int point;
  vector<string> offense;

  while ( 1 ){
    getline( cin, line );
    if ( line == "" || cin.eof() ) break;
    offense.clear();
    split( offense, line );
    date = Date( offense[0] );
    point = atoi(offense[1].c_str());

    /* bounus  */
    current_date = resent_date;
    int y = 0;
    for ( int i = resent_date.year + 1; i <= date.year; i++ ){
      current_date.year++;
      y++;
      /* add merit point */
      if ( y / 2 >= 1 && y % 2 == 0 && demerit_point == 0){
	if ( i == date.year ){
	  if ( resent_date.month < date.month){
	    addMerit();
	  }else if ( resent_date.month == date.month && resent_date.day <= date.day ){
	    addMerit();
	  }
	}else{
	  addMerit();
	}
      }
      /* reduce demerit point */
      if ( demerit_point ){
	reduceDemerit();
      }
    }

    demerit_point += point;
    current_date = date;

    if ( demerit_point > 2 * merit_point ){
      demerit_point -= 2*merit_point;
      merit_point = 0;
    }else if ( demerit_point <= 2 * merit_point ){
      merit_point -= demerit_point / 2;
      demerit_point = 0;
    }

    printState();
    resent_date = date;
  }


  /* bounus  */
  current_date = resent_date;
  int y = 0;
  while ( 1 ){
    current_date.year++;
    /* add merit point */
    if ( y / 2 >= 1 && y % 2 == 0 && demerit_point == 0){
      addMerit();
    }
    /* reduce demerit point */
    else{
      reduceDemerit();
    }
    y++;
    /* cout << y << " " << merit_point << " " << demerit_point << endl; */
    if ( merit_point >= 5 ) return;
  }

}

main(){
  int t;
  getline ( cin, line );
  t = atoi( line.c_str() );
  getline ( cin, line );
  for ( int i = 0; i < t; i++ ){
    if ( i ) cout << endl;
    read();
    work();
  }
}
// @end_of_source_code
