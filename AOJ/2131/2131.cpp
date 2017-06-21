#include<iostream>
#include<cmath>
using namespace std;

double PI = acos(-1);

void compute( double R ){
    for ( int d = 1;;d++){
	int l = 1, r = d*8;
	while(l < r){
	    int n = (l + r)/2;
	    double p = 1.0*n/d;
	    if ( fabs(PI-p) <= R ){
		cout << n << "/" << d << endl; return;
	    } else if ( p > PI ){
		r = n;
	    } else {
		l = n+1;
	    }
	}
    }
}

main(){
    double R;
    while(1){
	cin >> R;
	if ( R == 0 ) break;
	compute(R);
    }
}
