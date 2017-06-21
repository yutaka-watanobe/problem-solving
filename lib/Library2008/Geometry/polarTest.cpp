#include<iostream>
#include<complex>
#include<cmath>

using namespace std;
#define EPS (1e-10)
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

typedef Point Vector;

// polar 
Point pol( double a, double r ){
    return Point(cos(r)*a, sin(r)*a);
}

main(){
  complex<double> p;

  double d, r;
  cin >>d >> r;
  p = polar(d,r);
  cout << p.real() << " "  << p.imag() << endl;

  Point c = pol(d, r);
  cout << c.x << " " << c.y << endl;
}
