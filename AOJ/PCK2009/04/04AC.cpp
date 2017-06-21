#include<iostream>
#include<cmath>
using namespace std;
typedef long long llong;

llong power(llong x, int n){
    if ( n == 0 ) return 1;
    llong t = power(x, n/2);
    return (n%2 == 0) ? t*t : t*t*x;
}

llong getCount(llong x){
    llong d = 1, n = -1, cnt = 0;
    for( llong a = x; a; d *= 10, n++, a /= 10 ); 
    d /= 10;

    while(d){
	for ( int i = 0; i < x/d; i++ )
	    if ( i != 4 && i != 6 ) cnt += (1 << (3*n)); //power(8, n);
	if ( n == 0 && x/d != 4 && x/d != 6 ) cnt++;
	if ( x/d == 4 || x/d == 6 ) break;
	x %= d;
	d /= 10; n--;
    }
    return cnt;
}

llong rec(llong x, llong r){
    llong c = x - getCount(x) + 1;
    return (r == c) ? x : rec( x+c-r, c );
}

main(){
    llong n;
    while( cin >> n && n) cout << rec(n, 0) << endl;
}
