#include<iostream>
#include<complex>
#include<cassert>
#include<cfloat>

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
    // assert(onSegment,,,);
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


// intersect Segment s1 and Segment s2 ?
bool isIntersect(Segment s1, Segment s2){
    return isIntersect(s1.source, s1.target, s2.source, s2.target);
}
// verified by 920
Point getCrossPoint(Segment s1, Segment s2){
    //    assert( isIntersect(s1, s2) );
    Vector base = s2.target - s2.source;
    double d1 = abs(cross(base, s1.source - s2.source));
    double d2 = abs(cross(base, s1.target - s2.source));
    double t = d1/(d1 + d2);
    return s1.source + (s1.target - s1.source)*t;
}

static const int MAX = 1000;
static const double LX = FLT_MIN;
static const double UX = FLT_MAX;

void simulate( int NP, Segment segments[MAX], Point source ){
    Point current = source;
    bool used[MAX];
    for ( int i = 0; i < NP; i++ ) used[i] = false;

    while(1){
	//cout << current.real() << " " << current.imag() << endl;
	

	int target;
	double mind = UX;
	for ( int i = 0; i < NP; i++ ){
	    if ( used[i] ) continue;
	    if ( !isIntersect(segments[i], Segment(current, Point(current.real(), 0.0))) ) continue;
	    Point crossPoint = getCrossPoint(segments[i], Segment(current, Point(current.real(), 0.0)));
	    double dist = getDistance(current, crossPoint);

	    if ( mind > dist && current.imag() > crossPoint.imag()){
		mind = dist;
		target = i;
	    }
	}

	if ( segments[target].source.imag() == 0.0 && segments[target].target.imag() == 0.0 ){
	    cout << (int)current.real() << endl;
	    return;
	}
	
	used[target] = true;
	if ( segments[target].source.imag() < segments[target].target.imag() ){
	    current = segments[target].source;
	} else {
	    current = segments[target].target;
	}
    }
}

void compute(){
    Segment segments[MAX];
    int NP,  NS;
    double x1, y1, x2, y2;
    cin >> NP;
    for ( int i = 0; i < NP; i++ ){
	cin >> x1 >> y1 >> x2 >> y2;
	segments[i] = Segment(Point(x1, y1), Point(x2, y2));
    }
    segments[NP++] = Segment(Point(LX, 0), Point(UX, 0));
    
    cin >> NS;
    for ( int i = 0; i < NS; i++ ){
	cin >> x1 >> y1;
	simulate(NP, segments, Point(x1, y1));
    }
}

int main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ) {
	if ( i ) cout << endl;
	compute();
    }
    return 0;
}
