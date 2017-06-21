#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;
static const double r = 6378.1;
static const double PI = acos(-1);

class Point{
    public:
    double x, y, z;
    Point(){}
    Point ( double theta, double phi ){
	theta = 90 - theta;
	theta *= (PI/180); // to degree
	phi *= (PI/180);
	x = r*sin(theta)*cos(phi);
	y = r*sin(theta)*sin(phi);
	z = r*cos(theta);
    }
};

double getDistance( Point p1, Point p2 ){
    return  (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)+(p1.z-p2.z)*(p1.z-p2.z);
}

int main(){
    double lat1, lat2, lon1, lon2;
    Point p1, p2;
    double theta, phi;
    while( cin >> lat1 >> lon1 >> lat2 >> lon2 ){
	if ( lat1 == 0 && lon1 == 0 && lat2 == 0 && lon2 == 0 ) break;
	
	p1 =  Point( lat1, lon1 );
	p2 =  Point( lat2, lon2 );

	double dist = getDistance( p1, p2 );
	
	printf("%.0lf\n", r*acos( 1 - dist/(2*r*r)));
    }

    return 0;
}
