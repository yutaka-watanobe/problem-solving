#include<iostream>
#include<cstdio>

#include<cmath>
using namespace std;

void compute(){
    double d, v, u;
    cin >> d >> v >> u;
    if ( v >= u || u == 0 || v == 0 ){
	cout << "can't determine" << endl;
    } else {
	printf("%.3lf\n", fabs(d/sqrt(u*u-v*v) - d/u));
	
    }
}


main(){
    int tcase; cin >> tcase;
    for (int i = 1; i <= tcase; i++ ){
	cout << "Case " << i << ": ";
	compute();
    }
}
