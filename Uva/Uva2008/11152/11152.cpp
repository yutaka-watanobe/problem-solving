#include<iostream>
#include<cmath>
using namespace std;

main(){
    double a, b, c, s, S, r, R, A;
    double roses, violets, sunflowers;
    static const double PI = acos(-1);

    while( cin >> a >> b >> c ){
	s = (a + b + c)/2;
	S = sqrt(s*(s-a)*(s-b)*(s-c));
	r = S/s;
	A = acos((b*b+c*c-a*a)/(2*b*c));
	R = (a/sin(A))/2;
	roses = PI*r*r;
	violets = S - roses;
	sunflowers = PI*R*R - S;

	printf("%.4lf %.4lf %.4lf\n", sunflowers, violets, roses);
    }
    
}
