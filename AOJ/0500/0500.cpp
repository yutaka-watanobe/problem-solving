#include<iostream>
using namespace std;
#define MAX 10000
main(){
    int a, b, n, sa, sb;
    while( cin >> n && n ){
	sa = sb = 0;
	for( int i = 0; i < n; i++ ){
	    cin >> a >> b;

	    if ( a > b ){
		sa += a+b;
	    } else if ( a < b ){
		sb += a+b;
	    } else {
		sa += a;
		sb += b;
	    }
	}
	cout << sa << " " << sb << endl;
    }
}
