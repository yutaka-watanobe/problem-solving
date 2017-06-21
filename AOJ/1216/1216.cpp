#include<iostream>
#include<cmath>
using namespace std;

class Point{
    public:
    double x, y, z;
    Point( double x = 0, double y = 0, double z = 0):x(x), y(y),z(z){}
};

double getDist( Point p1, Point p2 ){
    return sqrt( (p1.x-p2.x)*(p1.x-p2.x) +  (p1.y-p2.y)*(p1.y-p2.y) + (p1.z-p2.z)*(p1.z-p2.z));
}

bool eq( double a, double b ){
    return fabs(a-b) < 0.0000001;
}

void compute(){
    Point P[100];
    double QR, RP, PQ, x, y, z;
    cin >> QR >> RP >> PQ;
    int n; cin >> n;
    for ( int i = 0; i < n; i++ ){
	cin >> x >> y >> z;
	P[i] = Point(x, y, z);
    }

    bool finished = false;
    for ( int p = 0; p < n; p++ ){
	for ( int q = 0; q < n; q++ ){
	    for ( int r = 0; r < n; r++ ){
		if ( p == q || p == r || q == r ) continue;
		double rate = PQ/getDist(P[p], P[q]);
		if ( !eq(rate, RP/getDist(P[r], P[p]))) continue;
		if ( !eq(rate, QR/getDist(P[q], P[r]))) continue;
		if ( finished ) continue;
		c out << p+1 << " " << q+1 << " " << r+1 << endl;
		finished = true;
	    }
	}
    }

    
}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ) compute();
}
