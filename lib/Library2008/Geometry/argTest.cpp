#include<iostream>
#include<complex>
#include<cmath>
using namespace std;

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS ) // deq
#define dle(a, b) (equals(a, b) || a < b )

class Point{
    public:
    double x, y;
    
    Point ( double x = 0, double y = 0): x(x), y(y){}
    
    Point operator + ( Point p ){ return Point(x + p.x, y + p.y); }
    Point operator - ( Point p ){ return Point(x - p.x, y - p.y); }
    Point operator * ( double a ){ return Point(x*a, y*a); }
    Point operator / ( double a ){ return Point(x/a, y/a); }

    double abs() { return sqrt(norm());}
    double norm() { return x*x + y*y; }

    bool operator < ( const Point &p ) const {
	return x != p.x ? x < p.x : y < p.y;
    }

    bool operator == ( const Point &p ) const {
	return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;
    }
};

double getRealTheta(Point p1, Point p2){
    assert( !(p1 == p2 ) );
    double k;
    double dx, dy;
    
    dx = p2.x - p1.x;
    dy = p2.y - p1.y;
    
    if( dx == 0 ){
	if( dy > 0 ) return 90;
	else  return 180+90;
    }
    
    k = atan( dy/dx )/ acos(-1.0) * 180;
    if( dx < 0 ) k += 90 + 90;
    else if( dy < 0 ) k += 90 + 180 + 90;

    return k;
}

// 0 <= a <= 360
double getAngleTheta(Point p){
    double polar = atan2(p.y, p.x);
    double rad = (dle(0, polar))? polar : 2*acos(-1)+polar;
    return rad*180.0/acos(-1);
}
// 0 <= a <= 2pi
double getAngle(Point p){
    double polar = atan2(p.y, p.x);
    return (dle(0, polar))? polar : 2*acos(-1)+polar;
}


main(){
  double x, y;
  complex<double> c;

  while( cin >> x >> y ){
    c.real() = x;
    c.imag() = y;

    cout << arg(c) << endl;
    cout << atan2(y, x) << endl;
    cout << getRealTheta(Point(0, 0), Point(x, y)) << endl;
    cout << getAngleTheta(Point(x, y)) << endl;
  }
}


