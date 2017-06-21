#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

main(){
    double x, y, a, b, r, th;
    char ch;
    int tcase = 1;
    while ( cin >> a >> ch >> b ){
	th = atan(b/a);
	r = 100/(cos(th) + th);
	x = 2*r*cos(th);
	y = 2*r*sin(th);
	printf("Case %d: %.12lf %.12lf\n", tcase++, x, y);
    }
}
