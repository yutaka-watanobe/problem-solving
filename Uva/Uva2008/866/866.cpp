#include<stdio.h>
#include<complex>
#include<cassert>

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
// verified by 920, 833
bool isIntersect(Segment s1, Segment s2){
    return isIntersect(s1.source, s1.target, s2.source, s2.target);
}
// verified by 920, 833
Point getCrossPoint(Segment s1, Segment s2){
    assert( isIntersect(s1, s2) );
    Vector base = s2.target - s2.source;
    double d1 = abs(cross(base, s1.source - s2.source));
    double d2 = abs(cross(base, s1.target - s2.source));
    double t = d1/(d1 + d2);
    return s1.source + (s1.target - s1.source)*t;
}

static const int MAX = 100;

void compute(){
    Segment segments[MAX];
    int n; scanf("%d", &n);
    double x1, y1, x2, y2;
    for ( int i = 0; i < n; i++ ){
	scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
	segments[i] = Segment(Point(x1, y1), Point(x2, y2));
    }

    int nintersect = n;
    for ( int i = 0; i < n-1; i++ ){
	for ( int j = i+1; j < n; j++ ){
	    if ( isIntersect(segments[i], segments[j]) ) nintersect+=2;
	}
    }
    printf("%d\n", nintersect);
}

int main(){
    int tcase; scanf("%d", &tcase);
    for ( int i = 0; i < tcase; i++ ){
	if (i) printf("\n");
	compute();
    }
}
