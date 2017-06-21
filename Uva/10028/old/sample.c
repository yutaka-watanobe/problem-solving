#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include <cassert>

using namespace std;

#define REDUCTION 0
#define AWARD 1
#define OFFENSE 2

#define MERIT_UPPER 5

class Date {
public:

	int year, month, day;

	Date( int y, int m, int d ) : year(y), month(m), day(d) {}
	Date() {}

	bool operator < ( const Date &d ) const {
		if ( year < d.year ) return true;
		if ( year > d.year ) return false;
		if ( month < d.month ) return true;
		if ( month > d.month ) return false;
		if ( day < d.day ) return true;
		return false;
	}

	bool operator > ( const Date &d ) const {
		if ( year > d.year ) return true;
		if ( year < d.year ) return false;
		if ( month > d.month ) return true;
		if ( month < d.month ) return false;
		if ( day > d.day ) return true;
		return false;
	}

	bool operator == ( const Date &d ) const {
		if ( year != d.year ) return false;
		if ( month != d.month ) return false;
		if ( day != d.day ) return false;
		return true;
	}

	bool operator != ( const Date &d ) const {
		if ( year != d.year ) return true;
		if ( month != d.month ) return true;
		if ( day != d.day ) return true;
		return false;
	}

};


class Event {
public:

	Date date;

	int type, point;

	Event( Date d, int pt, int tp ) : date(d), type(tp), point(pt) {}
	Event() {}

	bool operator < ( const Event &e ) const {
		if ( date < e.date ) return true;
		if ( date > e.date ) return false;

		// reduction < award < offense ¤Î½çÈÖ¤ÇÍ¥Àè.
		return (type < e.type);
	}

};


class TDemeritPoints {
public:

	multiset<Event> events;

	void input() {
		string line;
		int date, point;

		events.clear();

		getline(cin, line);
		sscanf(line.c_str(), "%d", &date);
		events.insert(createEvent(date, 0));

		while ( getline(cin, line) && !line.empty() ) {
			sscanf(line.c_str(), "%d %d", &date, &point);
			events.insert(createEvent(date, point));
		}
	}

	Event createEvent( int date, int pt ) {
		return Event(Date(date / 10000, date / 100 % 100, date % 100), pt, OFFENSE);
	}

	Event createFutureEvent( Date date, int tp, int afterYear ) {
		return Event(Date(date.year+afterYear, date.month, date.day), 0, tp);
	}

	void work() {
		int nmerit = 0;
		int ndemerit = 0;
		
		while ( !events.empty() ) {
			const Event curr = *events.begin(); events.erase(events.begin());

			switch ( curr.type ) {
			case REDUCTION:
				assert(nmerit == 0);
				if ( ndemerit <= 2 ) ndemerit = 0;
				else ndemerit /= 2;
				break;
			case AWARD:
				assert(ndemerit == 0);
				assert(nmerit < MERIT_UPPER);
				nmerit++;
				break;
			case OFFENSE:
				ndemerit += curr.point;
				cancelAwardReduction();
				break;
			default:
				assert(false);
			}

			adjustPoint(nmerit, ndemerit);

			if ( ndemerit != 0 )
				events.insert(createFutureEvent(curr.date, REDUCTION, 1));
			else if  (nmerit < MERIT_UPPER)
				events.insert(createFutureEvent(curr.date, AWARD, 2));

			printState(curr.date, nmerit, ndemerit);
		}
	}

	void cancelAwardReduction() {
		multiset<Event>::iterator p;

		while ( true ) {
			for ( p = events.begin(); p != events.end(); p++ )
				if ( p->type == AWARD || p->type == REDUCTION )
					break;

			if ( p == events.end() ) break;
			events.erase(p);
		}
	}

	void printState( const Date &date, int nmerit, int ndemerit ) {
		printf("%04d-%02d-%02d ", date.year, date.month, date.day);

		if ( nmerit > 0 )
			printf("%d merit point(s).\n", nmerit);
		else if ( ndemerit > 0 )
			printf("%d demerit point(s).\n", ndemerit);
		else
			printf("No merit or demerit points.\n");
	}

	void adjustPoint( int &nmerit, int &ndemerit ) {
		if ( ndemerit <= 2*nmerit )
			nmerit -= ndemerit/2, ndemerit = 0;
		else
			ndemerit -= 2*nmerit, nmerit = 0;
	}

};

int main() {
	TDemeritPoints TDP;
	int nrecord;
	string line;

	cin >> nrecord;
	getline(cin, line), getline(cin, line);

	for ( int i = 0; i < nrecord; i++ ) {
		TDP.input();

		if ( i > 0 ) cout << endl;
		TDP.work();
	}

	return 0;
}
