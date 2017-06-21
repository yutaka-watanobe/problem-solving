#include<iostream>
#include<stdio.h>
#include<complex>
#include<cassert>
#include<cfloat>

using namespace std;

#define EPS (1e-10)
#define equals(a, b) (abs((a) - (b)) < EPS )

typedef complex<double> Point;
typedef complex<double> Vector;

// verified by 833

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
bool isIntersect(Point p1, Point p2, Point p3, Point p4){
    return ( cross(p2 - p1, p4 - p1) * cross(p2 - p1, p3 - p1) <= 0 &&
	     cross(p4 - p3, p1 - p3) * cross(p4 - p3, p2 - p3) <= 0 );
}

// intersect Segment s1 and Segment s2 ?
// verified by 920, 833, 866
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

static const int MAX = 1000;
static const double LX = FLT_MIN;
static const double UX = FLT_MAX;

double getRatio(int NL, Segment S[MAX], double R[MAX], double p1, double p2){
    double r = 1.0;
    for ( int i = 0; i < NL; i++ ){
	double left = min( S[i].source.real(), S[i].target.real());
	double right = max( S[i].source.real(), S[i].target.real());
	if ( left <= p1 && p1 <= right &&
	     left <= p2 && p2 <= right ) r *= R[i];
    }
    return r;
}

void compute(){
    int NL; scanf("%d", &NL);
    double x1, y1, x2, y2;
    Segment S[MAX];
    double R[MAX];
    int n = 0;
    double X[MAX*2+2];
    for ( int i = 0; i < NL; i++ ){
	scanf("%lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &R[i]);
	S[i] = Segment(Point(x1, y1), Point(x2, y2));
	X[n++] = x1;
	X[n++] = x2;
    }
    X[n++] = LX;
    X[n++] = UX;

    sort( X, X + n );

    printf("%d\n", n-1);
    for ( int i = 1; i < n; i++ ){
	double p1 = X[i-1];
	double p2 = X[i];
	if ( p1 == LX ) printf("-inf ");
	else printf("%.3lf ", p1);
	if ( p2 == UX ) printf("+inf %.3lf\n",getRatio(NL, S, R, p1, p2));
	else printf("%.3lf %.3lf\n", p2, getRatio(NL, S, R, p1, p2));
    }
}

int main(){
    int tcase; scanf("%d", &tcase);
    for ( int i = 0; i < tcase; i++ ) {
	if (i) cout << endl;
	compute();
    }
    return 0;
}
