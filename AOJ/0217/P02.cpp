#include<iostream>
#include<cassert>
using namespace std;

main(){
    int n, p,maxp, maxv, d1, d2;
    while(1){
	cin >> n;
	if ( n == 0 ) break;
	assert( 1 <= n && n <= 10000 );
	maxv = -1;
	for ( int i = 0; i < n; i++ ){
	    cin >> p >> d1 >> d2;
	    assert(1 <= p && p <= 10000 );
	    assert(0 <= d1 && 1 <= 5000 );
	    assert(0 <= d2 && 2 <= 5000 );
	    assert( maxv != d1 + d2 );
	    if ( maxv < d1 + d2 ){
		maxp = p;
		maxv = d1 + d2;
	    }
	}
	cout << maxp << " " << maxv << endl;

    }
}
