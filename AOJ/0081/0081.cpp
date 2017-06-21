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
}

class Segment{
    public:
    Point source, target;
    Segment(Point s = Point(), Point t = Point()): source(s), target(t){}
};

double getDistance(Vector a, Vector b){
    return abs(a - b); 
}

bool eq(Point a, Point b){
    return abs(real(a)-real(b))< EPS && abs(imag(a)-imag(b)) < EPS;
}

// dot product
double dot(Vector a, Vector b){
    return real(conj(a)*b);
}

// cross product
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


int main(){
    double x1, y1, x2, y2, xq, yq;
    char ch;
    while( cin >> x1 >> ch >> y1 >> ch >> x2 >> ch >> y2 >> ch >> xq >>ch >>  yq ){
	Point p = reflect( Segment(Point(x1, y1), Point(x2, y2)), Point(xq, yq));
	printf("%.8lf %.8lf\n", p.real(), p.imag());
    }
    return 0;
}

