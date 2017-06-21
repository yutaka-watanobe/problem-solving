#include<iostream>
using namespace std;

bool isLeapYear(int y){

    if ( y % 4 == 0 ){
	if ( y % 100 == 0 ){
	    if ( y % 400 == 0 ) return true;
	    else return false;
	} else {
	    return true;
	}
    } else {
	return false;
    }
    /*
    if ( y % 400 == 0 ) return true;
    if ( y % 100 == 0 ) return false;
    if ( y % 4 == 0 ) return true;
    return false;
    */
    /*
    if ( y % 4 == 0 ){
	if ( y % 100 == 0 && y % 400 != 0 ) return false;
	return true;
    }
    return false;
    */
}

int getDayFromYear( int  y ){
    int d = 0;
    for ( int i = 0; i < y; i++ ){
	if ( isLeapYear(i) ) d += 366;
	else d += 365;
    }
    return d;
}


// blablablablablablablabla
int getDayFromMonth( int y, int m ){
    int d = 0;
    static int t[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    static int tl[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for ( int i = 0; i < m; i++ ){
	if ( isLeapYear(y) ) d += tl[i];
	else d += t[i];
    }
    return d;
}

int main(){
    int y1, m1, d1, y2, m2, d2;
    int day1, day2;

    while(1){
	cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
	if ( y1 < 0 ) break;
	day1 = getDayFromYear(y1) + getDayFromMonth(y1, m1) + d1;
	day2 = getDayFromYear(y2) + getDayFromMonth(y2, m2) + d2;
	cout << day2 - day1 << endl;
    }







    return 0;
}
