#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
static const double PI = acos(-1);

double getArea( double c, double A, double B ){
    return c*c*sin(A)*sin(B)/(2*sin(A+B));
}

void compute(set<double> angle ){
    vector<double> v;
    for ( set<double>::iterator it = angle.begin(); it != angle.end(); it++ ){
	v.push_back(*it);
    }
    double r = 0.5/cos(30*PI/180);
    int n = angle.size();
    double d = (v[1] - v[0])/2;
    double area = 2*getArea(r, d*PI/180, 30*PI/180);
    printf("%.8lf\n", area*n);
}

void insertP( set<double> &p, double a ){
    if ( a >= 360.0 ) p.insert(a - 360.0);
    else p.insert(a);
}

main(){
    int n;
    while( cin >> n && n ){
	set<double> p;
	for ( int i = 0; i < 3; i++ ) p.insert(i*120.0);
	double cur = 0.0;
	for ( int t = 1; t < n; t++ ){
	    cur += 360.0/n;
	    for ( int i = 0; i < 3; i++ ) insertP(p, cur+i*120.0);
	}
	compute(p);
    }
}
