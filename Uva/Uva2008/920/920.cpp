#include<iostream>
#include<stdio.h>
#include<complex>
#include<cassert>
#include<algorithm>

using namespace std;

#define EPS (1e-10)
#define equals(a, b) (abs((a) - (b)) < EPS )

typedef complex<double> Point;
typedef complex<double> Vector;

namespace std {
    bool operator < (const Point &a, const Point &b) {
	return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
    }
}

class Segment{
    public:
    Point source, target;
    Segment(Point s = Point(), Point t = Point()): source(s), target(t){}
};

double getDistance(Vector a, Vector b){
    return abs(a - b); 
}

// dot product
double dot(Vector a, Vector b){
    return real(conj(a)*b);
}

// cross product
double cross(Vector a, Vector b){
    return imag(conj(a)*b);
}

// intersect Segment p1-p2 and Segment p3-p4 ?
static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

int ccw( Point p0, Point p1, Point p2 ){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if ( cross(a, b) > 0 ) return COUNTER_CLOCKWISE;
    if ( cross(a, b) < 0 ) return CLOCKWISE;
    if ( dot(a, b) < 0 ) return ONLINE_BACK;
    if ( norm(a) < norm(b) ) return ONLINE_FRONT;
    return ON_SEGMENT;
}

// intersect Segment p1-p2 and Segment p3-p4 ?
bool isIntersect(Point p1, Point p2, Point p3, Point p4){
    return ( ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
	     ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0 );
    /*
    return ( cross(p2 - p1, p4 - p1) * cross(p2 - p1, p3 - p1) <= 0 &&
	     cross(p4 - p3, p1 - p3) * cross(p4 - p3, p2 - p3) <= 0 );
    */
}

/*
bool isIntersect(Point p1, Point p2, Point p3, Point p4){
    return ( cross(p2 - p1, p4 - p1) * cross(p2 - p1, p3 - p1) <= 0 &&
	     cross(p4 - p3, p1 - p3) * cross(p4 - p3, p2 - p3) <= 0 );
	     }*/

// intersect Segment s1 and Segment s2 ?
bool isIntersect(Segment s1, Segment s2){
    return isIntersect(s1.source, s1.target, s2.source, s2.target);
}

Point getCrossPoint(Segment s1, Segment s2){
    assert( isIntersect(s1, s2) );
    Vector base = s2.target - s2.source;
    double d1 = abs(cross(base, s1.source - s2.source));
    double d2 = abs(cross(base, s1.target - s2.source));
    double t = d1/(d1 + d2);
    return s1.source + (s1.target - s1.source)*t;
}

int n, npeak;
static const int MAX = 100;
static const double LX = -1.0;
static const double UX = 30001.0;

void compute(){
    cin >> n;
    double x, y;
    Point P[MAX+2];
    pair<Point, Point> peaks[MAX+2];

    for ( int i = 0; i < n; i++ ){
	cin >> x >> y; P[i] = Point(x, y);
    }
    P[n++] = Point(LX, 0.0);
    P[n++] = Point(UX, 0.0);
    sort( P, P + n );

    npeak = 0;
    for ( int i = 1; i <= n-2; i++ ){
	if ( P[i-1].imag() < P[i].imag() && P[i+1].imag() < P[i].imag() ){
	    peaks[npeak++] = make_pair(P[i], P[i+1]);
	}
    }
    peaks[npeak++] = make_pair(Point(UX, 0.0), Point());

    int p = 0;
    double total = 0.0;

    pair<Point, Point> source, target;
    int pt;
    while(1){
	source = peaks[p];
	double maxt = 0.0;
	for ( int i = p+1; i < npeak; i++ ){
	    if ( maxt < peaks[i].first.imag() ){
		maxt = peaks[i].first.imag();
		pt = i;
	    }
	}
	target = peaks[pt];

	if ( maxt < source.first.imag() ){
	    Point crossPoint = getCrossPoint( Segment(source.first, source.second),
					      Segment(Point(LX, maxt), Point(UX, maxt) ) );

	    total += getDistance(crossPoint, source.first);
	}

	p = pt;
	if ( maxt == 0.0 ) break;
    }
    
    printf("%.2lf\n", total);
}

int main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ) compute();
    return 0;
}
