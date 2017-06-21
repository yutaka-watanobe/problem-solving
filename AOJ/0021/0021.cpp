#include<iostream>
#include<cfloat>
#include<cmath>

using namespace std;

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS )

class Point{
    public:
    double x, y;
    
    Point ( double x = 0, double y = 0): x(x), y(y){}
    
    Point operator + ( Point p ){ return Point(x + p.x, y + p.y); }
    Point operator - ( Point p ){ return Point(x - p.x, y - p.y); }

};

typedef Point Vector;

double cross( Vector a, Vector b ){ return a.x*b.y - a.y*b.x; }

bool isParallel( Vector a, Vector b ){
    return equals( cross(a, b), 0.0 );
}

bool isParallel( Point a1, Point a2, Point b1, Point b2){
    return isParallel( a1 - a2, b1 - b2 );
}

int main(){
    int n; cin >> n;
    double x1, y1, x2, y2, x3, y3, x4, y4;

    for ( int i = 0; i < n; i++ ){
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	if ( isParallel(Point(x1, y1), Point(x2, y2), 
			Point(x3, y3), Point(x4, y4) ) ) cout << "YES" << endl;
	else cout << "NO" << endl;
    }
    return 0;
}
