#include<iostream>
#include<complex>
#include<cfloat>
#include<cassert>

using namespace std;

#define EPS (1e-10)
#define equals(a, b) (abs((a) - (b)) < EPS )

typedef complex<double> Point;
typedef complex<double> Vector;

// verified by 833
static const double LX = FLT_MIN;
static const double UX = FLT_MAX;

namespace std {
    bool operator < (const Point &a, const Point &b) {
	return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
    }

    bool operator == ( const Point &a, const Point &b ) {
	return abs(real(a)-real(b))< EPS && abs(imag(a)-imag(b)) < EPS;
    }
}

class Segment{
    public:
    Point source, target;
    Segment(Point s = Point(), Point t = Point()): source(s), target(t){}
};

double dot(Vector a, Vector b){
    return real(conj(a)*b);
}

double cross(Vector a, Vector b){
    return imag(conj(a)*b);
}

Point project( Segment s, Point p ){
    Vector base = s.target - s.source;
    double t = dot(p - s.source, base)/norm(base);
    return s.source + t*(base);
}

Point reflect( Segment s, Point p ){
    return p + 2.0*(project(s, p) - p);
}

// verified by uoa2062
bool isOnSegment( Point a, Point b, Point c){
    if ( a == c || b == c ) return true;
    return (abs(a-c) + abs(c-b) < abs(a-b) + EPS );
}

bool isOrthogonal( Vector a, Vector b ){
     return equals( dot(a, b), 0.0 );
}

bool isOrthogonal( Point a1, Point a2, Point b1, Point b2 ){
    return isOrthogonal( a1 - a2, b1 - b2 );
}

bool isOrthogonal( Segment s1, Segment s2 ){
    return equals( dot(s1.target - s1.source, s2.target - s2.source), 0.0 );
}

bool isParallel( Vector a, Vector b ){
    return equals( cross(a, b), 0.0 );
}

bool isParallel( Point a1, Point a2, Point b1, Point b2){
    return isParallel( a1 - a2, b1 - b2 );
}

bool isParallel( Segment s1, Segment s2 ){
    return equals( cross(s1.target - s1.source, s2.target - s2.source), 0.0 );
}

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

int ccw( Point p0, Point p1, Point p2 ){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if ( cross(a, b) > EPS ) return COUNTER_CLOCKWISE;
    if ( cross(a, b) < -EPS ) return CLOCKWISE;
    if ( dot(a, b) < -EPS ) return ONLINE_BACK;
    if ( norm(a) < norm(b) ) return ONLINE_FRONT;
    return ON_SEGMENT;
}

// intersect Segment p1-p2 and Segment p3-p4 ?
bool isIntersect(Point p1, Point p2, Point p3, Point p4){
    return ( ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
	     ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0 );
}

// intersect Segment s1 and Segment s2 ?
// verified by 920, 833, 866, uoa2062
bool isIntersect(Segment s1, Segment s2){
    return isIntersect(s1.source, s1.target, s2.source, s2.target);
}

// verified by 920, 833, uoa2062
Point getCrossPoint(Segment s1, Segment s2){
    assert( isIntersect(s1, s2) );
    Vector base = s2.target - s2.source;
    double d1 = abs(cross(base, s1.source - s2.source));
    double d2 = abs(cross(base, s1.target - s2.source));
    double t = d1/(d1 + d2);
    return s1.source + (s1.target - s1.source)*t;
}

double getDistance(Vector a, Vector b){
    return abs(a - b); 
}

double getDistance(Segment s, Point p){
    if ( dot(s.target - s.source, p - s.source) < 0.0 ) return abs(p - s.source);
    if ( dot(s.source - s.target, p - s.target) < 0.0 ) return abs(p - s.target);
    return abs(cross(s.target - s.source, p - s.source)/abs(s.target - s.source));
}

double getDistance(Segment s1, Segment s2){
    if ( isIntersect(s1, s2) ) return 0.0;
    return min( min(getDistance(s1, s2.source), getDistance(s1, s2.target)),
		min(getDistance(s2, s1.source), getDistance(s2, s1.target)));
}



main(){
    Point p1(1.0, 2.1), p2(3.3, 4.5), p3;



    //    cin >> p1.real() >> p1.imag();
    p3 = p1*p2;
    cout << p3.real() << " " << p3.imag()<< endl;
    cout << getDistance(p1, p2) << endl;
}
