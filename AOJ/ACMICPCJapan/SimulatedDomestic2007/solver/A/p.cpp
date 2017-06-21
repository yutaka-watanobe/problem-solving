// Problem A: Space Coconut Crab
// @author yutaka
#include<iostream>
#include<algorithm>
using namespace std;

main(){
    int e; 
    while (1){
	cin >> e;
	if ( e == 0 ) break;
	int m = INT_MAX;
	for ( int z = 0; z*z*z <= e; z++ ){
	    for ( int y = 0; y*y + z*z*z <= e; y++ ){
		int x = e - y*y - z*z*z;
		m = min( m, x + y + z );
	    }
	}
	cout << m << endl;
    }
}
