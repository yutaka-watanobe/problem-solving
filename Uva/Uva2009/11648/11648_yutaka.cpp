#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

double getH( double a, double b, double c ){
    return (-b-sqrt(b*b-4*a*c))/(2*a);
}

main(){
    int tcase; cin >> tcase;
    double a, b, c, d, A, B, s, S, h, H, ds, t;

    for ( int i = 1; i <= tcase; i++ ){
	cin >> a >> b >> c >> d;

	s = (a - b + c + d)/2; S = sqrt(s*(s-a+b)*(s-c)*(s-d));
	H = 2*S/(a-b);

	A = acos((c*c+(a-b)*(a-b)-d*d)/(2*c*(a-b)));
	B = acos((d*d+(a-b)*(a-b)-c*c)/(2*d*(a-b)));

	ds = (a+b)*H/2; 
	t = ds/2;

	h = getH(c*cos(A) + d*cos(B), -2*a*H, 2*t*H);

	printf("Land #%d: %.12lf %.12lf\n", i, c*h/H, d*h/H);

    }
}
