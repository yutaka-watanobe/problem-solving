#include<iostream>
#include<string>

using namespace std;

class Date{
    public:
  int year, month, day;
  Date( int year=0, int month=0, int day=0 ): year(year), month(month), day(day){}

    bool operator < ( const Date &date ) const{
	if ( year < date.year ){
	    return true;
	} else if ( year == date.year ) {
	    if ( month < date.month ){
		return true;
	    } else if ( month == date.month ){
		return ( day < date.day );
	    } else return false;
	} else return false;
    }

    bool operator == ( const Date &date ) const{
	return ( year == date.year && month == date.month && day == date.day);
    }

    void print( string prefix, int jyear ){
      cout << prefix << " " << jyear << " " << month << " " << day << endl;
    }
};

static Date meijiLow = Date( 1868, 9, 8 );
static Date meijiUpper = Date( 1912, 7, 29 );
static Date taishoLow = Date( 1912, 7, 30 );
static Date taishoUpper = Date( 1926, 12, 24 );
static Date showaLow = Date(1926, 12, 25 );
static Date showaUpper = Date(1989, 1, 7);
static Date heiseiLow = Date( 1989, 1, 8 );


main(){
    int year, month , day; 
    while( cin >> year >> month >> day ){
      Date date = Date( year, month, day );
      if ( date < meijiLow ) {
	cout << "pre-meiji" << endl;
      } else if ( date == meijiLow || date == meijiUpper ||
		  meijiLow < date && date < meijiUpper ) {
	date.print("meiji", year - meijiLow.year + 1 );
      } else if ( date == taishoLow || date == taishoUpper ||
		  taishoLow < date && date < taishoUpper ){
	date.print("taisho", year - taishoLow.year + 1 );
      } else if ( date == showaLow || date == showaUpper ||
		  showaLow < date && date < showaUpper ){
	date.print("showa", year - showaLow.year + 1 );
      }else{
	date.print("heisei", year - heiseiLow.year + 1 );
      }
    }
}
