// @JUDGE_ID:  17051CA  518  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
typedef  long long ullong;

void split ( vector<string> &d, const string &s, char c=' ' ) {
  string t = "";
  d.clear();

  for ( int i = 0; i < s.size(); i++ ){    
    if ( s[i] == c ){
      if ( t != "" ){ d.push_back(t); t = ""; }
    }
    else t += s[i];
  }
  if ( t.size() ) d.push_back(t);
}

int month_table[13] = { -1, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

class Date{
 public:
  int year, month, day, hour, minute, second;
  /* À¾Îñ £° Ç¯ £° ·î £° Æü £° »þ´Ö £° Ê¬ £° ÉÃ ¤«¤é¤Î ¤½¤ì¤¾¤ì¤Î Time */
  ullong toYear;
  ullong toMonth;
  ullong toDay;
  ullong toHour;
  ullong toMinute;
  ullong toSecond;

  Date(){}
  Date( int year, int month, int day, int hour, int minute, int second ):
    year(year), month(month), day(day), hour(hour), minute(minute), second(second){
    
    toYear = (ullong)year;
    toMonth = 12 * year + month;

    bool leapYear = false;

    if ( year % 4 == 0 ){
      if ( year % 100 == 0 ){
	if ( year % 400 == 0 ) leapYear = true;
	else leapYear = false;
      } else {
	leapYear = true;
      }
    }

    ullong current_day;
    /* for year */
    current_day = (ullong)( ( year - 1) * 365) + ( year - 1)/4 - (year-1)/100 + (year-1)/400;
    /* for month */
    current_day += month_table[ month ];
    if ( leapYear && month > 2 ) current_day++;

    toDay = current_day + day;

    toHour = toDay * 24 + hour;
    toMinute = toHour * 60 + minute; 
    toSecond = toMinute * 60 + second;
  }


};

Date source, target;
ullong time_period;
ullong operand;
string period;

ullong getOvered(){
  if ( period == "year" ){
    if ( source.month == 1 && source.day == 1 && source.hour == 0 && source.minute == 0 && source.second == 0 ) return 0;
    else return 1;
  } else if ( period == "month" ){
    if ( source.day == 1 && source.hour == 0 && source.minute == 0 && source.second == 0 ) return 0;
    else return 1;
  } else if ( period == "day" ){
    if ( source.hour > 0 || source.minute > 0 || source.second > 0 ) return 1;
    else return 0;
  } else if ( period == "hour" ){
    if ( source.minute > 0 || source.second > 0 ) return 1;
    else return 0;
  } else if ( period == "minute" ){
    if ( source.second > 0 ) return 1;
    else return 0;
  }

  return 0;

}


void work(){
  
 /*  cout << source.year << " " << source.month << " " << source.day << " " << source.hour << " " << source.minute << " " << source.second << endl; */
/*   cout << target.year << " " << target.month << " " << target.day << " " << target.hour << " " << target.minute << " " << target.second << endl; */
/*   cout << source.toYear << " " << source.toMonth << " " << source.toDay << " " << source.toHour << " " << source.toMinute << " " << source.toSecond << endl; */
/*   cout << target.toYear << " " << target.toMonth << " " << target.toDay << " " << target.toHour << " " << target.toMinute << " " << target.toSecond << endl; */

  ullong length;

  if ( period == "second" ){
    length = target.toSecond - source.toSecond;
  } else if ( period == "minute" ){
    length = target.toMinute - source.toMinute;
  } else if ( period == "hour" ){
    length = target.toHour - source.toHour;
  } else if ( period == "day" ){
    length = target.toDay - source.toDay;
  } else if ( period == "month" ){
    length = target.toMonth - source.toMonth;
  } else if ( period == "year" ){
    length = target.toYear - source.toYear;
  }
  
  ullong over = getOvered();

  cout << length / operand - over << endl;

}


bool read(){
  string line;
  
  getline( cin, line );
  vector<string> sp;

  if ( line.size() == 0 || cin.eof() ) return false;
  
  split( sp, line );
  source = Date( atoi( sp[0].c_str() ),
		 atoi( sp[1].c_str() ),
		 atoi( sp[2].c_str() ),
		 atoi( sp[3].c_str() ),
		 atoi( sp[4].c_str() ),
		 atoi( sp[5].c_str() ) );
  getline( cin, line );
  split( sp, line );
  target = Date( atoi( sp[0].c_str() ),
		 atoi( sp[1].c_str() ),
		 atoi( sp[2].c_str() ),
		 atoi( sp[3].c_str() ),
		 atoi( sp[4].c_str() ),
		 atoi( sp[5].c_str() ) );
  getline( cin, line );
  split( sp, line );
  operand = atoi(sp[0].c_str() );
  period = sp[1];

  getline( cin, line ); /* empty line */
  return true;
}

main(){
  while ( read() ){
    work();
  }
}

// @end_of_source_code


