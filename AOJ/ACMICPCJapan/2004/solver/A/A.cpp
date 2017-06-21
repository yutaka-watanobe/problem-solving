#include<iostream>
#include<cmath>
#define LIMIT 50000
using namespace std;
int a, b , d, mx, my;

void update( int x, int y, int &mx, int &my ){
    if ( y < 0 ) return;
    if ( x + y == mx + my && a*x + b*y < a*mx + b*my ){
	mx = x; my = y;
    } else if ( x + y < mx + my ){
	mx = x; my = y;
    }
}

main(){
    while( cin >> a >> b >> d, (a || b || d) ){
	mx = my = LIMIT;
	for ( int y, x = 0; x <= a + d; x++ ){
	    if ( (a*x - d)%b == 0 ){
		y = (a*x - d)/b; update( x, y, mx, my );
	    } 
	    if ( (a*x + d)%b == 0 ){
		y = (a*x + d)/b; update( x, y, mx, my );
	    }
	    if ( (d - a*x)%b == 0 ){
		y = (d - a*x)/b; update( x, y, mx, my );
	    }
	}
	cout << mx << " " << my << endl;
    }
}
