// n(2a+n-1) == 2x ?
#include<iostream>
#include<cmath>

using namespace std;

main(){
    int x;
    while( cin >> x && x >= 0 ){
	int limit = (int)sqrt(2*x)+1 ;
	for ( int n = limit; n >= 1; n-- ){
	    if ( (2*x - n*n + n) % (2*n) != 0 ) continue;
	    int a =  (2*x - n*n + n) / (2*n);
	    if ( a < 1 || n*(2*a+n-1)!=2*x ) continue;
	    cout << x << " = " << a << " + ... + " << a + n - 1 << endl;
	    break;
	}
    }
}
