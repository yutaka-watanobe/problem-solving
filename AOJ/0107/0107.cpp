#include<iostream>
#include<algorithm>
using namespace std;

main(){
    int x, y, z;
    while( cin >> x >> y >> z && x && y && z ){
	int len = min( x*x + y*y, min(y*y + z*z, x*x + z*z) );

	int r, n; cin >> n;
	for ( int i = 0; i < n ;i++ ){
	    cin >> r;
	    r = (2*r)*(2*r);
	    if ( len < r ) cout << "OK" << endl;
	    else cout << "NA" << endl;
	}
    }
}
