#include<iostream>
#include<complex>
#include<cstdio>
using namespace std;
typedef complex<double> Point;
typedef complex<double> Vector;

#define EPS 0.00001

Point A, B, C;

void getR(double alpha, double beta, double l, double r, double R, double &ans, bool &suc){
    double a, b, c;
    a = 1.0/((tan(beta)*tan(beta)));
    b = 2*r/(tan(alpha)*tan(beta)) - 2*l/tan(beta) - 4*r;
    c = l*l - 2*r*l/tan(alpha) + r*r/(tan(alpha)*tan(alpha));
    double rr1 = (-b - sqrt(b*b-4*a*c))/(2*a);
    double rr2 = (-b + sqrt(b*b-4*a*c))/(2*a);
    suc = false;
    if ( 0 <= rr1 && rr1 <= R ) { ans = rr1; suc = true;}
    if ( 0 <= rr2 && rr2 <= R ) { ans = rr2; suc = true;}
}

void compute(){
    double a = abs(B - C), b = abs(A-C), c = abs(A-B), r1, r2, r3;
    double s = (a + b + c)/2.0;
    double R = sqrt(s*(s-a)*(s-b)*(s-c))/s;
    double X = acos((c*c + b*b - a*a)/(2*c*b));
    double Y = acos((c*c + a*a - b*b)/(2*c*a));
    double Z = acos((a*a + b*b - c*c)/(2*a*b));
    double l = 0, r = 2*R;
    bool suc1, suc2;
    while(1){
	r1 = (l + r)/2.0;
	getR(X/2, Y/2, c, r1, R, r2, suc1);
	getR(X/2, Z/2, b, r1, R, r3, suc2);
	Vector v1 = A - B;
	Vector v2 = A - C;
	v1 = polar(r2/sin(Y/2), arg(v1) - Y/2) + B; 
	v2 = polar(r3/sin(Z/2), arg(v2) + Z/2) + C; 
	double d = abs(v1 - v2);
	if ( fabs(d - (r2+r3)) < EPS ) break;
	if ( d < r2+r3 || !suc1 || !suc2) l = r1;
	else r = r1;
    }
    
    printf("%.5lf %.5lf %.5lf\n", r1, r2, r3);
}

main(){
    while(1){
	cin >> A.real() >> A.imag();
	cin >> B.real() >> B.imag();
	cin >> C.real() >> C.imag();
	if ( A.real() == 0 && A.imag() == 0 && 
	     B.real() == 0 && B.imag() == 0 && 
	     C.real() == 0 && C.imag() == 0 ) break;
	compute();
    }
}
