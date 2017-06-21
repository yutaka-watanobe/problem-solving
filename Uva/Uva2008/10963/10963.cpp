#include<iostream>
#include<cassert>
using namespace std;

main(){
    int tcase;  cin >> tcase;
    int n, y2, y1, diff;
    bool valid;
    for ( int i = 0; i < tcase; i++ ){
	if ( i ) cout << endl;
	cin >> n;
	assert( n );
	cin >> y2 >> y1;
	diff = y2 - y1;
	valid = true;
	for ( int i = 1; i < n; i++ ){
	    cin >> y2 >> y1;
	    if ( diff != y2 - y1 ) valid = false;
	}

	cout << ((valid) ? "yes" : "no") << endl;
    }
}
