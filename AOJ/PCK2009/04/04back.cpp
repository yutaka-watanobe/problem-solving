#include<iostream>
#include<cmath>
using namespace std;
typedef long long llong;

llong getL(llong x){
    llong cnt = 0;
    for ( llong i = 0; i < x; i++ ){
	if ( i != 4 & i != 6 )  cnt++;
    }
    return cnt;
}

llong getP(llong x){
    llong p = 1;
    for ( llong i = 0; i < x; i++ ) p *= 8;
    return p;
}

llong getCount(llong x){
    llong d = 1;
    llong n = 0;
    for( llong a = x; a; d *= 10, n++, a /= 10 ); 
    d /= 10;
    n--;

    llong cnt = 0;
    while(d){
	llong l = x/d; 
	//cout << getL(l) << "-" << n << endl;
	//	cout << getL(l)*getP(n) << " + ";
	cnt += getL(l)*getP(n);
	
	if ( n == 0 ){
	    if ( l != 4 && l != 6 ) cnt++;
	}
	if ( x/d == 4 || x/d == 6 ) break;
	x %= d;
	d /= 10; n--;
    }
    //    cout << endl;
    return cnt;
}

void compute(llong n){
    llong c;
    llong x = n;
    llong r = 0;
    while(1){
	c = x - getCount(x)+1;
	if ( r == c ) break;
	x += (c-r);
	r = c;
    }

    cout << x << endl;
}

main(){
    llong n;
    while( cin >> n ){
	//cout << getCount(n) << endl;
	compute(n);
    }
}
