#include<iostream>
#include<cmath>
using namespace std;

main(){
    int n, i, ans;
    double minv, bmi, w, h;
    while( cin >> n && n ){
	minv = (1<<21);
	for ( int j = 0; j < n; j++ ){
	    cin >> i >> h >> w;
	    bmi = w/(h*h*0.0001);
	    if ( fabs(22-bmi) < minv ){
		minv = fabs(22-bmi);
		ans = i;
	    }
	}
	cout << ans << endl;
    }
}
